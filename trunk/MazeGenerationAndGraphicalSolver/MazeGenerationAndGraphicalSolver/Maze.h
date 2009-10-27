//#pragma once
#include <iomanip>
#include <vector>
#include "Coordinate.h"
using namespace std;

class Maze
{
public:
	Maze()
	{
		Width = Length = 0;
		//myVector(Width, vector<bool>(Length));
		for ( int i = 0; i < Width; i++ )
		{
			//vector<bool> temp;
			//temp.resize(10);
			for (int j = 0; j < Length; j++)
			{
				myVector[i].push_back(1);
			}
		}
	};
	//init constructor
	Maze(int newWidth, int newLength)
	{
		SetWidth(newWidth);
		SetLength(newLength);
		//myVector(Width, vector<bool>(Length));
		for ( int i = 0; i < Width; i++ )
		{
			for (int j = 0; j < Length; j++)
			{
				myVector[i].push_back(1);
			}
		}
	};
	bool CheckCoordinates(Coordinates myCoordinate)
	{
		return myVector[myCoordinate.x][myCoordinate.y];
	};
 	void SetWidth(int newWidth)
	{
		Width = newWidth;
	}
	void SetLength(int newLength)
	{
		Length = newLength;
	}
private:

	vector<vector<bool> > myVector;
	int Width, Length;
};