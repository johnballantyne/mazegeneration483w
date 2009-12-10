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
				if(GetLocation().GetCoordinates() == End) break;
				if(!LookNorth() && LookWest()){
					this->Move(North);
					PushPath(GetLocation());
					this->SetMazeCoordinate(GetLocation(), true);
				}
				else if(!LookWest()) SetDirection(West);
				else SetDirection(East);
			}
			while(GetDirection() == East){
				if(GetLocation().GetCoordinates() == End) break;
				if(!LookEast() && LookNorth()){
					this->Move(East);
					PushPath(GetLocation());
					this->SetMazeCoordinate(GetLocation(), true);
				}
				else if(!LookNorth()) SetDirection(North);
				else SetDirection(South);
			}
			while(GetDirection() == South){
				if(GetLocation().GetCoordinates() == End) break;
				if(!LookSouth() && LookEast()){
					this->Move(South);
					PushPath(GetLocation());
					this->SetMazeCoordinate(GetLocation(), true);
				}
				else if(!LookEast()) SetDirection(East);
				else SetDirection(West);
			}
			while(GetDirection() == West){
				if(GetLocation().GetCoordinates() == End) break;
				if(!LookWest() && LookSouth()){
					this->Move(West);
					PushPath(GetLocation());
					this->SetMazeCoordinate(GetLocation(), true);
				}
				else if (!LookSouth()) SetDirection(South);
				else SetDirection(North);
			}
		}
		while(GetLocation().GetCoordinates() != End);
	}

};