#ifndef DoubleWords_H
#define DoubleWords_H
#include "decorator.h"
#include "textprocess.h"
#include <string>
using std::string;

class DoubleWords: public Decorator
{
public:
	virtual ~DoubleWords();
	DoubleWords(TextProcessor&);
	virtual string getWord();
private:
	string str;
};

#endif
