#include "dropfirst.h"
#include <iostream>
#include <string>
using namespace std;


DropFirst::DropFirst(TextProcessor& tpr, int n): Decorator(tpr), dropNum(n)
{}

string DropFirst::getWord()
{
	string str(tp.getWord());

	// find words that is long enough appears after dropping n chars
	while((!(fail())) && str.length() <= dropNum) 
	{
		str = tp.getWord();
	}
	if(!(fail()))
	{
		// taking the substring of the string, drop first dropNum chars.
		str = str.substr(dropNum, str.length() - dropNum);
	}
	return str;
}

DropFirst::~DropFirst()
{}

