#include "User.h"

User::User(const std::string& username, const std::string& password, const Date dateCreated)
	: username(username), password(password), dateCreated(dateCreated)
{
}

User::~User()
{
}

const std::string& User::GetUsername() const
{
	return username;
}

const std::string & User::GetPassword()const
{
	return password;
}

const Date User::getDateCreated()
{
	if (dateCreated.returnDate() != "")
		return dateCreated;
	//else
		//return dateCreated.currentDateTime();
}

float User::getCredits()
{
	return credits;
}

List<LibraryItem*> User::getLibrary()
{
	return library;
}

void User::setUsername(string username)
{
	this->username = username;
}

void User::setPassword(string password)
{
	this->password = password;
}

void User::setDateCreated(string date)
{
	string delimiter = "-";
	vector<string> v = Utils::split(date, delimiter);
	int day = stoi(v[2]);
	int month = stoi(v[1]);
	int year = stoi(v[0]);
	Date newDate(day, month, year);

	this->dateCreated = newDate;
}

void User::setCredits(string credits)
{
	this->credits = stof(credits)/100;
}

void User::addToLibrary(LibraryItem * l)
{
	library.addAtEnd(l);
}

void User::setType(string type)
{
	this->type = type;
}

string User::returnType()
{
	return type;
}

void User::takeCredits(float minusCredits)
{
	this->credits = credits - minusCredits;
}

void User::addCredits(float addCredits)
{
	this->credits = credits + addCredits;
}
