#include "Stack.h"


// methods:

bool Stack::isEmpty()	const
{
	return stack.empty();
}

void Stack::makeEmpty()
{
	stack.clear();
}

void Stack::push(Item item)
{
	stack.push_back(item);
}

Item Stack::pop()
{
	Item lastItem = stack.back();
	stack.pop_back();
	return lastItem;
}

