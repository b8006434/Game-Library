#include "Application.h"
#include "MainMenu.h"

void main()
{
	// TODO: Remove call to dummy data, instead use Load and Save
	//createHardcodedTestData();

	Application app;
	app.Load();
	MainMenu("MAIN MENU", &app);
	app.Save();

	//app.Save();
}