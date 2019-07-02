#ifndef Vector_H
#define Vector_H
#include "list.h"

class Vector : public List
{
public:
	Vector(); // ctor
	Vector(const Vector&); // copy ctor
	virtual ~Vector(); // destructor
	Vector& operator = (const Vector&); // overloading assignment operator.
	virtual int at(int index) const; // returns the int stored at the position index in the array.
	virtual int first() const; // returns the first element in the array.
	virtual int last() const; // returns the last element in the array.
	virtual void add(int num); // adds a number to the adjusted array.
	// searches through the array for num. If found, it returns the index of the 
	// first occurrence of num. Otherwise, it returns -1.
	virtual int find(int num) const;
	// searches through the array for num. If found, it removes the first occurrence
	// and returns true. Otherwise, it returns false.
	virtual bool remove(int num);
protected:
	int* array; // an array of int.
	int capacity; // array's capacity.
};

#endif
