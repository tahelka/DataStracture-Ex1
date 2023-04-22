#include "Color.h"


// getters:

std::vector<int>& Color::getColors()
{
	return colors;
}


// setters:
void Color::resetColorsToWhite()
{
	std::fill(colors.begin(), colors.end(), WHITE);
}

// methods:

void Color::makeTownBlack(int id)
{
	colors.at(id) = BLACK;
}

void Color::makeTownWhite(int id)
{
	colors.at(id) = WHITE;
}

bool Color::isTownWhite(int id)	const
{
	return colors.at(id) == WHITE;
}
