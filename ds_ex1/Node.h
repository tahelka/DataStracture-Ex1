#ifndef _NODE_H
#define _NODE_H

class Node
{
	int id;
	Node* next;

public:
	// Constructors
	Node(int _id, Node* _next = nullptr) : id(_id), next(_next) {}

	// getters:
	Node* getNext() const;
	int getTownID() const;

	// setters:
	void setNext(Node* _next);
	void setTownID(int id);

};


#endif