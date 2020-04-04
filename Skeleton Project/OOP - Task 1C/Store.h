#pragma once

#include "Game.h"
#include "List.h"

class Store
{
	public:
		Store();
		~Store();
		List<Game*> getGames();
		void addGame(Game* g);
		vector<int> searchByName(string search);
		vector<int> searchByPrice(string priceSeach);
	private:
		List<Game*> games;
		vector<int> gameIDs;
		
};