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
				if(GetLocation().GetCoordinates() == End) break;
				if(!LookNorth() && LookEast()){
					this->Move(North);
					PushPath(GetLocation());
					this->SetMazeCoordinate(GetLocation(), true);
				}
				else if(!LookEast()) SetDirection(East);
				else SetDirection(West);
			}
			while(GetDirection() == East){
				if(GetLocation().GetCoordinates() == End) break;
				if(!LookEast() && LookSouth()){
					this->Move(East);
					PushPath(GetLocation());
					this->SetMazeCoordinate(GetLocation(), true);
				}
				else if(!LookSouth()) SetDirection(South);
				else SetDirection(North);
			}
			while(GetDirection() == South){
				if(GetLocation().GetCoordinates() == End) break;
				if(!LookSouth() && LookWest()){
					this->Move(South);
					PushPath(GetLocation());
					this->SetMazeCoordinate(GetLocation(), true);
				}
				else if(!LookWest()) SetDirection(West);
				else SetDirection(East);
			}
			while(GetDirection() == West){
				if(GetLocation().GetCoordinates() == End) break;
				if(!LookWest() && LookNorth()){
					this->Move(West);
					PushPath(GetLocation());
					this->SetMazeCoordinate(GetLocation(), true);
				}
				else if (!LookNorth()) SetDirection(North);
				else SetDirection(South);
			}
		}
		while(GetLocation().GetCoordinates() != End);
	}
};