#pragma once
#include "Location.h"
#include <vector>

enum Direction {North, East, South, West};

class King
{
public:
	/********************************constructers****************************/
	//default constructer
	King()
	{
		SetDirection(North);
		myMaze.GenMaze_Recursive();
	};

	/********************************Getters*********************************/
	//getter for location
	Location GetLocation()
	{
		return myLocation;
	}

	//get the maze in the king class
	Maze GetMaze()
	{
		return myMaze;
	}

	//get the direction
	Direction GetDirection()
	{
		return myDirection;
	}

	//get the vector of the kings path
	vector<Location> GetKingsPath()
	{
		return kingsPath;
	}

	void PushPath(Location newLocation)
	{
		kingsPath.push_back(newLocation);
	}
	/********************************setters*********************************/
	//set the direstion of the current king
	void SetDirection(Direction newDirection)
	{
		myDirection = newDirection;
	}

	void SetLocation(Location newLocation)
	{
		myLocation = newLocation;
	}

	void SetLocation(Coordinates newCoord)
	{
		myLocation.SetLocation(newCoord);
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

	void Move(Direction moveDirection);
	
	void SetMazeCoordinate(Location myLoc, bool set)
	{
		myMaze.setCoordinate(myLoc.GetCoordinates().y, myLoc.GetCoordinates().z, set);
	}
private:
	//Location Variable stores Kings Coordinates
	//See location.h for methods
	Location myLocation;

	//Maze that is being solved by the King
	Maze myMaze;

	//Enumerated type to make traversing the maze easier
	//"North, East, South, West"
	Direction myDirection;

	//the vector that will be storing the kings locations
	//possibility of using this vector to store choices
	//if i impliment a depth first search algorithm
	vector <Location> kingsPath;
};