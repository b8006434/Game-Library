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
		List<User*> getUsers();
		string returnEmail();
		string returnPassword();
		void setEmail(string email);
		void setPassword(string password);
		void setDateCreated(string date);
	private:
		std::string email;
		std::string password;
		List<User*> users;
		Date dateCreated;
};