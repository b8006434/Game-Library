#include "searchMenu.h"

searchMenu::searchMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint();
}

void searchMenu::OutputOptions()
{
	Line("Searching " + to_string(games.length()) + " games");
	Option('N', "Search by name");
	Option('P', "Search by price");
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
	}


	return false;
}
