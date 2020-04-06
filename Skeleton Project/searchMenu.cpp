#include "searchMenu.h"

searchMenu::searchMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint();
}

void searchMenu::OutputOptions()
{
	vector<int> gameIDs = app->returnGamesFound();
	int  gamesSize;
	if(gameIDs.size() == 0)
	gamesSize = games.length();
	else gamesSize = gameIDs.size();
	Line("Searching " + to_string(gamesSize) + " games");
	Option('N', "Search by name");
	Option('P', "Search by price");
	Option('O', "Search by rating");
}

bool searchMenu::HandleChoice(char choice)
{
	string search;
	switch (choice)
	{
	case 'N':
		search = Question("Enter name to search for");
		app->setGamesFound(store1->searchByName(search));
		searchResult("Searched By Name", app);
		break;
	case'P':
		search=	Question("Enter price range to search(e.g 5-10)");
		app->setGamesFound(store1->searchByPrice(search));
		searchResult("Searched By Price", app);
		break;
	case'O':
		search = Question("Enter rating to search e.g 20%");
		app->setGamesFound(store1->searchByRating(search));
		searchResult("Searched By Rating", app);
		break;
	}


	return false;
}
