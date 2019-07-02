#ifndef List_H
#define List_H
#include "node.h"

class List
{
public:
	List();  // ctor
	List(const List&); // copy ctor
	virtual ~List(); // destrucor
	List& operator = (const List&); // overloading assignment operator
	virtual int at(int index) const; // returns the int stored at given position index.
	virtual int first() const; // returns the first element in the list.
	virtual int last() const; // returns the last element in the list.
	virtual void add(int num); // adds a number to a unsorted list.
	// find(int) searches through the list for num. If found, it returns the index of 
	// the first occurrence of num. Otherwise, it returns -1.
	virtual int find(int num) const;
	// remove(num) searches through the list for num. If found, it removes the first 
	// occurrence and returns true. Otherwise, it returns false.
	virtual bool remove(int num);
	int size() const; // returns the number of elements currently in the list.
	NodePtr getHead() const; // returns head
protected:
	int countsize; // the number of elements currently in the list or array.
	NodePtr head; // a pointer which pointed to the first Node in the linked list.
};

#endif
