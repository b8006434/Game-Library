#include "Account.h"

Account::Account(const std::string& email, const std::string& password, const Date dateCreated)
	: email(email), password(password), dateCreated(dateCreated)
{
}

Account::~Account()
{
	for (int i = 0; i < 3; ++i)
	{
		delete users[i];
	}
}

void Account::addUser(User* user)
{
	users.addAtEnd(user);
}

List<User*> Account::getUsers()
{
	return users;
}

string Account::returnEmail()
{
	return email;
}

string Account::returnPassword()
{
	return password;
}

void Account::setEmail(string email)
{
	this->email = email;
}

void Account::setPassword(string password)
{
	this->password = password;
}

void Account::setDateCreated(string date)
{
	string delimiter = "-";
	vector<string> v = Utils::split(date, delimiter);
	int day = stoi(v[2]);
	int month = stoi(v[1]);
	int year = stoi(v[0]);
	Date newDate(day, month, year);

	this->dateCreated = newDate;

}


