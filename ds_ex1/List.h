#ifndef _LIST_H
#define _LIST_H

#include "Node.h"

#define DUMMY_HEAD_ID 0

class List
{
	Node* head;
	Node* tail;

public:
	// Consturctor
	List();
	// Destructor
	~List();

	// getters:
	Node* getHead()			const;
	Node* getTail()			const;

	// setters:
	void setHead(Node* _head);
	void setTail(Node* _tail);

	// Methods

	// this function checks if list is empty
	bool isEmpty()		const;
	//this function makes list empty
	void makeEmpty();
	// this function creates a new node for list with given data
	void insertDataToList(int id, Node* next);
	// this function adds node to list in ascending order
	void insertNodeToList(Node* node);
	// this function finds the right node to add a new node after it so the ascending order will not get ruined.
	Node* findNodeToAddAfter(int id)		const;
};

#endif