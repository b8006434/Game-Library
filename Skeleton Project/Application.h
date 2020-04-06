#pragma once

#include "Account.h"
#include "User.h"
#include "Store.h"
#include "List.h"
#include <iostream>
#include <fstream>
#include "Admin.h"

class Application
{
	public:
		Application();
		~Application();

		bool IsAccountLoggedIn() const;
		bool IsUserLoggedIn() const;
		Account* GetCurrentAccount() const;
		User* GetCurrentUser() const;
		Store& GetStore();
		List<Account*> getAccounts()const;
		bool LoginAccount(const std::string& email, const std::string& password);
		bool LoginUser(const std::string& username, const std::string& password);
		void LogoutUser();
		void addUsers();
		void addUser(User* nUser);
		void removeUser(const string& dUser);
		void addLibraryItems();
		void Load();
		void Save();
		void setGameIndex(const int& index);
		int returnIndex();
		void setGamesFound(const vector<int>& games);
		vector<int> returnGamesFound()const;
	private:
		Store store;
		Account* currentAccount;
		User* currentUser;
		List<Account*> accounts;
		List<User*> users;
		List<LibraryItem*> libraryItems;
		int gameIndex;
		vector<int> gamesFound;
};