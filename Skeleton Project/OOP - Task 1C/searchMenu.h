#pragma once

#include "Menu.h"
#include "userMenu.h"
#include <string>
#include"searchResult.h"

class searchMenu : public Menu
{
public:
	searchMenu(const std::string& title, Application * app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;


private:
	Store* store1 = new Store(app->GetStore());
	List<Game*> games = store1->getGames();
};