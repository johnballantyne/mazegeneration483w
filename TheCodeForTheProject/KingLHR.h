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
					Move(North);
				else SetDirection(West);
			}
			while(GetDirection() == West){
				if(!LookWest())
					Move(West);
				else SetDirection(South);
			}
			while(GetDirection() == South){
				if(!LookSouth())
					Move(South);
				else SetDirection(East);
			}
			while(GetDirection() == East){
				if(!LookEast())
					Move(East);
				else SetDirection(North);
			}
		}
		while(GetLocation().GetCoordinates() != End);
	}
};