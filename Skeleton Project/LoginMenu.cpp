#include "LoginMenu.h"

LoginMenu::LoginMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint();
}

void LoginMenu::OutputOptions()
{

	for (int i = 0; i < currentAccounts.length(); i++)
	{
		// adding 1 so the display is nicer for the user
		Option(i + 1, currentAccounts[i]->returnEmail());
	}
}

bool LoginMenu::HandleChoice(char choice)
{
	// since we are using numbers here we shift the char down by '1'
// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
// this reverses the + 1 above and lets us do the range check below
	bool accLoggedIn = false;
	int index = choice - '1';
	string password;
	if (index >= 0 && index < currentAccounts.length())
	{
		string password; 
		cout << ("Please enter password for this account: "); 
		cin >> password;
		accLoggedIn = app->LoginAccount(currentAccounts[index]->returnEmail(), password);
		if (accLoggedIn == true)
			userMenu("CHOOSE USER", app);
	}
	return false;
}




