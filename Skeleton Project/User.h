#pragma once

#include <string>
#include "Date.h"
#include "List.h"
#include "LibraryItem.h"

class User
{
	public:
		User(const std::string&, const std::string&,const Date dateCreated);
		virtual ~User();
		const std::string& GetUsername() const;
		const std::string& GetPassword() const;
		const Date& getDateCreated();
	    const float& getCredits()const;
		vector<LibraryItem*> getLibrary();
		void setUsername(const string& username);
		void setPassword(const string& password);
		void setDateCreated(const string& date);
		void setCredits(const string& credits);
		void addToLibrary(LibraryItem* l);
		void setType(const string& type);
		const string& returnType()const;
		void takeCredits(const float& minusCredits);
		void addCredits(const float& addCredits);
		void clearLibrary();
	protected:
		std::string username;
		std::string password;
		Date dateCreated;  // TODO: replace with custom Date class, currently YYYY-MM-DD
		float credits;
		vector<LibraryItem*>  library;
		string type;

};