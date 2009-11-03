#ifndef CAMERA_H
#define CAMERA_H


#include "Vect3D.h"
#include <gl/glut.h>
class Camera
{
private:
	Vect3d Position, Direction, Up;
	Vect3d X_Axis, Y_Axis, Z_Axis;

public:
	Camera()
	{
		Position.Set(0.0, 0.0, 0.0);
		Direction.Set(0.0, 0.0, -1.0);
		Up.Set(0.0, 1.0, 0.0);

		X_Axis.Set(1.0, 0.0, 0.0);
		Y_Axis.Set(0.0, 1.0, 0.0);
		Z_Axis.Set(0.0, 0.0, 1.0);
	}

	void RotateY(float angle);
	void RotateX(float angle);
	void RotateZ(float angle);

	void SetCamera()
	{
		glLoadIdentity();
		gluLookAt(Position.x(), Position.y(), Position.z(),
				  Position.x()+Direction.x(), Position.y()+Direction.y(), Position.z() + Direction.z(),
				  Up.x(), Up.y(), Up.z());
	}

};


#endif