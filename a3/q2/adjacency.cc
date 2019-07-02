#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "adjacency.h"
using namespace std;

// constructor
AdjacencyList::AdjacencyList():count(0)
{
	for(int i = 0; i < MAXUSERS; i++)
	{
		users[i] = NULL;
	}
}

// copy constructor
AdjacencyList::AdjacencyList(const AdjacencyList& adj):count(adj.count)
{
	for(int i = 0; i < MAXUSERS; i++)
	{
		if(adj.users[i] == NULL)
		{
			users[i] = NULL;
		}
		else
		{
			users[i] = new User(*(adj.users[i]));
		}
	}
}

// overloading assignment operator
AdjacencyList& AdjacencyList::operator=(const AdjacencyList& adj)
{
	if(this == &adj)
	{
		return *this;
	}
	else
	{
		for(int i = 0; i < MAXUSERS; i++)
		{
			if(adj.users[i] == NULL)
			{
				users[i] = NULL;
			}
			else
			{
				users[i] = new User(*(adj.users[i]));
			}
		}
		return *this;
	}
}

// destructor
AdjacencyList::~AdjacencyList()
{
	for(int i = 0; i < MAXUSERS; i++)
	{
		delete users[i];
	}
}

// find a user in a UserList or return NULL.
UserPtr AdjacencyList::search(UserPtr head, int target) const
{
	UserPtr here = head;
	if(here == NULL)
	{
		return NULL;
	}
	else
	{
		while(here->id != target && here->nextFollow != NULL)
		{
			here = here->nextFollow;
		}
		if(here->id == target)
			// return a pointer which points to the target user in the UserList.
			return here; 
		else
			// did not find the target user, return NULL
			return NULL;
	}
}

// check a user already in the graph or ont.
bool AdjacencyList::checkUser(int num) const
{
	for(int i = 0; i < count; i++)
	{
		if(users[i]->id == num)
		{
			return true;
		}
	}
	return false;
}

void AdjacencyList::addUser(int user)
{
	if(checkUser(user))
	{
		cout << "User " << user << " already has an account" << endl;
		return;
	}
	users[count] = new User(user, NULL);
	count++;
	cout << "User " << user << " has joined the social network" << endl;
}

// A help method to remove the given user from every follow list.
void AdjacencyList::removehelp(int user, UserPtr& first)
{
	UserPtr backup = first;
	UserPtr next = first->nextFollow;

	if(first->id == user)
	{
		first->nextFollow = NULL;
		delete first;
		first = next;
		return;
	}
	while(next != NULL)
	{
		if (next->id == user)
		{
			backup->nextFollow = next->nextFollow;
			next->nextFollow = NULL;
			delete next;
			return;
		}
		else 
		{
			backup = next;
			next = next->nextFollow;
		}
	}
}

// remove a user with the UserID from the graph
void AdjacencyList::removeUser(int user)
{
	if(! checkUser(user))
	{
		cout << "User " << user << " does not have an account" << endl;
		return;
	}
	for(int i = 0; i < count; i++)
	{
		if(users[i]->id == user)
		{
			delete users[i];
			cout << "User " << user << " has deleted their account" << endl;
			for(int j = i; j < count-1; j++)
			{
				users[j] = users[j+1];
			}
			users[count-1] = NULL;
			count--;
			i--;
		}
		else if(users[i]->nextFollow == NULL) continue;
		else
		{
			removehelp(user,users[i]->nextFollow);
		}
	}


}

// let User a follow User b. 
void AdjacencyList::follow(int a, int b)
{	
	if(! checkUser(a))
	{
		cout << "User " << a << " does not have an account" << endl;
		return;
	}
	if(! checkUser(b))
	{
		cout << "User " << b << " does not have an account" << endl;
		return;
	}
	if(a == b)
	{
		cout << "Cannot follow yourself" << endl;
		return;
	}	
	for(int i = 0; i < count; i++)
	{
		if(users[i]->id == a)
		{
			if(search(users[i], b) != NULL)
			{
				cout << "User " << a << " is already following " << b << endl;
				return;
			}
			UserPtr backup = users[i]->nextFollow;
			if(backup == NULL)
			{
				users[i]->nextFollow = new User(b,NULL);
				cout << "User " << a << " is now following " << b << endl;
				return;
			}
			while(backup->nextFollow != NULL)
			{
				backup = backup->nextFollow;
			}
			backup->nextFollow = new User(b,NULL);
			cout << "User " << a << " is now following " << b << endl;
		}
	}
}

