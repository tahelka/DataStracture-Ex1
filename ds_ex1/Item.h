#ifndef __ITEM_H
#define __ITEM_H

#include "Node.h"

class Item
{
	Node* currNode;
	int distance;
	int line;

public:

	Item(Node* _currNode, int _distance, int _line) : currNode(_currNode), distance(_distance), line(_line) {}

	// getters:
	Node* getCurrNode()		const;
	int getDistance()		const;
	int getLine()			const;

	// setters:
	void setCurrNode(Node* node);
	void setDistance(int _distance);
	void setLine(int _line);


};

#endif

