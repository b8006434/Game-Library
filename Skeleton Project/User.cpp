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

const Date& User::getDateCreated()
{
	if (dateCreated.returnDate() != "")
		return dateCreated;
	//else
		//return dateCreated.currentDateTime();
}

const float& User::getCredits()const
{
	return credits;
}

vector<LibraryItem*> User::getLibrary()
{
	return library;
}

void User::setUsername(const string& username)
{
	this->username = username;
}

void User::setPassword(const string& password)
{
	this->password = password;
}

void User::setDateCreated(const string& date)
{
	string delimiter = "-";
	vector<string> v = Utils::split(date, delimiter);
	int day = stoi(v[2]);
	int month = stoi(v[1]);
	int year = stoi(v[0]);
	Date newDate(day, month, year);

	this->dateCreated = newDate;
}

void User::setCredits(const string& credits)
{
	this->credits = stof(credits)/100;
}

void User::addToLibrary(LibraryItem * l)
{
	library.push_back(l);
}

void User::setType(const string& type)
{
	this->type = type;
}

const string& User::returnType()const
{
	return type;
}

void User::takeCredits(const float& minusCredits)
{
	this->credits = credits - minusCredits;
}

void User::addCredits(const float& addCredits)
{
	this->credits = credits + addCredits;
}

void User::clearLibrary()
{
	library.clear();
}
