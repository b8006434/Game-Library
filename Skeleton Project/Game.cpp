#include "Game.h"

Game::Game(const std::string& name, const std::string& desc, int cost, int rating, int id)
	:name(name), description(desc), cost(cost), ageRating(rating),id(id)
{
}

Game::~Game()
{
}

const std::string& Game::GetName() const
{
	return name;
}

const std::string& Game::GetDescription() const
{
	return description;
}

const int& Game::getID()const
{
	return id;
}

const float& Game::GetCost()const
{
	return cost;
}

void Game::setName(const string& name)
{
	this->name = name;
}

void Game::setDescription(const string& description)
{
	this->description = description;
}

void Game::setCost(const string& costf)
{
	this->cost = stof(costf)/100;
}

void Game::setAgeRating(const int& ageRating)
{
	this->ageRating = ageRating;
}

void Game::setID(const int& id)
{
	this->id = id;
}

void Game::addLike()
{
	reviews.push_back(1);
}

void Game::addDisLike()
{
	reviews.push_back(2);
}

string Game::getReviewPercentage()const
{
	
	int likes = 0;
	if (reviews.size() != 0)
	{
		int allReviews = reviews.size();
		int dislikes = allReviews - likes;
		float percentage;
		for (int a = 0; a < reviews.size(); a++)
		{
			if (reviews.at(a) == 1)
				likes++;
		}
		percentage = (likes * 100) / allReviews;
		if (percentage < 0)
		{
			return "0%";
		}
		return Utils::prd(percentage, 0) + "%";
	}
	else
		return "0%";
}

const int& Game::getAgeRating()const
{
	return ageRating;
}

void Game::clearRatings()
{
	reviews.clear();
}




