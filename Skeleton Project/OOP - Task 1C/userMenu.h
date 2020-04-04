#pragma once

#include "Menu.h"
#include "MainMenu.h"
#include <string>
#include <vector>

class userMenu : public Menu
{
public:
	userMenu(const std::string& title, Application * app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
private:
	Account* ac = app->GetCurrentAccount();
	List<User*> usrs = ac->getUsers();                // get users from current account
};