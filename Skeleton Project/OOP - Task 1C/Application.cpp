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

List<Account*> Application::getAccounts()
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
				addLibraryItems();
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
				return true;
			}
	}
	return false;
}

void Application::LogoutUser()
{
	currentUser = nullptr;
	currentAccount = nullptr;
}


void Application::addUsers()
{

	if (currentAccount != nullptr)
	{
		for (int a = 0; a < users.length(); a++)
		{
			currentAccount->addUser(users[a]);
		}
	}
}

void Application::addLibraryItems()
{
	for (int a = 0; a < users.length(); a++)
	{
		users[a]->addToLibrary(libraryItems[2]);
		users[a]->addToLibrary(libraryItems[5]);
		users[a]->addToLibrary(libraryItems[4]);
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
			gam1.setCost(stoi(line));
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
}

void Application::setGameIndex(int index)
{
	this->gameIndex = index;
}

int Application::returnIndex()
{
	return gameIndex;
}





