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

const List<User*> Account::getUsers()const
{
	return users;
}

const string& Account::returnEmail()const
{
	return email;
}

const string& Account::returnPassword()const
{
	return password;
}

void Account::setEmail(const string& email)
{
	this->email = email;
}

void Account::setPassword(const string&password)
{
	this->password = password;
}

void Account::setDateCreated(const string& date)
{
	string delimiter = "-";
	vector<string> v = Utils::split(date, delimiter);
	int day = stoi(v[2]);
	int month = stoi(v[1]);
	int year = stoi(v[0]);
	Date newDate(day, month, year);

	this->dateCreated = newDate;

}

void Account::clearUsers()
{
	for (int a = 0; a <= users.length(); a++)
	{
		users.deleteFirst();
	}
	users.deleteFirst();
}
const Date& Account::getDateCreated()const
{
	return dateCreated;
}





