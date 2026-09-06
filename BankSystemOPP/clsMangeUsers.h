#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserrScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;

class clsMangeUsers : protected clsScreen
{
private:
	enum enMangeUsersScreenOption { eListUsers = 1, eAddNewUser = 2,
		eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainMenue = 6 };

	static short _ReadMangeUsersOption()
	{
		cout << setw(37) << left << "Choose What do you want to do ? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1,6, "Enter Number between 1 to 6 ");
		return Choice;
	}

	static void _ShowListUsersScreen()
	{
		clsListUsersScreen::ShowUsersList();
	}

	static void _ShowAddNewUser()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		clsDeleteClientScreen::DeleteClient();
	}

	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _ShowMainMenu()
	{
		// Nothing here
	}

	static void _GoBackToMangeUsersScreen()
	{
		cout << "\n\nPress any key to go back to Manage Users Menu...";
		system("pause>0");
		ShowMangeUsersMenueScreen();
	}

	static void _PerformMangeUsersMenueOption(enMangeUsersScreenOption MangeUsersScreenOption)
	{
		system("cls");

		switch (MangeUsersScreenOption)
		{
		case enMangeUsersScreenOption::eListUsers:
		{
			_ShowListUsersScreen();
			_GoBackToMangeUsersScreen();
			break;
		}

		case enMangeUsersScreenOption::eAddNewUser:
		{
			_ShowAddNewUser();
			_GoBackToMangeUsersScreen();
			break;
		}

		case enMangeUsersScreenOption::eDeleteUser:
		{
			_ShowDeleteUserScreen();
			_GoBackToMangeUsersScreen();
			break;
		}

		case enMangeUsersScreenOption::eUpdateUser:
		{
			_ShowUpdateUserScreen();
			_GoBackToMangeUsersScreen();
			break;
		}

		case enMangeUsersScreenOption::eFindUser:
		{
			_ShowUpdateUserScreen();
			_GoBackToMangeUsersScreen();
			break;
		}

		case enMangeUsersScreenOption::eMainMenue:
		{
			_ShowMainMenu();
			break;
		}
		}
	}
public:

	static void ShowMangeUsersMenueScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}

		system("cls");
		_DrawScreenHeader("\tMange Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "" << "\t\t Mange Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformMangeUsersMenueOption((enMangeUsersScreenOption)_ReadMangeUsersOption());
	}
};

