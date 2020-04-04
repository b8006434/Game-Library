#pragma once

#include "Utils.h"
#include "Application.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Menu
{
public:
	Menu(const std::string& title, Application* app);
	void Paint();
	virtual void OutputOptions() = 0;
	virtual bool HandleChoice(char) = 0;

private:
	string title;
	void Header();
	void Footer();

protected:
	Application* app;
	void Line();										// output blank line
	void Line(const std::string& text);					// output message
	void Option(int id, const std::string& option);		// output menu option
	void Option(char id, const std::string& option);	// output menu option
	string Question(const std::string& question);	// output question and return the user's input
	void BlockingMessage(const std::string& message);	// output message and wait for the use to press enter
	
	

};

