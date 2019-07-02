#ifndef user_H
#define user_H

struct User 
{ 
	const int id;
	User *nextFollow;
    //add helper methods here if needed
    User(int i, User* next);
    User(int i);
    User(const User&); // copy constructor
    ~User(); // destructor
    User& operator=(const User& u); // assignment operator

};

typedef User* UserPtr;

#endif