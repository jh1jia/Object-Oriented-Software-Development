#ifndef Node_H
#define Node_H

class Node
{
public:
	Node(int i); // ctor 
	Node(int i, Node* nextnode); // ctor
	Node(const Node&); // copy ctor
	virtual ~Node(); // destructor
	Node& operator = (const Node&); // overloading assignment operator
	int getnum() const;
	Node* getnext() const;
	void setnext(Node*);
	void setnum(int);
private:
	int num;
	Node* next;
};
typedef Node* NodePtr;

#endif
