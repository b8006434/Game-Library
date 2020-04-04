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
		const Date getDateCreated();
		float getCredits();
		List<LibraryItem*> getLibrary();
		void setUsername(string username);
		void setPassword(string password);
		void setDateCreated(string date);
		void setCredits(string credits);
		void addToLibrary(LibraryItem* l);
		void setType(string type);
		string returnType();
		void takeCredits(float minusCredits);
		void addCredits(float addCredits);
	protected:
		std::string username;
		std::string password;
		Date dateCreated;  // TODO: replace with custom Date class, currently YYYY-MM-DD
		float credits;
		List<LibraryItem*>  library;
		string type;

};