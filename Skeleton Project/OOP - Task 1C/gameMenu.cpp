#include "gameMenu.h"

gameMenu::gameMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint();
}


void gameMenu::OutputOptions()
{

	float gameCost = Utils::convertToFloat(games[gameIndex]->GetCost());;
	string gameCostf = to_string(gameCost);
	if (!app->IsUserLoggedIn())
	{
		Line(games[gameIndex]->GetDescription());
		Line("Cost: "+gameCostf);
	}
	else
	{
		float usrCredits = app->GetCurrentUser()->getCredits();
		Line(games[gameIndex]->GetDescription());
		Line("Cost: "+gameCostf);
		Line("Credits: " + to_string(usrCredits));
		Option('P', "Purchase for: " + gameCostf);
		if (gamePurchased == true)
		{
			Line();
			Line("You own this game");
			Line("Date purchased: " + date);
		}
	}
}

bool gameMenu::HandleChoice(char choice)
{
	if (choice == 'p' || choice == 'P')
	{
		float usrCredits = app->GetCurrentUser()->getCredits();
		float gameCost = Utils::convertToFloat(games[gameIndex]->GetCost());

		if (usrCredits > gameCost)
		{
			
			Date date1(10, 02, 2011);
			LibraryItem* lib = new LibraryItem(date1, games[gameIndex]);
			lib->setDatePurchased(date);
			currentUser->addToLibrary(lib);
			currentUser->takeCredits(gameCost);
			gamePurchased = true;
		}
	}
	return false;
}


