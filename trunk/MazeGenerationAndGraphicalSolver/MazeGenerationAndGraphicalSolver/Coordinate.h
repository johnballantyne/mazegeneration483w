#pragma once

//struct used to maintain an x and y in one struct
struct Coordinates
{
	int x;
	int y;
	int z;
};

bool operator==(Coordinates& other, Coordinates &myCoordinate);
bool operator!=(Coordinates& other, Coordinates &myCoordinate);