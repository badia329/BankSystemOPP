#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "clsLoginScreen.h"
#include "Global.h"

int main()

{
	while (true)
	{
		clsLoginScreen::ShowLoginScreen();
	}

	system("pause>0");
	return 0;
}