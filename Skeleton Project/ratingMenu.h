#pragma once

#include "Menu.h"
#include <string>
#include <ctype.h>


class ratingMenu : public Menu
{
public:
	ratingMenu(const std::string& title, Application * app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;


private:
	User* currentUser = app->GetCurrentUser();
	vector<LibraryItem*> library = currentUser->getLibrary();
    Game* game1;
	vector<char>allOptions;

};