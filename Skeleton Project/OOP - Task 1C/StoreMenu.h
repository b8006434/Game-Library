#pragma once

#include "Menu.h"
#include "Store.h"
#include "Game.h"
#include <string>
#include <vector>
#include "gameMenu.h"

class StoreMenu : public Menu
{
public:
	StoreMenu(const std::string& title, Application * app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
	void searchByName();
	void searchByPrice();
private:
	Store* store1 = new Store(app->GetStore());
	StoreMenu* sMenu;
	List<Game*> games =store1->getGames();
};