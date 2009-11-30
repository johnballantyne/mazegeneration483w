#pragma once
#include "King.h"

class KingLHR : public King
{
public:
	void SolveMaze(Coordinates Start, Coordinates End, Direction startDirection)
	{
		GetLocation().SetCoordinates(Start.x, Start.y, Start.z);
		SetDirection(startDirection);

		do{
			while(GetDirection() == North){
				if(!LookNorth())
					GetLocation().MoveZ(-1);
				else SetDirection(West);
			}
			while(GetDirection() == West){
				if(!LookWest())
					GetLocation().MoveX(-1);
				else SetDirection(South);
			}
			while(GetDirection() == South){
				if(!LookSouth())
					GetLocation().MoveZ(1);
				else SetDirection(East);
			}
			while(GetDirection() == East){
				if(!LookEast())
					GetLocation().MoveX(1);
				else SetDirection(North);
			}
		}
		while(GetLocation().GetCoordinates() != End);
	}
};