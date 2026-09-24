#pragma once
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRate.h"

class clsCurrencyScreen : protected clsScreen
{

private:

	enum enCurrencyMenueOption { eListCurrencies = 1, eFindCurrencies = 2, eUdpateCurrencies = 3, eCurrencyCalculator = 4, eMainMenue = 5};

public:

	static void _GoBackToCurrencyMenu()
	{
		cout << setw(37) << left << "" << "\n\t\Press any key to go back to Currency Menue...\n";

		system("pause>0");
		_ShowCurrencyMenuScreen();
	}

	static void _ShowCurrencyListScreen()
	{
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::_ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyRateScreen()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		// Calculator Screen Will be here 
	}

	static void _GoBackToMainMenu()
	{
		// Nothing here
	}

	static void _PerformCurrencyMenuOption(enCurrencyMenueOption CurrencyMenueOption)
	{
		system("cls");

		switch (CurrencyMenueOption)
		{

		case enCurrencyMenueOption::eListCurrencies:
		{
			_ShowCurrencyListScreen();
			_GoBackToCurrencyMenu();
			break;
		}

		case enCurrencyMenueOption::eFindCurrencies:
		{
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyMenu();
			break;
		}

		case enCurrencyMenueOption::eUdpateCurrencies:
		{
			_ShowUpdateCurrencyRateScreen();
			_GoBackToCurrencyMenu();
			break;
		}

		case enCurrencyMenueOption::eCurrencyCalculator:
		{
			_ShowCurrencyMenuScreen();
			_GoBackToCurrencyMenu();
			break;
		}

		case enCurrencyMenueOption::eMainMenue:
		{
			_GoBackToMainMenu();
			break;
		}

		}
		
	}

	static short _ReadCurrencyMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return choice;
	}

	static void _ShowCurrencyMenuScreen()
	{

		system("cls");
		_DrawScreenHeader("\tCurrency Exhange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tCurrency Exhange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currencies.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCurrencyMenuOption((enCurrencyMenueOption)_ReadCurrencyMenuOption());
	}

};

