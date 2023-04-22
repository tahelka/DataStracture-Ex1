#ifndef __STACK_H
#define __STACK_H

#include <vector>
#include "Item.h"

class Stack
{
	std::vector<Item> stack;

public:

	// methods:

	bool isEmpty()	const;
	void makeEmpty();
	void push(Item item);
	Item pop();
};

#endif
