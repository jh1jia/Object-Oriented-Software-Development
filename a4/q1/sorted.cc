#include "sorted.h"
#include <iostream>
using namespace std;

SortedList::SortedList():List()
{}

SortedList::SortedList(const SortedList& sl):List(sl)
{}

SortedList::~SortedList()
{}

SortedList& SortedList::operator = (const SortedList& sl)
{
	List::operator=(sl);
	return *this;
}

void SortedList::add(int num)
{
	countsize++;
	NodePtr newnode = new Node(num);
	if(head == NULL)
	{
		head = newnode;
		return;
	}
	if(num <= head->getnum())
	{
		newnode->setnext(head);
		head = newnode;
		return;
	}
	NodePtr backup = head;
	while(backup->getnext() != NULL)
	{
		if(num <= backup->getnext()->getnum())
		{
			newnode->setnext(backup->getnext());
			backup->setnext(newnode);
			return;
		}
		backup = backup->getnext();
	}
	backup->setnext(newnode);
	return;
}

