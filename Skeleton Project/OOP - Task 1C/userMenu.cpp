#include "userMenu.h"

userMenu::userMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint();
}

void userMenu::OutputOptions()
{
		for (int i = 0; i < usrs.length(); i++)
		{
			// adding 1 so the display is nicer for the user
			Option(i + 1, usrs[i]->GetUsername());
		}
}

bool userMenu::HandleChoice(char choice)
{
	int index = choice - '1';
	string password;
	bool usrLoggedIn = false;
	if (index >= 0 && index < usrs.length())
	{
		switch (choice)
		{
		case'1':
			Line("Please enter password");
			cin >> password;
			usrLoggedIn = app->LoginUser(usrs[0]->GetUsername(), password);
			if (usrLoggedIn == true)
				MainMenu("Main", app);
			break;
		case'2':
			Line("Please enter password");
			cin >> password;
			usrLoggedIn = app->LoginUser(usrs[1]->GetUsername(), password);
			if (usrLoggedIn == true)
				MainMenu("Main", app);
			break;
		}
	}
	return false;
}
