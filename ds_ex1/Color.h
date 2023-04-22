#ifndef __COLOR_H
#define __COLOR_H

#include <vector>

#define WHITE 0
#define BLACK 1

class Color
{
	std::vector<int> colors;

public:

	// Constructors
	Color(int numOfTowns) : colors(numOfTowns, WHITE) {}

	// getters:
	std::vector<int>& getColors();

	// setters:
	void resetColorsToWhite();

	// Methods
	// this function makes town black
	void makeTownBlack(int id);
	// this function makes town white
	void makeTownWhite(int id);
	// this function checks if a town is white (never visited)
	bool isTownWhite(int id) const;

};

#endif


