#pragma once

#include "Menu.h"
#include "userProfile.h"
#include"LoginMenu.h"
#include "StoreMenu.h"
#include "Application.h"
#include "Account.h"
class MainMenu : public Menu
{
public:
	MainMenu(const std::string& title, Application * app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
private:


};