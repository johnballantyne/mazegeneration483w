#pragma once
#include "Location.h"

enum Direction {North, East, South, West};

class King
{
public:
	/********************************constructers****************************/
	//default constructer
	King()
	{
	};

	/********************************Getters*********************************/
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

	//get the direction
	Direction GetDirection()
	{
		return myDirection;
	}

	/********************************setters*********************************/
	//set the direstion of the current king
	void SetDirection(Direction newDirection)
	{
		myDirection = newDirection;
	}
	/********************************Looking Functions***********************/

	//Check if there is a wall directly West of the kings location
	bool LookWest();

	//Check if there is a wall directly East of the kings location
	bool LookEast();

	//Check if there is a wall directly South of the kings location
	bool LookSouth();
	
	//Check if there is a wall directly North of the kings location
	bool LookNorth();

	/*******************************MazeFunctions*******************************/
	//method that each individual solver will impliment
	void  SolveMaze(Coordinates start, Coordinates end, Direction startDirection);

	//set up the maze
	void SetUpMaze();
	
private:
	//Location Variable stores Kings Coordinates
	//See location.h for methods
	Location myLocation;

	//Maze that is being solved by the King
	Maze myMaze;

	//Enumerated type to make traversing the maze easier
	//"North, East, South, West"
	Direction myDirection;
};