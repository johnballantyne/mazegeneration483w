#pragma once
#include <iostream>
#include "Maze.h"
#include "Coordinate.h"

using namespace std;

class Location
{
public:
	//default constructor
	Location()
	{
		SetCoordinates(1,1,1);
	}
	//init constructor
	//sets location passed to it from maze
	Location(Coordinates newCoordinate)
	{
		SetCoordinates(newCoordinate.x, newCoordinate.y, newCoordinate.z);
	}
	//returns struct of Coordinates type
	Coordinates GetCoordinates();
	//sets the locaiton of whatever has a location
	void SetCoordinates(int x, int y, int z);
	//set location
	void SetLocation(Coordinates myCoords);
	//change the X location
	void MoveX(int x);
	//change the y location
	void MoveY(int y);
	//change z location
	void MoveZ(int z);
	//checks if coordinate is a wall
	bool IsWall(Coordinates checkCoordinate, Maze myMaze);
	//overloaded = operator for locations
	Location & operator=(const Location &myLocation);
protected:
	Coordinates myCoordinates;
};


