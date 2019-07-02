#include "user.h"
#include <iostream>

User::User(int i, User* next)
: id(i), nextFollow(next) {}

User::User(int i)
: id(i), nextFollow(NULL) {}

User::User(const User& u)
:id(u.id), nextFollow(u.nextFollow ? new User(*(u.nextFollow)) : NULL) {}

User::~User()
{
	delete nextFollow;
}

// overloading assignment operator
User& User::operator=(const User& u)
{
	if(this == &u)
	{
		return *this;
	}
	else
	{
		delete nextFollow;
		nextFollow = new User(*(u.nextFollow));
		return *this;
	}
}
