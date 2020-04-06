#include "userMenu.h"

userMenu::userMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint();
}

void userMenu::OutputOptions()
{
		for (int i = 0; i < usrs.length(); i++)
		{
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
		Line("Please enter password");
		cin >> password;
		usrLoggedIn = app->LoginUser(usrs[index]->GetUsername(), password);
		if (usrLoggedIn == true)
			MainMenu("MAIN APP", app);
	}
	return false;
}
