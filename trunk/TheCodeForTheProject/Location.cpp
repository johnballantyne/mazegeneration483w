#include "Location.h"

//returns struct of Coordinates type
Coordinates Location::GetCoordinates()
{
	return myCoordinates;
};

//sets the locaiton of whatever has a location
void Location::SetCoordinates(int x, int y, int z)
{
	myCoordinates.x = x;
	myCoordinates.y = y;
	myCoordinates.z = z;
};
//sets the location uses coordinate set as well
void Location::SetLocation(Coordinates myCoord)
{
	SetCoordinates(myCoord.x, myCoord.y, myCoord.z);
}
//change the X location
void Location::MoveX(int x)
{
	myCoordinates.x += x;
};

//change the y location
void Location::MoveY(int y)
{
	myCoordinates.y += y;
};

//cahnge z location
void Location::MoveZ(int z)
{
	myCoordinates.z += z;
};

bool Location::IsWall(Coordinates checkCoordinate, Maze myMaze)
{
	return myMaze.checkCoordinate(checkCoordinate.y, checkCoordinate.z);
};

//overloaded operator for assignment
Location& Location::operator=(const Location &myLocation) 
{
	this->SetCoordinates(myLocation.myCoordinates.x, myLocation.myCoordinates.y, myLocation.myCoordinates.z);
    return *this;
};

/*cout coordinates
ostream& operator<<(ostream& output, Location p) 
{
	output << "(" <<  p.GetCoordinates().x << ", " << p.GetCoordinates().y <<", " <<p.GetCoordinates().z <<")";
	return output;  // for multiple << operators.
};*/