#include "searchResult.h"

searchResult::searchResult(const std::string& title, Application * app) : Menu(title, app)
{
	Paint();
}

void searchResult::OutputOptions()
{
	for (int a = 0; a < gameIDs.size(); a++)
	{
		Option(a + 1, games[gameIDs.at(a)]->GetName());
	}
}

bool searchResult::HandleChoice(char choice)
{
	int index = choice - '1';//this is a zero but supposed to be 1 on list
	int g = games[gameIDs.at(index)]->getID();
	app->setGameIndex(g);
	if (index >= 0 && index < gameIDs.size())
	{
		gameMenu g1(games[g]->GetName(), app);
	}

	return false;
}
