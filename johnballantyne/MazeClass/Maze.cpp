

//general cse support, on business day john domico, main guy; tony vallalla, one of 3
#include "Maze.h"
#include <vector>
#include <iostream>
#include <time.h>
using namespace std;

Maze::Maze()
{
	width = 0;
	length = 0;
	real_width = 0;
	real_length = 0;

	for(int i=0; i<width; i++)
	{
		vector<bool> temp;
		temp.resize(width);
		for (int j=0; j<length; j++)
			maze.push_back(temp);
	}
}

Maze::Maze(int w, int l)
{
	srand(time(NULL));
	real_width = w;
	real_length = l;
	width = w*4+1;
	length = l*4+1;

	for(int i=0; i<width; i++)
	{
		vector<bool> temp;
		temp.resize(width);
		for (int j=0; j<length; j++)
			maze.push_back(temp);
	}

	for(int i=0; i<width; i++)
	{
		maze[i][0] = true;
		maze[i][width-1] = true;
	}

	for(int i=0; i<length; i++)
	{
		maze[0][i] = true;
		maze[length-1][i] = true;
	}

	//if (rand%2)
	{

	}
	//else
	{

	}

}

void Maze::setWidth(int w)
{
	//width = w*4+1;
	cout << "FUNCTION INCOMPLETE\n";
}

void Maze::setLength(int l)
{
	//length = l*4+1;
	cout << "FUNCTION INCOMPLETE\n";
}

int Maze::getWidth()
{
	return width;
}

int Maze::getLength()
{
	return length;
}

bool Maze::checkCoordinate(int x, int y)
{
	return maze[x][y];
}

void Maze::setCoordinate(int x, int y, bool set)
{
	maze[x][y] = set;
}

void Maze::printMaze()
{
	for (int i=0; i<width; i++)
	{
		for (int j=0; j<width; j++)
		{
			if (maze[i][j])
				cout << "1," << "";
			else
				cout << "0,";
		}
		cout << endl;
	}
}

void Maze::Random_StartEnd()
{
	if (rand()%2) //Start and end on sides
	{
		int rand1 = rand()%real_width;
		int rand2 = rand()%real_width;
		for (int i=1; i<4; i++)
		{
			maze[rand1*4+i][0] = 0;
			maze[rand2*4+i][width-1] = 0;
		}
	}
	else //Start and end on top and bottom
	{
		int rand1 = rand()%real_length;
		int rand2 = rand()%real_length;
		for (int i=1; i<4; i++)
		{
			maze[0][rand1*4+i] = 0;
			maze[length-1][rand2*4+i] = 0;
		}
	}
}

void Maze::GenMaze_Recursive()
{
	GenMaze_RecursiveFunction(0, real_width, 0, real_length);
	Random_StartEnd();
}

void Maze::GenMaze_RecursiveFunction(int x1, int x2, int y1, int y2)
{
	if (((x2-x1)==1) || ((y2-y1)==1))
		return;

	 //flip a coin for vertical or horizontal
	int coin = rand()%2;
	if ((x2-x1) > (y2-y1))
		coin = 0;
	if ((y2-y1) > (x2-x1))
		coin = 1;
	if (coin) //Horizontal
	{
		int rand_line = rand()%((y2-1)-(y1+1)+1)+(y1+1);
		int rand_spot = rand()%(x2-x1)+x1;
		for (int i=x1*4; i<x2*4; i++)
			maze[rand_line*4][i] = 1;

		maze[rand_line*4][rand_spot*4+1] = 0;
		maze[rand_line*4][rand_spot*4+3] = 0;
		maze[rand_line*4][rand_spot*4+2] = 0;
		
		GenMaze_RecursiveFunction(x1, x2, rand_line, y2);
		GenMaze_RecursiveFunction(x1, x2, y1, rand_line);

	}
	else  //Vertical
	{
		int rand_line = rand()%((x2-1)-(x1+1)+1)+(x1+1);
		int rand_spot = rand()%(y2-y1)+y1;
		for (int i=y1*4; i<y2*4; i++)
			maze[i][rand_line*4] = 1;

		maze[rand_spot*4+1][rand_line*4] = 0;
		maze[rand_spot*4+3][rand_line*4] = 0;
		maze[rand_spot*4+2][rand_line*4] = 0;

		GenMaze_RecursiveFunction(x1, rand_line, y1, y2);
		GenMaze_RecursiveFunction(rand_line, x2, y1, y2);
	}
}

void Maze::FillMazeWalls()
{
	for (int i=1; i<real_width; i++)
		for (int j=1; j<length; j++)
			maze[i*4][j] = 1;

	for (int i=1; i<real_length; i++)
		for (int j=1; j<width; j++)
			maze[j][i*4] = 1;
}

void Maze::GenMaze_DFS()
{
	FillMazeWalls();
	vector<cell> cells;
	for (int i=0; i<real_width; i++)
	{
		for (int j=0; j<real_length; j++)
		{
			cell temp;
			temp.X = i;
			temp.Y = j;
			temp.status = 0;
			cells.push_back(temp);
		}
	}

	while (cells.size()>1)
	{
		int randcell = rand()%(cells.size()-1);
		
		cell temp = cells[randcell];
		int randwall = -1;

		if ((temp.Y == 0) || (temp.Y == real_length-1))
			randwall = rand()%2;
		else if ((temp.X == 0) || (temp.X == real_width-1))
			randwall = rand()%(2)+2;
		else
			randwall = rand()%(4);
		
		switch (randwall)
		{
			case 0: //top
				for (int i=1; i<4; i++)
					maze[temp.X*4][temp.Y*4+i] = 0;
				break;
			case 1: //bottom
				for (int i=1; i<4; i++)
					maze[temp.X*4+4][temp.Y*4+i] = 0;
				break;
			case 2: //right
				for (int i=1; i<4; i++)
					maze[temp.X*4+i][temp.Y*4+4] = 0;
				break;
			case 3: //left
				for (int i=1; i<4; i++)
					maze[temp.X*4+i][temp.Y*4] = 0;
				break;
		}
		cells.erase(cells.begin()+randcell);
		cout << cells.size() << endl;
	}
}

void Maze::initMaze(int w, int l)
{
	srand(time(NULL));
	real_width = w;
	real_length = l;
	width = w*4+1;
	length = l*4+1;

	for(int i=0; i<width; i++)
	{
		vector<bool> temp;
		temp.resize(width);
		for (int j=0; j<length; j++)
			maze.push_back(temp);
	}

	for(int i=0; i<width; i++)
	{
		maze[i][0] = true;
		maze[i][width-1] = true;
	}

	for(int i=0; i<length; i++)
	{
		maze[0][i] = true;
		maze[length-1][i] = true;
	}
}