#include "Coordinate.h"

bool operator==(Coordinates& other, Coordinates &myCoordinate)
{
	return (other.x == myCoordinate.x && other.y == myCoordinate.y && other.z == myCoordinate.z);
};
bool operator!=(Coordinates& other, Coordinates &myCoordinates)
{
	return !(other == myCoordinates);
};