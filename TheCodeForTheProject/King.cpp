#include "King.h"

bool King::LookWest()
{
	Location temp = GetLocation();
	temp.MoveX(-1);

	return GetLocation().IsWall(temp.GetCoordinates(), GetMaze());
};

bool King::LookEast()
{
	Location temp = GetLocation();
	temp.MoveX(1);

	return GetLocation().IsWall(temp.GetCoordinates(), GetMaze());
};

bool King::LookSouth()
{
	Location temp = GetLocation();
	temp.MoveZ(1);

	return GetLocation().IsWall(temp.GetCoordinates(), GetMaze());
};

bool King::LookNorth()
{
	Location temp = GetLocation();
	temp.MoveZ(-1);

	return GetLocation().IsWall(temp.GetCoordinates(), GetMaze());
};

void King::Move(Direction myDirection)
{
	Location temp = GetLocation();
	if(myDirection = North)
		temp.MoveZ(-1);
	else if (myDirection = East)
		temp.MoveY(1);
	else if (myDirection = South)
		temp.MoveZ(1);
	else if (myDirection = West)
		temp.MoveY(-1);
	GetLocation() = temp;
};