#include "doublewords.h"
#include <string>
#include <iostream>
using namespace std;


DoubleWords::~DoubleWords()
{}

DoubleWords::DoubleWords(TextProcessor& tpr): Decorator(tpr), str("")
{}

string DoubleWords::getWord()
{
	// in order to double the string, we need to return every string stored
	// in str twice.
	if(str != "") // check if str is empty
	{
		// str is not empty, so in order to double the word, we must to use
		// the word stored in str again.
		string temp(str); 

		str = ""; // empty the str for next word waiting to be doubled.
		
		return temp;
	}
	str = tp.getWord();
	return str;
}
