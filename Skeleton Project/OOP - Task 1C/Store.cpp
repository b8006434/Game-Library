#include "Store.h"

Store::Store()
{
}

Store::~Store()
{

}

List<Game*> Store::getGames()
{
	return games;
}

void Store::addGame(Game* g)
{
	games.addAtEnd(g);
}
vector<int> Store::searchByName(string search)
{
	if (gameIDs.size() != 0)
	{
		gameIDs.clear();
	}
	else
	{
		for (int a = 0; a < games.length(); a++)
		{
			if (Utils::startsWith(games[a]->GetName(),Utils::convertToUpper(search)))
				gameIDs.push_back(games[a]->getID());
		}
	}
	return  gameIDs;
}

vector<int> Store::searchByPrice(string priceSeach)
{
	string delimiter = "-";
	vector<string> v = Utils::split(priceSeach, delimiter);
	float minPrice = stoi(v[0]);
	float maxPrice = stoi(v[1]);
	if (gameIDs.size() != 0)
	{
		gameIDs.clear();
	}
	else
	{
		for (int a = 0; a < games.length(); a++)
		{
			if (games[a]->GetCost() > minPrice &&  games[a]->GetCost() < maxPrice)
			{
				gameIDs.push_back(games[a]->getID());
			}
		}
	}
	return  gameIDs;
}


