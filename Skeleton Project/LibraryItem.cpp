#include "LibraryItem.h"

LibraryItem::LibraryItem(const Date date, Game* game)
	: purchased(date), game(game)
{
}

LibraryItem::~LibraryItem()
{
}

Game* LibraryItem::returnGame()const
{
	return game;
}

void LibraryItem::setGame(Game * g)
{
	this->game = g;
}

void LibraryItem::setDatePurchased(const string& date)
{
	string delimiter = "-";
	vector<string> v = Utils::split(date, delimiter);
	int day = stoi(v[2]);
	int month = stoi(v[1]);
	int year = stoi(v[0]);
	Date newDate(day, month, year);

	this->purchased = newDate;
}

void LibraryItem::setMinsPlayed(const string& minsPlayed)
{
	this->minsPlayed = stoi(minsPlayed);
}

void LibraryItem::addMinsPlayed(const int& mins)
{
	this->minsPlayed = mins + minsPlayed;
}

const int& LibraryItem::returnMinsPlayer()const
{
	return  minsPlayed;
}

 const Date& LibraryItem::returnDatePurchased()const
{
	return purchased;
}

 const bool& LibraryItem::getGameRatedStatus()const
{
	return gameRated;
}

void LibraryItem::setGameRatedStatus(const bool& status)
{
	this->gameRated = status;
}
