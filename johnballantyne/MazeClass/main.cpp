#include <iostream>
#include "Maze.h"
using namespace std;

int main()
{
	Maze maze(9, 9);
	//maze.printMaze();
	//maze.setCoordinate(2, 4, true);
	cout << endl;

	maze.GenMaze_Recursive();
		maze.printMaze();
	return 0;
}