#include "istring.h"
#include <iostream>
#include <cstring>
#include <locale>
using namespace std;

iString::iString():length(0), capacity(0), chars(NULL)
{}

iString::iString(const char* str)
{
  int len = strlen(str);
  chars = new char [len + 1];
  strcpy(chars, str);
  length = len;
  capacity = len + 1;
}

  iString::iString(const iString& str)
:length(str.length), capacity(str.capacity)
{
  chars = new char [capacity];
  for(int i = 0; i < length; i++)
  {
	chars[i] = str.chars[i];
  }
  chars[length] = '\0';
}

iString::~iString()
{
  delete [] chars;
}

iString& iString:: operator = (const iString& str)
{
  if(capacity != str.capacity)
  {
	delete [] chars;
	chars = new char [str.capacity];
  }

  capacity = str.capacity;
  length = str.length;

  for(int i = 0; i < length; i++)
  {
	chars[i] = str.chars[i];
  }
  chars[length] = '\0';

  return *this;
}

ostream& operator << (ostream& outputStream, const iString& str)
{
  if(str.chars != NULL)
  {
	outputStream << str.chars;
  }

  return outputStream;
}

istream& operator >> (istream& inputStream, iString& str)
{
  int peek = inputStream.peek();
  char c;

  delete [] str.chars;
  str.chars = new char [5];
  str.length = 0;
  str.capacity = 5;

  while(isspace(peek))
  {
	inputStream.ignore();
	peek = inputStream.peek();
  }

  while(!(isspace(peek)))
  {
	inputStream.get(c);

	str.chars[str.length] = c;
	str.length++;

	if(str.length == str.capacity)
	{
	  char* resize = new char [str.capacity * 2];
	  int slen = str.length;
	  for(int i = 0; i < slen; i++)
	  {
		resize[i] = str.chars[i];
	  }
	  delete [] str.chars;
	  str.chars = resize;
	  str.capacity *= 2;
	}

	peek = inputStream.peek();
  }

  str.chars[str.length] = '\0';

  return inputStream;
}

const iString operator + (const iString& str1, const iString& str2)
{
  iString mystr;
  mystr.length = str1.length + str2.length;
  mystr.capacity = mystr.length + 1;
  mystr.chars = new char [mystr.capacity];
  if (str1.chars != NULL && str2.chars != NULL)
  {
	strcpy(mystr.chars, str1.chars);
	strcat(mystr.chars, str2.chars);
  }
  else if (str1.chars == NULL && str2.chars != NULL)
  {
	strcpy(mystr.chars, str2.chars);
  }
  else if (str2.chars == NULL && str1.chars != NULL)
  {
	strcpy(mystr.chars, str1.chars);
  }
  else
  {
	delete [] mystr.chars;
	mystr.chars = NULL;
	mystr.capacity = 0;
	mystr.length = 0;
  }

  return mystr;
}

const iString operator + (const iString& str1, const char* str2)
{
  iString mystr;
  if (str2 != NULL)
  {
	mystr.length = str1.length + strlen(str2);
  }
  else
  {
	mystr.length = str1.length;
  }
  mystr.capacity = mystr.length + 1;
  mystr.chars = new char [mystr.capacity];
  if(str1.chars != NULL && str2 != NULL)
  {
	strcpy(mystr.chars, str1.chars);
	strcat(mystr.chars, str2);
  }
  else if (str1.chars == NULL && str2 != NULL)
  {
	strcpy(mystr.chars, str2);
  }
  else if (str1.chars != NULL && str2 == NULL)
  {
	strcpy(mystr.chars, str1.chars);
  }
  else
  {
	delete [] mystr.chars;
	mystr.chars = NULL;
	mystr.capacity = 0;
	mystr.length = 0;
  }

  return mystr;
}

const iString operator ~ (const iString& str)
{
  iString mystr;
  mystr.length = 0;
  mystr.capacity = 5;
  mystr.chars = new char [5];
  int len = str.length;

  for(int i = 0; i < len; i++)
  {
	for(int j = 0; j <= i; j++)
	{
	  mystr.chars[mystr.length] = str.chars[j];
	  mystr.length++;

	  if(mystr.length == mystr.capacity)
	  {
		char* resize = new char [mystr.capacity * 2];
		int mylen = mystr.length;
		for(int i = 0; i < mylen; i++)
		{
		  resize[i] = mystr.chars[i];
		}
		delete [] mystr.chars;
		mystr.chars = resize;
		mystr.capacity *= 2;
	  }

	}
  }

  mystr.chars[mystr.length] = '\0';

  return mystr;
}
