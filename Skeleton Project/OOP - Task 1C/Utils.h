#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Utils
{
  public:
    static std::string getLineFromUser();
    static char getCharFromUser();
	static std::string convertToUpper(std::string text);
	static vector<string> split(string s, string delimiter);
	static float convertToFloat(int amount);
    // TODO: 2 versions of ToUpper
};