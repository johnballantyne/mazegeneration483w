#pragma once
#include "King.h"

class KingRHR : public King
{
public:
	void SolveMaze(Coordinates Start, Coordinates End, Direction startDirection)
	{
		GetLocation().SetCoordinates(Start.x, Start.y, Start.z);
		SetDirection(startDirection);

		do{
			while(GetDirection() == North){
				if(!LookNorth()){
					Move(North);
					GetMaze().setCoordinate(GetLocation().GetCoordinates().x, GetLocation().GetCoordinates().z,true);
					GetMaze().printMaze();}
				else SetDirection(East);
			}
			while(GetDirection() == East){
				if(!LookEast()){
					Move(East);
					GetMaze().setCoordinate(GetLocation().GetCoordinates().x, GetLocation().GetCoordinates().z,true);
					GetMaze().printMaze();}
				else SetDirection(South);
			}
			while(GetDirection() == South){
				if(!LookSouth()){
					Move(South);
					GetMaze().setCoordinate(GetLocation().GetCoordinates().x, GetLocation().GetCoordinates().z,true);
					GetMaze().printMaze();}
				else SetDirection(West);
			}
			while(GetDirection() == West){
				if(!LookWest()){
					Move(West);
					GetMaze().setCoordinate(GetLocation().GetCoordinates().x, GetLocation().GetCoordinates().z,true);
					GetMaze().printMaze();}
				else SetDirection(North);
			}
		}
		while(GetLocation().GetCoordinates() != End);
	}
};