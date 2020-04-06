#include "Date.h"

Date::Date(int day, int month, int year)
{
	bool dateValid = checkDate(day, month, year);
	if (dateValid == true)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
}

Date::Date(int day, string month, int year)
{
	int monthInt = convertMonth(month);
	bool dateValid = checkDate(day, monthInt, year);
	if (dateValid == true)
	{
		this->day = day;
		this->month = monthInt;
		this->year = year;
	}
}

bool Date::checkDate(int day, int month, int year)
{
	bool dateCheck = false;

	if (day != NULL)
		if (month != NULL)
			if (year != NULL)
			{
				if (day <= 31)
					if (month <= 12)
						dateCheck = true;
			}
	return dateCheck;
}

int Date::convertMonth(string month)
{
	if (month != "")
	{
		if (month == Utils::convertToUpper("January"))
			return 1;
		if (month == Utils::convertToUpper("February"))
			return 2;
		if (month == Utils::convertToUpper("March"))
			return 3;
		if (month == Utils::convertToUpper("April"))
			return 4;
		if (month == Utils::convertToUpper("May"))
			return 5;
		if (month == Utils::convertToUpper("June"))
			return 6;
		if (month == Utils::convertToUpper("July"))
			return 7;
		if (month == Utils::convertToUpper("August"))
			return 8;
		if (month == Utils::convertToUpper("September"))
			return 9;
		if (month == Utils::convertToUpper("October"))
			return 10;
		if (month == Utils::convertToUpper("November"))
			return 11;
		if (month == Utils::convertToUpper("December"))
			return 12;
	}
}

const std::string Date::currentDateTime()
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}

string Date::returnDate()const
{
	return to_string(this->year) + "-" + to_string(this->month) + "-" + to_string(this->day);
}
