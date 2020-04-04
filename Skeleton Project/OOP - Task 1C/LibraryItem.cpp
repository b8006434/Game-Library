#include "LibraryItem.h"

LibraryItem::LibraryItem(const Date date, Game* game)
	: purchased(date), game(game)
{
}

LibraryItem::~LibraryItem()
{
}

const Game* LibraryItem::returnGame()
{
	return game;
}

void LibraryItem::setGame(Game * g)
{
	this->game = g;
}

void LibraryItem::setDatePurchased(string date)
{
	string delimiter = "-";
	vector<string> v = Utils::split(date, delimiter);
	int day = stoi(v[2]);
	int month = stoi(v[1]);
	int year = stoi(v[0]);
	Date newDate(day, month, year);

	this->purchased = newDate;
}

void LibraryItem::setMinsPlayed(string minsPlayed)
{
	this->minsPlayed = stoi(minsPlayed);
}
