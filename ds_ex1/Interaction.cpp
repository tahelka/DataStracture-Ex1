
#include "Interaction.h"

// getters:

int Interaction::getNumOfTowns()		const
{
	return numOfTowns;
}

int Interaction::getNumOfRoads()		const
{
	return numOfRoads;
}

Road Interaction::getPath()		    const
{
	return path;
}


// setters:

void Interaction::setNumOfTowns(int numOfTowns)
{
	this->numOfTowns = numOfTowns;
}

void Interaction::setNumOfRoads(int numOfRoads)
{
	this->numOfRoads = numOfRoads;
}

void Interaction::setPath(int currTown, int destTown)
{
	path.setFirstTownId(currTown);
	path.setSecTownId(destTown);
}

// methods:

std::vector<Road> Interaction::getTownsAndRoadsNumFromUser()
{
	std::vector<Road> roads;

	std::cin >> numOfTowns >> numOfRoads;

	if (numOfTowns < 1 || numOfRoads < 1 || numOfRoads > nCk(numOfTowns, 2))
	{
		// input is not valid
		return roads;
	}

	numOfTowns++; // plus 1 for dummy town

	roads = getRoadsFromUser();

	if (!roads.empty()) {

		int currTown, destTown;

		std::cin >> currTown >> destTown;

		setPath(currTown, destTown);

		if (!path.isRoadInValidRange(numOfTowns))
		{
			// input is not valid
			roads.clear();
		}
	}

	return roads;

}

std::vector<Road> Interaction::getRoadsFromUser()
{
	bool isValid;
	int firstTownID, secTownID;
	std::vector <Road> roads;
	roads.reserve(numOfRoads);
	Road newRoad;

	for (int i = 0; i < numOfRoads; i++)
	{
		std::cin >> firstTownID >> secTownID;

		newRoad.setFirstTownId(firstTownID);
		newRoad.setSecTownId(secTownID);

		isValid = newRoad.isRoadValid(numOfTowns, roads);

		if (!isValid)
		{
			roads.clear();
			return roads;
		}
		else
		{
			roads.push_back(newRoad);
		}
		
	}
	// clearing buffer in case user inserts more roads than needed
	clearBuffer();

	return roads;
}

int Interaction::nCk(int n, int k)		const
{
	int result = 1;
	for (int i = 1; i <= k; i++)
	{
		result *= n - i + 1;
		result /= i;
	}
	return result;
}

void Interaction::clearBuffer()			const
{
	std::cin.ignore(MAX_BUFFER, '\n');
}