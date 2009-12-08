#pragma once
#include "King.h"

class KingLHR : public King
{
public:
	void SolveMaze(Coordinates Start, Coordinates End, Direction startDirection)
	{
		SetLocation(Start);
		PushPath(GetLocation());

		do{
			while(GetDirection() == North){
				if(!LookNorth() && LookEast()){
					this->Move(North);
					PushPath(GetLocation());
				}
				else if(!LookEast()) SetDirection(East);
				else SetDirection(West);
			}
			while(GetDirection() == East){
				if(!LookEast() && LookSouth()){
					this->Move(East);
					PushPath(GetLocation());
				}
				else if(!LookSouth()) SetDirection(South);
				else SetDirection(North);
			}
			while(GetDirection() == South){
				if(!LookSouth() && LookWest()){
					this->Move(South);
					PushPath(GetLocation());
				}
				else if(!LookWest()) SetDirection(West);
				else SetDirection(East)
			}
			while(GetDirection() == West){
				if(!LookWest() && LookNorth()){
					this->Move(West);
					PushPath(GetLocation());
				}
				else if (!LookNorth) SetDirection(North);
				else SetDirection(South);
			}
		}
		while(GetLocation().GetCoordinates() != End);
	}
};