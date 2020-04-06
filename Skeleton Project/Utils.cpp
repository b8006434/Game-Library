#include "Utils.h"

std::string Utils::getLineFromUser()
{
    std::string input;
    std::getline(std::cin, input);
    return convertToUpper(input);
}

char Utils::getCharFromUser()
{
    return toupper(getLineFromUser()[0]);
}

std::string Utils::convertToUpper(string text)
{
	if (text != "")
	{
		std::transform(text.begin(), text.end(), text.begin(), ::toupper);
	}
	return text;
}


std::vector<string> Utils::split(string s, string delimiter)
{
	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	string token;
	vector<string> res;

	while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
		token = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back(token);
	}

	res.push_back(s.substr(pos_start));
	return res;
}

float Utils::convertToFloat(const int& amount)
{

	return 	amount / 100;
}

bool Utils::startsWith( string fullText,  string toSearch)
{
	string cFullText = Utils::convertToUpper(fullText);
	if (cFullText.find(toSearch) != std::string::npos) {
		return true;
	}
	return false;
}

int Utils::randomNumber(const int& from,const int& to)
{
	srand(time(0));
	return rand() % (to - from + 1) + from;
	return 0;
}

string Utils::convertMinsToHours(const int& time)
{
	string toReturn;
	int hour = 0;
	float mins = 0;
	float totaltime = 0;
	if (time < 60)
		return to_string(time)+" minutes";
	
	if (time >= 60 && time < 300)
	{
		if (time >= 60 && time < 120)
		{
			hour = 1;
			mins = static_cast<float>(time-60) / 60;
			totaltime = hour + mins;
			return prd(totaltime, 1) + "hours";
		}
		if (time >= 120 && time < 180)
		{
			hour = 2;
			mins = static_cast<float>(time -120) / 60;
			totaltime = hour + mins;
			return prd(totaltime, 1) + "hours";
		}
		if (time >= 180 && time < 240)
		{
			hour = 3;
			mins = static_cast<float>(time-180) / 60;
			totaltime = hour + mins;
			return prd(totaltime, 1) + "hours";
		}
		if (time >= 240 && time < 300)
		{
			hour = 4;
			mins = static_cast<float>(time-240) / 60;
			totaltime = hour + mins;
			return prd(totaltime, 1) + "hours";
		}
	}
	
	if (time > 300)
	{
		return to_string(time / 60) + " hours";
	}

}

string Utils::prd(const double x, const int decDigits)
{
	stringstream ss;
	ss << fixed;
	ss.precision(decDigits); // set # places after decimal
	ss << x;
	return ss.str();
}






