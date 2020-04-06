#pragma once

#include "Menu.h"
#include "Admin.h"
#include <string>
#include <vector>
#include <algorithm>
#include"ratingMenu.h"

class userProfile : public Menu
{
public:
	userProfile(const std::string& title, Application * app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
	void sortByGameName();
	void sortByDatePurchased();
	static bool compByName(LibraryItem* a, LibraryItem* b);
	static bool compByDate(LibraryItem* a, LibraryItem* b);
private:
	User* currentUser = app->GetCurrentUser();
	vector<LibraryItem*> library = currentUser->getLibrary();
	const Game* game1;
};

