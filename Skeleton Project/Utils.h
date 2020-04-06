#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib> 
#include <ctime> 
#include <sstream>
using namespace std;
class Utils
{
  public:
    static std::string getLineFromUser();
    static char getCharFromUser();
	static std::string convertToUpper(string text);
	static vector<string> split(string s,string delimiter);
	static float convertToFloat(const int& amount);
	static bool startsWith(string fullText, string toSearch);
	static int randomNumber(const int& from,const int& to);
	static string convertMinsToHours(const int& minutes);
	static string prd(const double x, const int decDigits);

    // TODO: 2 versions of ToUpper
};