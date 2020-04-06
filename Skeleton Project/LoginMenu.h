#pragma once

#include "Menu.h"
#include "userMenu.h"
#include <string>


class LoginMenu : public Menu
{
public:
	LoginMenu(const std::string& title, Application * app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;


private:
	List<Account*> currentAccounts = app->getAccounts();
	 Account* ac= app->GetCurrentAccount();
	
};