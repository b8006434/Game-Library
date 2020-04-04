#pragma once

#include "Menu.h"
#include "Store.h"
#include "Game.h"
#include <string>
#include <vector>
#include "gameMenu.h"
#include"searchMenu.h"
class StoreMenu : public Menu
{
public:
	StoreMenu(const std::string& title, Application * app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;

private:
	Store* store1 = new Store(app->GetStore());
	List<Game*> games =store1->getGames();

};