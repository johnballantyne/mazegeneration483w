#include <iostream>
#include "Maze.h"
using namespace std;

int main()
{
	Maze maze(19, 19);
	//maze.printMaze();
	//maze.setCoordinate(2, 4, true);
	cout << endl;

	maze.GenMaze_Recursive();
		maze.printMaze();
	return 0;
}