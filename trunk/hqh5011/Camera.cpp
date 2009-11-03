#include "Camera.h"


void Camera::RotateY(float angle)
{
	float xd = Direction.x();
	float yd = Direction.y();
	float zd = Direction.z();

	//Rotate about the y-axis
	//This will rotate the camera around the origin axis
	
	//The rotation here is using Rotation Matrix around the Y-axis


	// (New camera Position) = RotationMatrix * (Old camera Position)
	/*
		| cos(ang)    0     -sin(ang)   0  |   | CamX |
		|    0        1        0        0  |   | CamY |
		| sin(ang)    0      cos(ang)   0  | * | CamZ |
		|    0        0        0        1  |   |  1   |
	*/
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

void Camera::MoveStraight(float distance)
{
	float px = Position.x();
	float py = Position.y();
	float pz = Position.z();

	Position.Set(px+Direction.x()*distance,
				 py+Direction.y()*distance,
				 pz+Direction.z()*distance);

}

void Camera::TopViewCamera()
{
	Position.Set(0, 50, 0);		//Set position of the top view camera
	Direction.Set(0, -1, 0);	//Direction of looking is down
	Up.Set(0, 0, -1);		//Up direction is toward the -z axis
}

void Camera::ThirdPersonCamera()
{
	Position.Set(0, 0, 0);
	Direction.Set(0, 0, -1);
	Up.Set(0, 1, 0);
}