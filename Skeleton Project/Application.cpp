#include "Application.h"

Application::Application() : currentAccount(nullptr), currentUser(nullptr)
{

}

Application::~Application()
{
	for (int i = 0; i < 1; ++i)
	{
		delete accounts[i];
	}
}

bool Application::IsUserLoggedIn() const
{
	return currentUser != nullptr;
}

bool Application::IsAccountLoggedIn() const
{
	return currentAccount != nullptr;
}

Account* Application::GetCurrentAccount() const
{
	return currentAccount;
}

User* Application::GetCurrentUser() const
{
	return currentUser;
}

Store& Application::GetStore()
{
	return store;
}

List<Account*> Application::getAccounts()const
{
	return accounts;
}



bool Application::LoginAccount(const std::string& email, const std::string& password)
{
	// TODO: This currently always logs you in as the first account
	for (int i = 0; i < accounts.length(); i++)
	{
		if (email == accounts[i]->returnEmail())
		{
			if (password == accounts[i]->returnPassword())
			{
				currentAccount = accounts[i];
				addUsers();
				return true;
			}
		}

	}
	return false;

}

bool Application::LoginUser(const std::string& username, const std::string& password)
{
	List<User*> users = currentAccount->getUsers();
	
	for (int z = 0; z < users.length();z++)
	{
		if(username == users[z]->GetUsername())
			if (password == users[z]->GetPassword())
			{
				currentUser = users[z];
				addLibraryItems();
				return true;
			}
	}
	return false;
}

void Application::LogoutUser()
{
	Save();
	gamesFound.clear();
	currentUser = nullptr;

}


void Application::addUsers()
{

	if (currentAccount != nullptr)
	{
		if(currentAccount->getUsers().length() != 0)
		currentAccount->clearUsers();
		for (int a = 0; a < users.length(); a++)
		{
			currentAccount->addUser(users[a]);
		}
	}
}

void Application::addUser(User * nUser)
{
	users.addAtEnd(nUser);
}

void Application::removeUser(const string& dUser)
{
	for (int a = 0; a < users.length(); a++)
	{
		if (Utils::convertToUpper(users[a]->GetUsername()) == Utils::convertToUpper(dUser))
		{
			users.deleteOne(users[a]);
		}
	}
}

void Application::addLibraryItems()
{
	if (currentUser != nullptr)
	{
		if (currentUser->getLibrary().size() != 0)
		{
			currentUser->clearLibrary();
		}
		else
		{
			currentUser->addToLibrary(libraryItems[0]);
			currentUser->addToLibrary(libraryItems[2]);
			currentUser->addToLibrary(libraryItems[5]);
		}
	}



}

