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
		const int& getID()const;
		const float& GetCost()const;
		void setName(const string& name);
		void setDescription(const string& description);
		void setCost(const string& costf);
		void setAgeRating(const int& ageRating);
		void setID(const int& id);
		void addLike();
		void addDisLike();
		string getReviewPercentage()const;
		const int& getAgeRating()const;
		void clearRatings();
	private:
		string name;
		string description;
		vector<int> reviews;
		float cost;
		int ageRating;
		int id;

};