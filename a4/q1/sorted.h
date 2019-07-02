#ifndef SortedList_H
#define SortedList_H
#include "list.h"

class SortedList : public List
{
public:
	SortedList(); // ctor 
	SortedList(const SortedList&); // copy ctor
	virtual ~SortedList(); // destrucor
	SortedList& operator = (const SortedList&); // overloading assignment operator.
	virtual void add(int num); // inserts elements into a SortedList in sorted order.
};

#endif

