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

std::string Utils::convertToUpper(std::string text)
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

float Utils::convertToFloat(int amount)
{

	return 	amount / 100;
}

bool Utils::startsWith(string fullText, string toSearch)
{
	string cFullText = Utils::convertToUpper(fullText);
	if (cFullText.find(toSearch) != std::string::npos) {
		return true;
	}
	return false;
}


