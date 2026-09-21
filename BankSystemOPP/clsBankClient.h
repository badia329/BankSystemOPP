#pragma once
#include<fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"

class clsBankClient : public clsPerson
{
private:
	enum enMode { EmtyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete = false;

	static clsBankClient _ConvertLineClientToObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);
		return stClientRecord;
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmtyMode, "", "", "", "", "", "", 0);
	}

	string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient, string UserName, string Seperator = "#//#")
	{

		string TransferLogRecord = "";

		TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
		TransferLogRecord += AccountNumber + Seperator;
		TransferLogRecord += DestinationClient.AccountNumber + Seperator;
		TransferLogRecord += to_string(Amount) + Seperator;
		TransferLogRecord += to_string(AccountBalance) + Seperator;
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		TransferLogRecord += UserName;

		return TransferLogRecord;
	}
	
	struct stTransferLogRecord;

	static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line , string Separtor = "#//#")
	{
		stTransferLogRecord TransferLog;
		vector<string> vTransferLog = clsString::Split(Line, Separtor);

		TransferLog.DateTime = vTransferLog[0];
		TransferLog.SourceAccountNumber = vTransferLog[1];
		TransferLog.DestinationAccountNumber = vTransferLog[2];
		TransferLog.SourceBalanceAfter = stof(vTransferLog[3]);
		TransferLog.Amount = stof(vTransferLog[4]);
		TransferLog.DestinationBalanceAfter = stof(vTransferLog[5]);
		TransferLog.UserName = vTransferLog[6];

		return TransferLog;
	}

	void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
	{
		string stDataLien = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

		fstream Myfile;

		Myfile.open("TransferLog.txt", ios::out | ios::app);

		if (Myfile.is_open())
		{
			Myfile << stDataLien << endl;
			Myfile.close();
		}

	}


	static vector <clsBankClient> _LoadClientsDateFromFile()
	{
		vector <clsBankClient> vClients;
		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineClientToObject(Line);
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;
	}

	static void _SaveCleintDataToFile(vector <clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{
			for (const clsBankClient &Client : vClients)
			{
				if (Client._MarkedForDelete == false)
				{
					DataLine = _ConvertClientObjectToLine(Client);
					MyFile << DataLine << endl;
				}
				
			}
		}
		MyFile.close();

	}

	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDateFromFile();

		for (clsBankClient& Client : _vClients)
		{
			if (Client.GetAccountNumber() == AccountNumber)
			{
				Client = *this;
			}
		}
		_SaveCleintDataToFile(_vClients);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}

public:

	struct stTransferLogRecord
	{
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		float Amount;
		float SourceBalanceAfter;
		float DestinationBalanceAfter;
		string UserName;
	};

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNubmer, string PinCode, float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNubmer;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmtyMode);
	}

	// Property Get
	string GetAccountNumber()
	{
		return _AccountNumber;
	}
	__declspec(property(get = GetAccountNumber)) string AccountNumber;

	// Property Set
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	
	// Property Get
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	// Property Set 
	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	
	// Property Get
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineClientToObject(Line);
				if (Client.AccountNumber == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineClientToObject(Line);
				if (Client.AccountNumber == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		return (!Client1.IsEmpty());
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNubmerExists = 3};

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmtyMode:
		{
			return enSaveResults::svFaildEmptyObject;
		}

		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
		}

		case enMode::AddNewMode:
		{
			if (clsBankClient::IsClientExist(AccountNumber))
			{
				return enSaveResults::svFaildAccountNubmerExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
		}

		}
	}
	
	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector <clsBankClient> vClientsData;
		vClientsData = _LoadClientsDateFromFile();

		for (clsBankClient& Client : vClientsData)
		{
			if (Client.GetAccountNumber() == _AccountNumber)
			{
				Client._MarkedForDelete = true;
				break;
			}
		}

		_SaveCleintDataToFile(vClientsData);
		*this = _GetEmptyClientObject();

		return true;
	}
	
	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientsDateFromFile();
	}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		_AccountBalance -= Amount;
		Save();
	}

	static double GetTotalBalances()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		double TotalBalances = 0;

		for (const clsBankClient &Client : vClients)
		{
			TotalBalances += Client._AccountBalance;
		}
		return TotalBalances;
	}

	bool Transfer(float Amount, clsBankClient& DestinationClient, string UserName)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}

		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestinationClient, UserName);
		return true;
	}


	static vector<stTransferLogRecord> GetTransfersLogList()
	{
		vector <stTransferLogRecord> vTransferLog;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);

		if (MyFile.is_open())
		{
			string DataLine;

			stTransferLogRecord  TransferLogRecord;

			while (getline(MyFile, DataLine))
			{
				TransferLogRecord = _ConvertTransferLogLineToRecord(DataLine);
				vTransferLog.push_back(TransferLogRecord);
			}
		}
		return vTransferLog;
	}

};
