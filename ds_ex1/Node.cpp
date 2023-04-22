#include "Node.h"


// getters:

Node* Node::getNext() const 
{
	return next;
}

int Node::getTownID() const
{
	return id;
}

// setters:

void Node::setNext(Node* _next)
{
	this->next = _next;
}

void Node::setTownID(int id)
{
	this->id = id;
}