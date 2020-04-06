#include "Store.h"

Store::Store()
{
}

Store::~Store()
{

}

 List<Game*> Store::getGames()const
{
	return games;
}

void Store::addGame(Game* g)
{
	games.addAtEnd(g);
}
 vector<int> Store::searchByName(const string& search)
{
	if (gameIDs.size() != 0)
	{
		vector<int> temp = gameIDs;
		gameIDs.clear();
		for (int b = 0; b < temp.size(); b++)
		{
			if (Utils::startsWith(games[temp.at(b)]->GetName(),Utils::convertToUpper(search)))
			{
				gameIDs.push_back(games[temp.at(b)]->getID());
			}
	    }
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

 vector<int> Store::searchByPrice(const string& priceSeach)
{
	string delimiter = "-";
	vector<string> v = Utils::split(priceSeach, delimiter);
	float minPrice = stoi(v[0]);
	float maxPrice = stoi(v[1]);

	if (gameIDs.size() != 0)
	{
		vector<int> temp = gameIDs;
		gameIDs.clear();
		for (int b = 0; b < temp.size(); b++)
		{
			if (games[temp.at(b)]->GetCost() > minPrice &&  games[temp.at(b)]->GetCost() < maxPrice)
			{
				gameIDs.push_back(games[temp.at(b)]->getID());
			}
		}
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

 vector<int> Store::searchByRating(const string& ratingSearch)
{
	if (gameIDs.size() != 0)
	{
		vector<int> temp = gameIDs;
		gameIDs.clear();
		for (int b = 0; b < temp.size(); b++)
		{
			if (games[temp.at(b)]->getReviewPercentage() == ratingSearch)
			{
				gameIDs.push_back(games[temp.at(b)]->getID());
			}
		}
	}
	else
	{
		for (int a = 0; a < games.length(); a++)
		{
			if (games[a]->getReviewPercentage() == ratingSearch)
				gameIDs.push_back(games[a]->getID());
		}
	}
	return  gameIDs;
}


