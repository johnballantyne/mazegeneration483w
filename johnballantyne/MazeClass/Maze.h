#ifndef CUBE_H
#define CUBE_H
#include <vector>
using namespace std;

class Maze
{
public:
	Maze();
	Maze(int w, int l);
	void setWidth(int w);
	void setLength(int l);
	int getWidth();
	int getLength();
	bool checkCoordinate(int x, int y);
	void setCoordinate(int x, int y, bool set);
	void printMaze();
	void GenMaze_Recursive();
	void GenMaze_DFS();
	void initMaze(int w, int l);
private:
	void Random_StartEnd();
	void GenMaze_RecursiveFunction(int x1, int x2, int y1, int y2);
	void FillMazeWalls();
	int width;
	int length;
	int real_width;
	int real_length;
	vector<vector<bool>> maze;
	struct cell {
		int X;
		int Y;
		int status;
	};
};
#endif