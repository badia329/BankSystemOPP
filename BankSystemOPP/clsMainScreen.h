#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsMangeUsers.h"
#include "Global.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyScreen.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
private:
	enum enMainMenueOptions { eListClients = 1, eAddNewClient = 2, eDeleteCleint = 3, eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6, eMangeUsers = 7, eLoginRegister = 8, eShowCurrencyMenue = 9, eExit = 10 };

	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
		short choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between 1 to 10? ");
		return choice;
	}

	static void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\t\Press any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenue();
	}

	static void _ShowAllClientsScreen()
	{
		clsClientListScreen::ShowClientClist();
	}

	static void _ShowAddNewClientsScreen()
	{
		clsAddNewClientScreen::AddNewClient();
	}

	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::DeleteClient();
	}

	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::UpdateClient();
	}

	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenue()
	{
		clsTransactionsScree::ShowTransactionsMenue();
	}

	static void _ShowManageUsersMenue()
	{
		clsMangeUsers::ShowMangeUsersMenueScreen();
	}

	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyMenue()
	{
		clsCurrencyScreen::_ShowCurrencyMenuScreen();
	}

	static void _LogOut()
	{
		CurrentUser = clsUser::Find("", "");
	}

	static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
	{
		system("cls");

		switch (MainMenueOption)
		{
		case enMainMenueOptions::eListClients:
		{
			_ShowAllClientsScreen();
			_GoBackToMainMenue();
			break;
		}

		case enMainMenueOptions::eAddNewClient:
		{
			_ShowAddNewClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		
		case enMainMenueOptions::eDeleteCleint:
		{
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;
		}
		
		case enMainMenueOptions::eUpdateClient:
		{
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;
		}

		case enMainMenueOptions::eFindClient:
		{
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		}

		case enMainMenueOptions::eMangeUsers:
		{
			_ShowManageUsersMenue();
			_GoBackToMainMenue();
			break;
		}

		case enMainMenueOptions::eShowTransactionsMenue:
		{
			_ShowTransactionsMenue();
			_GoBackToMainMenue();
			break;
		}

		case enMainMenueOptions::eLoginRegister:
		{
			_ShowLoginRegisterScreen();
			_GoBackToMainMenue();
			break;
		}

		case enMainMenueOptions::eShowCurrencyMenue:
			_ShowCurrencyMenue();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eExit:
		{
			_LogOut();
			break;
		}

		}
	};

public:

	static void ShowMainMenue()
	{

		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[8] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
	}
};