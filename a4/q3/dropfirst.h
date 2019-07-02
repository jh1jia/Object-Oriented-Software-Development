#ifndef Dropfirst_H
#define Dropfirst_H
#include "decorator.h"
#include "textprocess.h"
#include <string>
using std::string;

class DropFirst: public Decorator
{
public:
	virtual string getWord(); // Drop the first n characters of each word.
	virtual ~DropFirst();
	// ctor which takes a reference tpr to textprocessor and an integer n.
	DropFirst(TextProcessor& tpr, int n);
private:
	int dropNum; // the number of characters need to be dropped.
};

#endif

