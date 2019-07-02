#ifndef adjacency_H
#define adjacency_H
#include "user.h"
#include <iostream>
using std::istream;

const int MAXUSERS=100;
struct AdjacencyList { 

   User *users[MAXUSERS];//array of User pointers

   //for descriptions of the following refer to
   //commands in the assignment specifications
   void addUser(int);
   void removeUser(int);
   void follow(int, int); 
   void unfollow(int, int); 
   void list(int id, int level) const;
   void printAll() const;
   void print(int) const;

   //add helper methods here
   int count; // count how many users in the graph
   AdjacencyList(); // constructor
   bool checkUser(int) const; // check a user already in the graph or ont.
   void removehelp(int user, UserPtr& first);
   UserPtr search(UserPtr head, int target) const; // find a user in a UserList or return NULL.
   void listhelp(int array [], int& index, int num, int aim) const; 
   void myread(istream&); // read commands from standard input or a file.
   ~AdjacencyList(); // destructor.
   AdjacencyList(const AdjacencyList&); // copy constructor
   AdjacencyList& operator=(const AdjacencyList&); // assignment operator
};



#endif