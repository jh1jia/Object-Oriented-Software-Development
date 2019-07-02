#include "allcaps.h"
#include <string>
#include <iostream>
using namespace std;

AllCaps::~AllCaps()
{}

AllCaps::AllCaps(TextProcessor& tpr): Decorator(tpr)
{}

string AllCaps::getWord()
{
	string str(tp.getWord());
	int length = str.length(); // string length

	for(int i = 0; i < length; i++)
	{
		if(str.at(i) >= 'a' && str.at(i) <= 'z') // check if the char is lower case.
		{
			str.at(i) = str.at(i) - 'a' + 'A'; // capitalize a char
		}
	}

	return str;
}
