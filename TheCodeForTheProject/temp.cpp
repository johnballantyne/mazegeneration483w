#include "stdafx.h"
#include "KingRHR.h"
#include "KingLHR.h"
#include "Coordinate.h"
#include <stdio.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int x = 0;
	Coordinates mine, theres;
	theres.x = mine.x = mine.y = mine.z = 1;
	theres.y = theres.z = 19;
	
	KingLHR myKing;
	KingRHR myKing1;

	cout<<"Enter 1 for RHR 2 for LHR"<<endl;
	cout<<"Enter 3 to quit"<<endl;
	cin>>x;
	if(x == 1)
		myKing.SolveMaze(mine, theres, North);
	else if(x ==2 )
		myKing1.SolveMaze(mine, theres, North);
	
	cout<<"Mazed Solved!"<<endl;

	system("pause");

	return 0;
}

