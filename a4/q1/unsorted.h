#ifndef UnsortedList_H
#define UnsortedList_H
#include "list.h"

class UnsortedList : public List
{
public:
	UnsortedList(); // ctor
	UnsortedList(const UnsortedList&); // copy cotr
	virtual ~UnsortedList(); // destructor
	UnsortedList& operator = (const UnsortedList&); // overloading assignment operator.
};

#endif
