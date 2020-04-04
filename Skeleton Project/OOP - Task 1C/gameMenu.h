#pragma once

#include "Menu.h"
#include "userMenu.h"
#include <string>


class gameMenu : public Menu
{
public:
	gameMenu(const std::string& title, Application * app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;

private:
	string date = Date::currentDateTime();
	Store* store = new Store(app->GetStore());
	List<Game*> games = store->getGames();
	User* currentUser = app->GetCurrentUser();
	int gameIndex = app->returnIndex();
	bool gamePurchased = false;
};