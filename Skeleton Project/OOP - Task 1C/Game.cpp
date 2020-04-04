#include "Game.h"

Game::Game(const std::string& name, const std::string& desc, int cost, int rating, int id)
	: name(name), description(desc), cost(cost), ageRating(rating),id(id)
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

int Game::GetCost() const
{
	return cost;
}

void Game::setName(string name)
{
	this->name = name;
}

void Game::setDescription(string description)
{
	this->description = description;
}

void Game::setCost(int cost)
{
	this->cost = cost;
}

void Game::setAgeRating(int ageRating)
{
	this->ageRating = ageRating;
}

void Game::setID(int id)
{
	this->id = id;
}
