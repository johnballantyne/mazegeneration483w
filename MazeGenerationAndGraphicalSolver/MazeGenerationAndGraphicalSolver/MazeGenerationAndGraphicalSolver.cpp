// MazeGenerationAndGraphicalSolver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "KingRHR.h"
#include "Coordinate.h"

int _tmain(int argc, _TCHAR* argv[])
{
	KingRHR myKing;

	Maze maze(19, 19);
	cout << endl;

	maze.GenMaze_Recursive();
		maze.printMaze();
	system("pause");


	return 0;
}

