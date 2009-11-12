#pragma once
#include "King.h"

class KingRHR : public King
{
	void Solve(Coordinates Start, Coordinates End, Direction startDirection)
	{
		do{
			while(GetDirection() == North){
				if(!LookNorth())
					GetLocation().MoveZ(-1);
				else SetDirection(West);
			}
			while(GetDirection() == East){
				if(!LookEast())
					GetLocation().MoveX(1);
				else SetDirection(South);
			}
			while(GetDirection() == South){
				if(!LookSouth())
					GetLocation().MoveZ(1);
				else SetDirection(West);
			}
			while(GetDirection() == West){
				if(!LookWest())
					GetLocation().MoveX(-1);
				else SetDirection(North);
			}
		}
		while(GetLocation().GetCoordinates() != End);
	}
};