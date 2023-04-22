#include "Road.h"

// getters:

int Road::getFirstTownId()		const
{
	return firstTownID;
}
int Road::getSecTownId()		const
{
	return secTownID;
}

// setters:

void Road::setFirstTownId(int id)
{
	this->firstTownID = id;

}
void Road::setSecTownId(int id)
{
	this->secTownID = id;

}

// operators:

bool Road::operator==(const Road& other)		 const
{
	return (this->firstTownID == other.firstTownID && this->secTownID == other.secTownID)
		|| (this->firstTownID == other.secTownID && this->secTownID == other.firstTownID);
}


// methods:

bool Road::isRoadValid(int numOfTown, std::vector<Road>& roads)				const
{
	return !(firstTownID==secTownID) && isRoadInValidRange(numOfTown) && !isRoadAlreadyExist(roads);
}

bool Road::isRoadInValidRange(int numOfTown)			const
{
	return firstTownID >= FIRST_VAL_ID_TOWN && firstTownID < numOfTown && secTownID >= FIRST_VAL_ID_TOWN && secTownID < numOfTown;
}


bool Road::isRoadAlreadyExist(std::vector<Road>& roads)			 const
{
	int logSize = roads.size();
	for (int i = 0; i < logSize; i++)
	{
		if (*this == roads.at(i))
		{
			return true;
		}
	}

	return false;
}
