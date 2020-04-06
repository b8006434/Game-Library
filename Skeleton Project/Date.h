#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include "Utils.h"




using namespace std;

class Date
{
public:
	Date(int day, int month, int year);
	Date(int day, string month, int year);
	static const std::string currentDateTime();
	string returnDate()const;
private:
	int day;
	int month;
	int year;
	int convertMonth(string month);
	bool checkDate(int day, int month, int year);
};

