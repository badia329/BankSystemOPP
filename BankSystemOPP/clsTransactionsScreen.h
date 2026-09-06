#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalances.h"

using namespace std;

class clsTransactionsScree : protected clsScreen
{
private:

	enum enTransactionsMenueOptions
	{
		eDposit = 1, eWithdraw = 2,
		eShowTotalBalance = 3, sShowMainMenue = 4
	};

	static short _ReadTransactionsMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Enter Number between 1 to 4? ");
		return Choice;
	}

	static void _ShowDepositScree()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrowScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalances::showTotalBalances();
	}

	static void _GoBackToTransactionsMenueOption()
	{
		cout << "\n\nPress any Key to go back to Transactions Menue...";
		system("pause>0");
		ShowTransactionsMenue();
	}

	static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TranssactionsMenueOption)
	{
		switch (TranssactionsMenueOption)
		{
		case enTransactionsMenueOptions::eDposit:
		{
			system("cls");
			_ShowDepositScree();
			_GoBackToTransactionsMenueOption();
			break;
		}

		case enTransactionsMenueOptions::eWithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenueOption();
			break;
		}

		case enTransactionsMenueOptions::eShowTotalBalance:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenueOption();
			break;
		}

		case enTransactionsMenueOptions::sShowMainMenue:
		{
			//do nothing here the main screen will handle it :-) ;
		}

		}

	}

public:
	static void ShowTransactionsMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
		{
			return;
		}

		system("cls");
		_DrawScreenHeader("\tTransactions Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "" << "\t\t Transactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformTransactionsMenueOption((enTransactionsMenueOptions)_ReadTransactionsMenueOption());
	}

};