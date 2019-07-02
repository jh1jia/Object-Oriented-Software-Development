#ifndef Count_H
#define Count_H
#include "decorator.h"
#include "textprocess.h"
#include <string>
using std::string;

class Count: public Decorator
{
public:
	virtual ~Count();
	Count(TextProcessor&, char);
    // getWord() returns the string that first occurrence of the 
    // character c in the string is replaced with 1. The second is 
    // replaced with 2, ... the tenth is replaced with 10, and so on.
	virtual string getWord();
private:
	char c;
	int charCount; // count occurrence of a char c
};

#endif
