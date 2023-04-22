#ifndef _COUNTRYSTRUCTURE_H
#define _COUNTRYSTRUCTURE_H

#include <vector>

#include "List.h"
#include "Road.h"
#include "Color.h"
#include "Stack.h"

#define DUMMY_HEAD_ID 0
#define DEAD_ROAD -1
#define START 1
#define AFTER_FIRST 2


class CountryStructure {
	std::vector<List> countryStructure;
	int numOfTowns; // including dummy town

	// private functions:
	void setCountryStructure(std::vector<Road>& roads);

public:
	// Constructors
	CountryStructure(int numOfTowns, std::vector<Road>& roads);

	// getters:
	std::vector<List>& getCountryStructure();
	int getNumOfTowns()						 const;

	// setters:
	void setNumOfTowns(int num);

	// Methods

	// this function calculate the preferred distance recursivly
	int townDistanceRecursive(int currTown, int destTown, Color& colors);
	// this function calculate the preferred distance iterativly
	int townDistanceIterative(int currTown, int destTown, Color& colors);

};

#endif
