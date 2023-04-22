#include <iostream>
#include <vector>

#include "CountryStructure.h"
#include "Interaction.h"
#include "Color.h"

int main()
{
	Interaction myInteraction;

	 std::vector<Road> roads = myInteraction.getTownsAndRoadsNumFromUser();

	 if (roads.empty())
	 {
		 std::cout << "invalid input" << std::endl;
	 }
	 else
	 {

		 int numOfTowns = myInteraction.getNumOfTowns();
		 int currTown = myInteraction.getPath().getFirstTownId();
		 int destTown = myInteraction.getPath().getSecTownId();

		 Color colors(numOfTowns);

		 CountryStructure country(numOfTowns, roads);

		 int recursivePreferredDistance = country.townDistanceRecursive(currTown, destTown, colors);
		 std::cout << "Preferred distance (recursive algorithm): " << recursivePreferredDistance << std::endl;

		 colors.resetColorsToWhite();

		 int iterativePreferredDistance = country.townDistanceIterative(currTown, destTown, colors);
		 std::cout << "Preferred distance (iterative stack algorithm): " << iterativePreferredDistance << std::endl;

	 }

}
