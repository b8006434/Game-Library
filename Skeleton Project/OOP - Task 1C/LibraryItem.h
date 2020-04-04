#pragma once

#include "Game.h"

class LibraryItem
{
	public:
		LibraryItem(const Date, Game*);
		~LibraryItem();
		const Game* returnGame();
		void  setGame(Game* g);
		void setDatePurchased(string date);
		void setMinsPlayed(string minsPlayed);
	private:
		const Game* game;
		 Date purchased; 
		int minsPlayed;
};