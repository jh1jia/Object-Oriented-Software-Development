#include "decorator.h"
#include <iostream>
using namespace std;


Decorator::~Decorator() 
{
	delete &tp;
}

Decorator::Decorator(TextProcessor& tpr): tp(tpr)
{}

void Decorator::setSource(istream* inp)
{
	tp.setSource(inp);
}

bool Decorator::fail() const
{
	return tp.fail();
}

