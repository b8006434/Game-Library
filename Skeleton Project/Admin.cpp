#include "Admin.h"

Admin::Admin(const std::string& username, const std::string& password, const Date dateCreated)
	: Player(username, password, dateCreated)
{
}

Admin::~Admin()
{
}