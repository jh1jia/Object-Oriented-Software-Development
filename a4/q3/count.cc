#include "count.h"
#include <sstream>
#include <string>
#include <iostream>
using namespace std;


Count::~Count()
{}

Count::Count(TextProcessor& tpr, char ch): Decorator(tpr), c(ch), charCount(0)
{}

string Count::getWord()
{
	string str = tp.getWord();
	int length = str.length();
	stringstream ss(""); // empty stringstream ss
	for(int i = 0; i < length; i++)
	{
		if(str[i] == c) // check if the char is the char that needs to be counted
		{
			charCount++; // count occurrence of a char c
			ss << charCount; // convert charCount into string using stringstream
			continue;
		}
		ss << str[i];
	}
	return ss.str(); 
}
