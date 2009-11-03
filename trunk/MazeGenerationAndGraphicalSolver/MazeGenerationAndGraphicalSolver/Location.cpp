#include "Location.h"

//returns struct of Coordinates type
Coordinates Location::GetCoordinates()
{
	return myCoordinates;
}

//sets the locaiton of whatever has a location
void Location::SetCoordinates(Coordinates newCoordinate)
{
	myCoordinates.x = newCoordinate.x;
	myCoordinates.y = newCoordinate.y;
	myCoordinates.z = newCoordinate.z;
}

//change the X location
void Location::MoveX(int x)
{
	myCoordinates.x += x;
}

//change the y location
void Location::MoveY(int y)
{
	myCoordinates.y += y;
}

//cahnge z location
void Location::MoveZ(int z)
{
	myCoordinates.z += z;
}

bool Location::IsWall(Coordinates checkCoordinate, Maze myMaze)
{
	return myMaze.checkCoordinate(checkCoordinate.x, checkCoordinate.z);
}
//overloaded operator for assignment
Location& Location::operator=(Location &myLocation) 
{
	this->SetCoordinates(myLocation.GetCoordinates());
    return *this;
  }
/*cout coordinates
ostream& operator<<(ostream& output, Location p) 
{
	output << "(" <<  p.GetCoordinates().x << ", " << p.GetCoordinates().y <<", " <<p.GetCoordinates().z <<")";
	return output;  // for multiple << operators.
};*/