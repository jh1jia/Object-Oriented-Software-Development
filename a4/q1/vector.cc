#include "vector.h"
#include <iostream>
using namespace std;

Vector::Vector():List(),array(NULL),capacity(0)
{}

Vector::Vector(const Vector& vec): List(vec), capacity(vec.capacity)
{
	if(vec.array == NULL)
	{
		array = NULL;
	}
	else
	{
		array = new int[capacity];
		for(int i = 0; i < countsize; i++)
		{
			array[i] = vec.array[i];
		}
	}
}

Vector::~Vector()
{
	delete [] array;
}

Vector& Vector::operator=(const Vector& vec)
{
	if(this == &vec)
	{
		return *this;
	}

	List::operator=(vec);
	capacity = vec.capacity;
	delete [] array;
	array = new int[capacity];

	for(int i = 0; i < countsize; i++)
	{
		array[i] = vec.array[i];
	}
	return *this;
}

int Vector::at(int index) const
{
	return array[index];
}

int Vector::first() const
{
	return *array;
}

int Vector::last() const
{
	return array[countsize - 1];
}

void Vector::add(int num)
{
	if(capacity == 0)
	{
		array = new int[5];
		capacity = 5;
	}
	// check if the array is full, if so then double the capacity of the array.
	if(countsize == capacity) 
	{
		int* resize = new int[capacity * 2]; // new array
		for(int i = 0; i < countsize; i++)
		{
			resize[i] = array[i]; // copy element from old array to new array.
		}
		delete [] array; // free the old array.
		array = resize;
		capacity *= 2;
	}
	array[countsize] = num;
	countsize++;
}

int Vector::find(int num) const
{
	for(int i = 0; i < countsize; i++)
	{
		if(array[i] == num)
		{
			return i;
		}
	}
	return -1;
}

bool Vector::remove(int num)
{
	int i;
	for(i = 0; i < countsize; i++)
	{
		if(array[i] == num)
		{
			for(; i < countsize - 1; i++)
			{
				array[i] = array[i+1]; // immediately fills the gap that is created.
			}
			countsize--;
			return true;
		}
	}	
	return false;
}
