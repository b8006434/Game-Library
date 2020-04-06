#include "userProfile.h"

userProfile::userProfile(const std::string& title, Application * app) : Menu(title, app)
{
	Paint();
}

void userProfile::OutputOptions()
{
	const string addUsr = "Add an user";
	const string removeUsr = "Delete an User";
	string credits = Utils::prd(currentUser->getCredits(),2);
	Line("CREDITS: "+credits);
	Line();
	Line();
	Option('f', "Buy 10 credits");
	Line();
	Line();
	for (int i = 0; i < library.size(); i++)
	{
		// adding 1 so the display is nicer for the user
		game1 = library.at(i)->returnGame();
		string minsPlayed = Utils::convertMinsToHours(library[i]->returnMinsPlayer());
		string gameToShow = game1->GetName() + "(" + minsPlayed + ")";
		Option(i + 1, gameToShow);
	}
	if (currentUser->returnType() =="admin")
	{
		Line();
		Option('q', addUsr);
		Option('w', removeUsr);
	}
	Line();
	Option('E', "Sort library by name");
	Option('R', "Sort library by date purchased");
	Line();
	Option('T', "Rate games");
}

bool userProfile::HandleChoice(char choice)
{
	// since we are using numbers here we shift the char down by '1'
// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';
	if (currentUser->returnType() == "admin")
	{
		if (choice == 'Q')
		{
			string username = Question("Please type in the new user's username");
			string password = Question("Please type in the new user's password");
			Date d(1, 2, 2019);
			string currentDate = Date::currentDateTime();
			Player* newPlayer = new Player(username, password, d);
			newPlayer->setDateCreated(currentDate);
			app->addUser(newPlayer);
		}
		if (choice == 'W')
		{
			string user = Question("Please type in the user's name to be deleted");
			app->removeUser(user);
		}
	}


	if (choice == 'F')
		currentUser->addCredits(10.00);

	if (choice == 'E')
		sortByGameName();
	if (choice == 'R')
		sortByDatePurchased();
	if (choice == 'T')
		ratingMenu("RATE GAMES", app);
	if (index >= 0 && index < library.size())
	{
		library[index]->addMinsPlayed(Utils::randomNumber(10, 60));
	}
	return false;
}

bool userProfile::compByName(LibraryItem* a, LibraryItem* b)
{
	return a->returnGame()->GetName()< b->returnGame()->GetName();
}

bool userProfile::compByDate(LibraryItem * a, LibraryItem * b)
{
	return a->returnDatePurchased().returnDate() > b->returnDatePurchased().returnDate();
}

void userProfile::sortByGameName()
{
	sort(library.begin(), library.end(),userProfile::compByName);
}

void userProfile::sortByDatePurchased()
{
	sort(library.begin(), library.end(), userProfile::compByDate);
}


