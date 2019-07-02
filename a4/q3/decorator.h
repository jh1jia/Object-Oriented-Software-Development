#ifndef Decorator_H
#define Decorator_H
#include "textprocess.h"
#include <iostream>
using std::istream;

class Decorator: public TextProcessor
{
public:
	Decorator(TextProcessor&);
	virtual ~Decorator();
	// in order to maximize the reuse of the code and reduce
	// unnecessary repetition. I implementated setSource(istream*) and
	// fail() here.
	virtual void setSource(istream*);
	virtual bool fail() const;
protected:
	TextProcessor& tp;
};

#endif
