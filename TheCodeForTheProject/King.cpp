#include "King.h"

bool King::LookWest()
{
	Location temp = GetLocation();
	temp.MoveZ(-1);

	return GetLocation().IsWall(temp.GetCoordinates(), GetMaze());
};

bool King::LookEast()
{
	Location temp = GetLocation();
	temp.MoveZ(1);

	return GetLocation().IsWall(temp.GetCoordinates(), GetMaze());
};

bool King::LookSouth()
{
	Location temp = GetLocation();
	temp.MoveY(1);

	return GetLocation().IsWall(temp.GetCoordinates(), GetMaze());
};

bool King::LookNorth()
{
	Location temp = GetLocation();
	temp.MoveY(-1);

	return GetLocation().IsWall(temp.GetCoordinates(), GetMaze());
};

void King::Move(Direction myDirection)
{
	Location temp = GetLocation();
	if(myDirection == North)
		temp.MoveY(-1);
	else if (myDirection == East)
		temp.MoveZ(1);
	else if (myDirection == South)
		temp.MoveY(1);
	else if (myDirection == West)
		temp.MoveZ(-1);
	SetLocation(temp);
};