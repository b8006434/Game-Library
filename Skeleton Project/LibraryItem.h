#pragma once

#include "Game.h"

class LibraryItem
{
	public:
		LibraryItem(const Date, Game*);
		~LibraryItem();
		Game* returnGame()const;
		void  setGame(Game* g);
		void setDatePurchased(const string& date);
		void setMinsPlayed(const string& minsPlayed);
		void addMinsPlayed(const int& mins);
		const int& returnMinsPlayer()const;
		const Date& returnDatePurchased()const;
	    const bool& getGameRatedStatus()const;
		void setGameRatedStatus(const bool& status);
	private:
		 Game* game;
		 Date purchased; 
		int minsPlayed;
		bool gameRated;
};