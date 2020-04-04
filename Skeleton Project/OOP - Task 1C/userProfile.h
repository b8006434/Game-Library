#pragma once

#include "Menu.h"
#include "Admin.h"
#include <string>
#include <vector>

class userProfile : public Menu
{
public:
	userProfile(const std::string& title, Application * app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
private:
	User* currentUser = app->GetCurrentUser();
	List<LibraryItem*> library = currentUser->getLibrary();
	const Game* game;
};