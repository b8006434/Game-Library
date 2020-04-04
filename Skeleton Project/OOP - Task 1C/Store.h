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
	private:
		List<Game*> games;
};