// let User a unfollow User b. 
void AdjacencyList::unfollow(int a, int b)
{
	if(! checkUser(a))
	{
		cout << "User " << a << " does not have an account" << endl;
		return;
	}
	if(! checkUser(b))
	{
		cout << "User " << b << " does not have an account" << endl;
		return;
	}
	if(a == b)
	{
		cout << "Cannot follow yourself therefore cannot unfollow yourself" << endl;
		return;
	}
	for(int i = 0; i < count; i++)
	{
		if(users[i]->id == a)
		{
			if(search(users[i], b) == NULL)
			{
				cout << "User " << a << " was not following " << b << endl;
				return;
			}
			removehelp(b,users[i]->nextFollow);
			cout << "User " << a << " is no longer following " << b << endl;
			return;
		}
	}
}

// print the users that user a is following.
void AdjacencyList::print(int a) const
{
	if(! checkUser(a))
	{
		cout << "User " << a << " does not have an account" << endl;
		return;
	}
	for(int i = 0; i < count; i++)
	{
		if(users[i]->id == a)
		{
			if(users[i]->nextFollow == NULL)
			{
				cout << "User " << a << " is following no one" << endl;
				return;
			}
			cout << "User " << a << " is following ";
			UserPtr backup = users[i]->nextFollow;
			while(backup != NULL)
			{
				if(backup->nextFollow == NULL)
				{
					cout << backup->id << endl;
				}
				else
				{
					cout << backup->id << ",";
				}
				backup = backup->nextFollow;
			}
		}
	}
}

// calls print UserID for all users
void AdjacencyList::printAll() const
{
	for(int i = 0; i < count; i++)
	{
		print(users[i]->id);
	}
}



void AdjacencyList::listhelp(int array[], int& index, int num, int aim) const
{
	bool flag = true;

	for(int i = 0; i < count; i++)
	{
		if(users[i]->id == num)
		{
			UserPtr backup = users[i]->nextFollow;
			while(backup != NULL && backup->id != aim)
			{
				for(int h = 0; h < index; h++)
				{
					if(array[h] == backup->id)
					{
						flag = false;
						break;
					}
				}
				if(flag)
				{
					array[index] = backup->id;
					index++;
				}
				backup = backup->nextFollow;
				flag = true;
			}
			break;
		}
	}
}

// prints the number of unique users reachable from UserID through
// up to n levels of follow relationships
void AdjacencyList::list(int id, int level) const
{
	if(! checkUser(id))
	{
		cout << "User " << id << " does not have an account" << endl;
		return;
	}
    // store reachable unique users in an array.
	int myarray[MAXUSERS]; 
	// count how many reachable unique users in myarray.
	int myindex = 0;

	// help find reachable users in the follow relationships list.
	listhelp(myarray, myindex, id, id);

	while (level > 1)		
	{
		int dex = myindex;
		for(int i = 0; i < dex; i++) // search through myarray.
		{
			listhelp(myarray, myindex, myarray[i], id);
		}
		level--;
	}

	cout << myindex << endl;
}


// read commands from standard input or a file.
void AdjacencyList::myread(istream& in)
{
	string str;
	int arg1, arg2;

	while(in >> str)
	{
		if(str == "include")
		{
			in >> str;
			ifstream filein(str.c_str());
			myread(filein);
			filein.close();
			continue;
		}
		if(str == "+")
		{
			in >> arg1;
			addUser(arg1);
			continue;
		}
		if(str == "-")
		{
			in >> arg1;
			removeUser(arg1);
			continue;
		}
		if(str == "follow")
		{
			in >> arg1;
			in >> arg2;
			follow(arg1,arg2);
			continue;
		}
		if(str == "unfollow")
		{
			in >> arg1;
			in >> arg2;
			unfollow(arg1,arg2);
			continue;
		}
		if(str == "print")
		{
			in >> arg1;
			print(arg1);
			continue;
		}
		if(str == "printall")
		{
			printAll();
			continue;
		}
		if(str == "list")
		{
			in >> arg1;
			in >> arg2;
			list(arg1,arg2);
			continue;
		}
		if(str == "quit")
		{
			in.clear();
			return;
		}
	}

	in.clear();
	return;
}