void Application::Load()
{

	ifstream myfile("data.txt");
	string line;


	if (!myfile)
	{
		cout << ("Error: data.txt not found");
		system("pause");
		exit(EXIT_FAILURE);
	}

	while (getline(myfile,line))
	{

		if (line == Utils::convertToUpper("game"))
		{
			Game gam1("t","a",1,2,3);
			getline(myfile, line);
			gam1.setID(stoi(line));
			getline(myfile, line);
			gam1.setName(line);
			getline(myfile, line);
			gam1.setDescription(line);
			getline(myfile, line);
			gam1.setCost(line);
			getline(myfile, line);
			gam1.setAgeRating(stoi(line));
			Game* newG = new Game(gam1);
			store.addGame(newG);
		}
		if(line == Utils::convertToUpper("account"))
		{
			Date date(10, 02, 2018);
			Account ac("1", "2", date);
			getline(myfile, line);
			ac.setDateCreated(line);
			getline(myfile, line);
			ac.setEmail(line);
			getline(myfile, line);
			ac.setPassword(line);
			Account* newAc = new Account(ac);
			accounts.addAtEnd(newAc);
		}
		if (line == Utils::convertToUpper("account-player"))
		{
			Date date(10, 02, 2018);
			Player p1("s", "a", date);
			getline(myfile, line);
			p1.setDateCreated(line);
			getline(myfile, line);
			p1.setUsername(line);
			getline(myfile, line);
			p1.setPassword(line);
			getline(myfile, line);
			p1.setCredits(line);
			Player* player = new Player(p1);
			users.addAtEnd(player);
		}
		if (line == Utils::convertToUpper("account-admin"))
		{
			Date date(10, 02, 2018);
			Admin a1("a", "s", date);
			getline(myfile, line);
			a1.setDateCreated(line);
			getline(myfile, line);
			a1.setUsername(line);
			getline(myfile, line);
			a1.setPassword(line);
			getline(myfile, line);
			a1.setCredits(line);
			a1.setType("admin");
			Admin* admin = new Admin(a1);
			users.addAtEnd(admin);
		}
		if (line == Utils::convertToUpper("library-item"))
		{
			List<Game*> games = store.getGames();
			Date date(10, 02, 2018);
			LibraryItem l1(date, games[0]);
			getline(myfile, line);
			int pos = stoi(line);
			l1.setGame(games[pos]);
			getline(myfile, line);
			l1.setDatePurchased(line);
			getline(myfile, line);
			l1.setMinsPlayed(line);
			LibraryItem* libItem = new LibraryItem(l1);
			libraryItems.addAtEnd(libItem);
		}

	}
}

void Application::Save()
{
	ofstream myfile("data.txt");
	string line;
	List<Game*> games = store.getGames();
	int cost;
	if (!myfile)
	{
		cout << ("Error: data.txt not found");
		system("pause");
		exit(EXIT_FAILURE);
	}

	if (myfile.is_open())
	{
		for (int a = 0; a < games.length(); a++)
		{
			myfile << "GAME" << endl;
			myfile << games[a]->getID() << endl;
			myfile << games[a]->GetName() << endl;
			myfile << games[a]->GetDescription() << endl;
			cost = games[a]->GetCost() * 100;
			myfile << cost << endl;
			myfile << games[0]->getAgeRating()<<endl;
		}
		for (int b = 0; b < accounts.length(); b++)
		{
			Date dateCreated = accounts[b]->getDateCreated();
			myfile << "ACCOUNT" << endl;
			myfile << dateCreated.returnDate() << endl;
			myfile << accounts[b]->returnEmail() << endl;
			myfile << accounts[b]->returnPassword() << endl;
		}
		for (int c = 0; c < users.length(); c++)
		{
		
	    if (users[c]->returnType() == "admin")
			{
				Date d1 = users[c]->getDateCreated();
				int credits = users[c]->getCredits() * 100;
				myfile << "ACCOUNT-ADMIN" << endl;
				myfile << d1.returnDate() << endl;
				myfile << users[c]->GetUsername() << endl;
				myfile << users[c]->GetPassword() << endl;
				myfile << credits << endl;
			}
			else
			{
					Date d1 = users[c]->getDateCreated();
					int credits = users[c]->getCredits() * 100;
					myfile << "ACCOUNT-PLAYER" << endl;
					myfile << d1.returnDate() << endl;
					myfile << users[c]->GetUsername() << endl;
					myfile << users[c]->GetPassword() << endl;
					myfile << credits << endl;
			}
		}
		for (int d = 0; d < libraryItems.length(); d++)
		{
			Date d2 = libraryItems[d]->returnDatePurchased();
			myfile << "LIBRARY-ITEM" << endl;
			myfile << libraryItems[d]->returnGame()->getID()<<endl;
			myfile << d2.returnDate()<< endl;
			myfile << libraryItems[d]->returnMinsPlayer() << endl;

		}
	}
}

void Application::setGameIndex(const int& index)
{
	this->gameIndex = index;
}


int Application::returnIndex()
{
	return gameIndex;
}

void Application::setGamesFound(const vector<int>& games)
{
	this->gamesFound = games;
}

vector<int> Application::returnGamesFound()const
{
	return gamesFound;
}





