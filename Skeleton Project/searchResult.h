#pragma once

#include "Menu.h"
#include "userMenu.h"
#include <string>


class searchResult : public Menu
{
public:
	searchResult(const std::string& title, Application * app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;


private:
	Store* store1 = new Store(app->GetStore());
	List<Game*> games = store1->getGames();
	vector<int> gameIDs = app->returnGamesFound();
};