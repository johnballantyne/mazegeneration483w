#pragma once
#include <iostream>
#include "Maze.h"
#include "Coordinate.h"

using namespace std;

//outputing coordinates is same as cout
//ostream& operator<<(ostream& output, Coordinates p);

//class has set and get funcitons also has a coordinate struct
//to keep track of location based on x and y
class Location
{
public:
	//default constructor
	Location(){};
	//init constructor
	//sets location passed to it from maze
	Location(Coordinates newCoordinate)
	{
		SetCoordinates(newCoordinate);
	};
	//returns struct of Coordinates type
	Coordinates GetCoordinates();
	//sets the locaiton of whatever has a location
	void SetCoordinates(Coordinates newCoordinate);
	//change the X location
	void MoveX(int x);
	//change the y location
	void MoveY(int y);
	//change z location
	void MoveZ(int z);
	//checks if coordinate is a wall
	bool IsWall(Coordinates checkCoordinate, Maze myMaze);
	//overloaded = operator for locations
	Location & operator=(Location &myLocation);
private:
	Coordinates myCoordinates;
};


