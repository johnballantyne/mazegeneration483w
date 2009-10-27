#include "stdafx.h"
#include "Location.h"
#include "King.h"

int _tmain(int argc, _TCHAR* argv[])
{
	
	Coordinates myCoordinate;
	myCoordinate.x = 5;
	myCoordinate.y = 6;
	myCoordinate.z = 2;
	
	//cout<< myCoordinate;
	
	King myKing(myCoordinate);

	//cout<<myKing.LookEast().y;
	return 0;
}

