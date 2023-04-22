#ifndef __ROAD_H
#define __ROAD_H

#include <iostream>
#include <vector>

#define FIRST_VAL_ID_TOWN 1 // first valid id town in ascending order is id 1

class Road
{
	int firstTownID;
	int secTownID;

public:
	// getters:
	int getFirstTownId()		const;
	int getSecTownId()			const;

	// setters:
	void setFirstTownId(int id);
	void setSecTownId(int id);

	// operators:
	bool operator==(const Road& other)	const;

	// methods:

	// this function checks if a road is valid
	bool isRoadValid(int numOfTown, std::vector<Road>& roads)			const;
	// this function checks if a road is in valid range
	bool isRoadInValidRange(int numOfTown)								const;
	// this function checks if a road is already received
	bool isRoadAlreadyExist(std::vector<Road>& roads)					const;
	// this function checks if two road are the same

};

#endif