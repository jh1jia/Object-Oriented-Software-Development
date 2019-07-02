#include "list.h"
#include <iostream>
using namespace std;

List::List():countsize(0), head(NULL)
{}

List::List(const List& lt)
:countsize(lt.countsize), head(lt.head ? new Node(*(lt.head)) : NULL)
{}

List::~List()
{
	delete head;
}

List& List::operator = (const List& lt)
{
	if(this == &lt)
	{
		return *this;
	}

	countsize = lt.countsize;
	delete head;

	if(lt.head == NULL)
	{
		head = NULL;
	}
	else
	{
		head = new Node(*(lt.head));
	}
	
	return *this;
	
}

NodePtr List::getHead() const
{
	return head; // a pointer which pointed to the first Node in the linked list.
}

// add(num) inserts elements into an UnsortedList at the end of the linked list
void List::add(int num)
{
	countsize++;
	NodePtr newnode = new Node(num);
	if(head == NULL)
	{
		head = newnode;
		return;
	}
	NodePtr backup = head;
	while(backup->getnext() != NULL)
	{
		backup = backup->getnext();
	}
	backup->setnext(newnode);
}


int List::at(int index) const
{
	NodePtr backup = head;
	while(index != 0)
	{
		backup = backup->getnext();
		index--;
	}
	return backup->getnum();
}

int List::first() const
{
	return head->getnum();
}

int List::last() const
{
	NodePtr backup = head;
	while(backup->getnext() != NULL) // find the last Node in the linked list.
	{
		backup = backup->getnext();
	}
	return backup->getnum();
}

int List::size() const
{
	return countsize;
}

int List::find(int num) const
{
	int index = 0;
	NodePtr backup = head;
	while(backup != NULL)
	{
		if(backup->getnum() == num)
		{
			return index;
		}
		backup = backup->getnext();
		index++;
	}
	return -1;
}

bool List::remove(int num)
{
	if(head == NULL)
	{
		return false;
	}

	NodePtr backup = head;
	NodePtr tracknext = backup->getnext();

	if(head->getnum() == num)
	{
		head->setnext(NULL);
		delete head;
		head = tracknext;
		countsize--;
		return true;
	}
	while(tracknext != NULL)
	{
		if(tracknext->getnum() == num)
		{
			backup->setnext(tracknext->getnext());
			tracknext->setnext(NULL);
			delete tracknext;
			countsize--;
			return true;
		}
		backup = tracknext;
		tracknext = tracknext->getnext();
	}
	return false;
}
