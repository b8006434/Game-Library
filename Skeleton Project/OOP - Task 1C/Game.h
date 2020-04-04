#pragma once

#include <string>
#include "List.h"
#include "Date.h"
class Game
{
	public:
		Game(const std::string&, const std::string&, int, int,int);
		~Game();

		const std::string& GetName() const;
		const std::string& GetDescription() const;
		int GetCost() const;
		void setName(string name);
		void setDescription(string description);
		void setCost(int cost);
		void setAgeRating(int ageRating);
		void setID(int id);
	private:
		std::string name;
		std::string description;
		int cost;
		int ageRating;
		int id;
};