#ifndef ISTRING_H
#define ISTRING_H
#include <iostream> 
using std::ostream;
using std::istream;

struct iString{

	char * chars;	        //dynamically allocated array of chars
	unsigned int length;    //# of characters currently in the chars array    
	unsigned int capacity;  //maximum # of characters that chars can store
	iString();              //constructor
	iString(const char *);  //one parameter constructor that takes c-style string
	iString(const iString&);//copy constructor
	~iString();             //destructor
	iString& operator=(const iString&); //copy assignment operator
};

// Add other declarations such as 
// input/ouput operators, operator+, operator~ here:

ostream& operator << (ostream& outputStream, const iString& str);
istream& operator >> (istream& inputStream, iString& str);
const iString operator + (const iString& str1, const iString& str2);
const iString operator + (const iString& str1, const char* str2);
const iString operator ~ (const iString& str);

#endif
