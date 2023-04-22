#ifndef _INTERACTION_H
#define _INTERACTION_H

#include <iostream>

#include <vector>
#include "Road.h"

#define MAX_BUFFER 256

class Interaction
{

	int numOfTowns; 
	int numOfRoads;
	Road path;

	// private functions:
	std::vector<Road> getRoadsFromUser();

public:

	// getters:
	int getNumOfTowns()			const;
	int getNumOfRoads()			const;
	Road getPath()				const;

	// setters:
	void setNumOfTowns(int numOfTowns);
	void setNumOfRoads(int numOfRoads);
	void setPath(int currTown, int destTown);

	// methods:

	// this function gets the needed input from user and stores it
	std::vector<Road> getTownsAndRoadsNumFromUser();
	// this function calculates n choose k
	int nCk(int n, int k)		const;
	// this function clears buffer
	void clearBuffer()			const; 
};

#endif

