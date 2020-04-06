#include "ratingMenu.h"

ratingMenu::ratingMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint();
}

void ratingMenu::OutputOptions()
{

	Line("LIKE GAMES");
	for (int a = 0; a <library.size(); a++)
	{
		if (library.at(a)->getGameRatedStatus() == false)
		Option(a + 1, library.at(a)->returnGame()->GetName());
	}
	Line();
	Line();
	Line("DISLIKE GAMES");
	char options = 'j';
	allOptions.push_back(options);
	for (int b = 0; b < library.size(); b++)
	{
		if (library.at(b)->getGameRatedStatus() == false)
		{
		Option(options, library.at(b)->returnGame()->GetName());
		options++;
	     }
		allOptions.push_back(options);
	}
	Line();
	Option('*', "Clear all ratings");


}

bool ratingMenu::HandleChoice(char choice)
{

	int index = choice - '1';
	if (choice == '*')
	{
		for (int y = 0; y < library.size(); y++)
		{
			library.at(y)->setGameRatedStatus(false);
			library.at(y)->returnGame()->clearRatings();
		}
	}

	if (isdigit(choice))
	{
		game1 = library.at(index)->returnGame();
		if (library.at(index)->getGameRatedStatus() == false)
		{
			game1->addLike();
			library.at(index)->setGameRatedStatus(true);
		}

	}
	else
	{
		for (int a = 0; a < allOptions.size(); a++)
		{
			if (choice == toupper(allOptions.at(a)))
			{
				game1 = library.at(a)->returnGame();
				if (library.at(a)->getGameRatedStatus() == false)
				{
					game1->addDisLike();
					library.at(a)->setGameRatedStatus(true);
				}
			}
		}
	}
	allOptions.clear();
	return false;
}
