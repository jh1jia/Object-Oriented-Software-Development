#include "unsorted.h"
#include <iostream>
using namespace std;

UnsortedList::UnsortedList():List()
{}

UnsortedList::UnsortedList(const UnsortedList& object):List(object)
{}

UnsortedList::~UnsortedList()
{}

UnsortedList& UnsortedList::operator = (const UnsortedList& object)
{
	List::operator=(object); // using assignment operator from base class List.
	return *this;
}


