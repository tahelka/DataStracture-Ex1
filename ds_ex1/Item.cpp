#include "Item.h"

// getters:

Node* Item::getCurrNode()		const
{
	return currNode;
}

int Item::getDistance()			const
{
	return distance;
}

int Item::getLine()				const
{
	return line;
}

// setters:

void Item::setCurrNode(Node* node)
{
	currNode = node;
}


void Item::setDistance(int _distance)
{
	distance = _distance;
}

void Item::setLine(int _line)
{
	line = _line;
}
