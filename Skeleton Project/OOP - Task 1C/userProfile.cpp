#include "userProfile.h"

userProfile::userProfile(const std::string& title, Application * app) : Menu(title, app)
{
	Paint();
}

void userProfile::OutputOptions()
{
	const string addUsr = "Add an user";
	const string removeUsr = "Delete an User";
	float credits = currentUser->getCredits();
	Line("CREDITS: "+to_string(credits));
	Line();
	Line();
	Option('f', "Buy 10 credits");
	Line();
	Line();
	for (int i = 0; i < library.length(); i++)
	{
		// adding 1 so the display is nicer for the user
		game = library[i]->returnGame();
		Option(i + 1, game->GetName());
	}
	if (currentUser->returnType() =="admin")
	{
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		Option('q', addUsr);
		Option('w', removeUsr);
	}
}

bool userProfile::HandleChoice(char choice)
{
	// since we are using numbers here we shift the char down by '1'
// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';
	if (choice == 'F')
		currentUser->addCredits(10.00);


	if (index >= 0 && index < library.length())
	{

	}
	return false;
}
