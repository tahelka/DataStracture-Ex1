#include "CountryStructure.h"


CountryStructure::CountryStructure(int numOfTowns, std::vector<Road>& roads)
{
	this->numOfTowns = numOfTowns;
	countryStructure.resize(numOfTowns);
	setCountryStructure(roads);
}

// getters:

std::vector<List>& CountryStructure::getCountryStructure()
{
	return countryStructure;
}

int CountryStructure::getNumOfTowns()						const
{
	return numOfTowns;
}

// setters:
void CountryStructure::setCountryStructure(std::vector<Road>& roads)
{
	
	int numOfRoads = roads.size();
	int id1, id2;

	for (int i = 0; i < numOfRoads; i++)
	{
		id1 = roads.at(i).getFirstTownId();
		id2 = roads.at(i).getSecTownId();
		
		(countryStructure.at(id1)).insertDataToList(id2, nullptr);
		(countryStructure.at(id2)).insertDataToList(id1, nullptr);
	}
}

void CountryStructure::setNumOfTowns(int num)
{
	numOfTowns = num;
}

// methods:

int CountryStructure::townDistanceRecursive(int currTown, int destTown, Color& colors)
{
	int distance;

	colors.makeTownBlack(currTown);

	if (currTown == destTown)
		return 0;

	Node* currNeigborTown = countryStructure.at(currTown).getHead();

	while (currNeigborTown != nullptr)
	{
		if (colors.isTownWhite(currNeigborTown->getTownID()))
		{
			distance = townDistanceRecursive(currNeigborTown->getTownID(), destTown, colors);
			if (distance != DEAD_ROAD)
			{
				return distance + 1;
			}
		}
		currNeigborTown = currNeigborTown->getNext();
	}

	return DEAD_ROAD;
}


int CountryStructure::townDistanceIterative(int currTown, int destTown, Color& colors)
{
	int returnDistance = DEAD_ROAD;
	Stack stack;

	if (currTown == destTown)
	{
		returnDistance++;
	}
	else if (!countryStructure.at(currTown).isEmpty())
	{
		colors.makeTownBlack(currTown);
		Item curr(countryStructure.at(currTown).getHead(), DEAD_ROAD + 1, START);
		int returnFromRecursion = 0;

		do {

			if (returnFromRecursion)
			{
				curr = stack.pop();
			}

			if (curr.getLine() == START)
			{
				if (curr.getCurrNode()->getTownID() == destTown)
				{
					returnFromRecursion = 1;
					curr.setDistance(curr.getDistance() + 1);
					returnDistance = curr.getDistance();
					stack.makeEmpty();

				}
				else if (!colors.isTownWhite(curr.getCurrNode()->getTownID()) || countryStructure.at(curr.getCurrNode()->getTownID()).isEmpty())
				{

					if (curr.getCurrNode()->getNext() == nullptr)
					{
						returnFromRecursion = 1;
					}
					else
					{
						curr.setCurrNode(curr.getCurrNode()->getNext());
					}
				}
				else // town is white and has a not empty list
				{
					colors.makeTownBlack(curr.getCurrNode()->getTownID());
					curr.setLine(AFTER_FIRST);
					curr.setDistance(curr.getDistance() + 1);
					stack.push(curr);

					curr.setCurrNode(countryStructure.at(curr.getCurrNode()->getTownID()).getHead());
					curr.setLine(START);

				}

			}
			else if (curr.getLine() == AFTER_FIRST)
			{
				if (curr.getCurrNode()->getNext() != nullptr)
				{
					curr.setCurrNode(curr.getCurrNode()->getNext());
					curr.setLine(START);
					curr.setDistance(curr.getDistance() - 1);
					returnFromRecursion = 0;
				}

			}

		} while (!(stack.isEmpty()) || returnFromRecursion == 0);
	}

	return returnDistance;

}
