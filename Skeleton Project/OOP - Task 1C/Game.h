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
		int getID();
		float GetCost() const;
		void setName(string name);
		void setDescription(string description);
		void setCost(string costf);
		void setAgeRating(int ageRating);
		void setID(int id);
	private:
		std::string name;
		std::string description;
		float cost;
		int ageRating;
		int id;
};