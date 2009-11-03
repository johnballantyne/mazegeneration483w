#include "Camera.h"


void Camera::RotateY(float angle)
{
	float xd = Direction.x();
	float yd = Direction.y();
	float zd = Direction.z();

	//Rotate about the y-axis
	
	Vect3d newDir(xd*cos(angle) - zd*sin(angle),
					yd,
					xd*sin(angle) + zd*cos(angle));

	/*Vect3d newDir(zd*cos(angle) + xd*sin(angle),
				  yd,
				  zd*sin(angle) - xd*cos(angle));*/
	//After that, re-config the coordinate system.

	Direction = newDir;
	Vect3d newXaxis;


	newXaxis = Direction.Cross(Up);		//Give a new x-axis
	X_Axis = newXaxis;
	


}
void Camera::RotateX(float angle)
{
	/*float xa = X_Axis.x();
	float ya = X_Axis.y();
	float za = X_Axis.z();*/

	float xa = Up.x();
	float ya = Up.y();
	float za = Up.z();

	Vect3d newDir(xa, ya*cos(angle) - za*sin(angle), ya*sin(angle) + za*cos(angle));
		/*Vect3d newDir(zd*cos(angle) + xd*sin(angle),
				  yd,
				  zd*sin(angle) - xd*cos(angle));*/
	Up = newDir;
	Vect3d newDirection;
	newDirection = Up.Cross(X_Axis);
	Direction = newDirection;
}