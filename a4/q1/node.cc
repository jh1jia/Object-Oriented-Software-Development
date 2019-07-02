#include "node.h"
#include <iostream>
using namespace std;

Node::Node(int i, Node* nextnode)
: num(i), next(nextnode) {}

Node::Node(int i)
: num(i), next(NULL) {}

Node::Node(const Node& n)
:num(n.num), next(n.next ? new Node(*(n.next)) : NULL) {}

Node::~Node()
{
	delete next;
}

int Node::getnum() const
{
	return num;
}

Node* Node::getnext() const
{
	return next;
}

void Node::setnext(Node* n)
{
	next = n;
}

void Node::setnum(int n)
{
	num = n;
}

// overloading assignment operator
Node& Node::operator = (const Node& n)
{
	if(this == &n)
	{
		return *this;
	}

	num = n.num;
	delete next;

	if(n.next == NULL)
	{
		next == NULL;
	}
	else
	{
		next = new Node(*(n.next));
	}
	return *this;
}
