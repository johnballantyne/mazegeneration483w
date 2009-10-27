#pragma once
#include "Location.h"

class King
{
public:
	//default constructer
	King(){};

	//init constructor
	King(Coordinates startCoordinate)
	{
		myLocation.SetCoordinates(startCoordinate);
	};
	//getter for location
	Location GetLocation()
	{
		return myLocation;
	}
	//prototype function to make my project work
	Maze GetMaze()
	{
		return myMaze;
	}
	//Check if there is a wall directly West of the kings location
	bool LookWest();

	//Check if there is a wall directly East of the kings location
	bool LookEast();

	//Check if there is a wall directly South of the kings location
	bool LookSouth();

	//Check if there is a wall directly North of the kings location
	bool LookNorth();

private:
	Location myLocation;
	Maze myMaze;
};