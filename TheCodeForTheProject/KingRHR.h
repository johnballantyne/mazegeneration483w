#pragma once
#include "King.h"

class KingRHR : public King
{
public:
	void SolveMaze(Coordinates Start, Coordinates End, Direction startDirection)
	{
		SetLocation(Start);
		PushPath(GetLocation());

		do{
			while(GetDirection() == North){
				if(!LookNorth() && LookWest()){
					this->Move(North);
					PushPath(GetLocation());
				}
				else if(!LookWest()) SetDirection(West);
				else SetDirection(East);
			}
			while(GetDirection() == East){
				if(!LookEast() && LookNorth()){
					this->Move(East);
					PushPath(GetLocation());
				}
				else if(!LookNorth()) SetDirection(North);
				else SetDirection(South);
			}
			while(GetDirection() == South){
				if(!LookSouth() && LookEast()){
					this->Move(South);
					PushPath(GetLocation());
				}
				else if(!LookEast()) SetDirection(East);
				else SetDirection(West);
			}
			while(GetDirection() == West){
				if(!LookWest() && LookSouth()){
					this->Move(West);
					PushPath(GetLocation());
				}
				else if (!LookSouth()) SetDirection(South);
				else SetDirection(North);
			}
		}
		while(GetLocation().GetCoordinates() != End);
	}
};