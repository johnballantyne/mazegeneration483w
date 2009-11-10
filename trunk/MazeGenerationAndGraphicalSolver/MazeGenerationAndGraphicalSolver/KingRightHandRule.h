#pragma once
#include "King.h"

class KingRightHandRule : public King
{
public:
	//init constructor
	KingRightHandRule(){};
	
	//Takes start coordinates based on the start location
	//of the maze
	KingRightHandRule(Coordinates startCoordinate)
	{
		SetDirection(North);
		GetLocation().SetCoordinates(startCoordinate);
	};
};