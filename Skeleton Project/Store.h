#pragma once

#include "Game.h"
#include "List.h"

class Store
{
	public:
		Store();
		~Store();
		List<Game*> getGames()const;
		void addGame(Game* g);
		vector<int> searchByName(const string& search);
		vector<int> searchByPrice(const string& priceSeach);
		vector<int> searchByRating(const string& ratingSearch);
	private:
		List<Game*> games;
		vector<int> gameIDs;
		
};