#ifndef AllCaps_H
#define AllCaps_H
#include "decorator.h"
#include "textprocess.h"
#include <string>
using std::string;

class AllCaps: public Decorator
{
public:
	virtual ~AllCaps();
	AllCaps(TextProcessor&); 
    // getWord() returns the string that all letters are presented in uppercase.
	virtual string getWord();
};

#endif
