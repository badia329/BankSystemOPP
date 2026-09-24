#pragma once
#include <iomanip>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen : protected clsScreen
{
private:

	static void _PrintCurrencyRecord(clsCurrency Currency)
	{
		cout << "\t\nCurrency Card:\n";
		cout << "\t\n_________________________________\n\n";
		cout << "Country       :" << Currency.CurrencyName() << endl;
		cout << "Code          :" << Currency.CurrencyCode() << endl;
		cout << "name          :" << Currency.CurrencyName() << endl;
		cout << "Rate(1$)  =   :" << Currency.Rate() << endl;
		cout << "\t\n_________________________________\n\n";

	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found !-)\n";
			_PrintCurrencyRecord(Currency);
		}
		else
		{
			cout << "\nCurrency was not Found :-(\n";
		}
	}

public:

	static void _ShowFindCurrencyScreen()
	{
		
		_DrawScreenHeader("\t  Find Currency Screen");

		cout << "Find By: [1] Code or [2] Country ? ";
		short Answer = 0;
		cin >> Answer;

		if (Answer == 1)
		{
			string CurrencyCode;
			cout << "\nPlease Enter CurrencyCode: ";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(Currency);

		}
		else
		{
			string CurrencyCountry;
			cout << "Please Enter Currency Country Name: ";
			cin >> CurrencyCountry;
			clsCurrency Currency = clsCurrency::FindByCountry(CurrencyCountry);
			_ShowResults(Currency);

		}
	}

};