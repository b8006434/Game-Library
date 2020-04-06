#pragma once

#include <string>
#include "List.h"
#include "Player.h"
#include "Date.h"

class Account
{
	public:
		Account(const std::string&, const std::string&, const Date dateCreated);
		~Account();
		void addUser(User* user);
		const List<User*> getUsers()const;
		const string& returnEmail()const;
		const string& returnPassword()const;
		void setEmail(const string& email);
		void setPassword(const string& password);
		void setDateCreated(const string& date);
		void clearUsers();
		const Date& getDateCreated()const;
	private:
		string email;
		string password;
		List<User*> users;
		Date dateCreated;
};