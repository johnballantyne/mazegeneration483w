#include "Vect3D.h"

void Vect3d::SetX(float xCoord)
{
	x = xCoord;
}

void Vect3d::SetY(float yCoord)
{
	y = yCoord;
}

void Vect3d::SetZ(float zCoord)
{
	z = zCoord;
}

float Vect3d::GetX()
{
	return x;
}
float Vect3d::GetY()
{
	return y;
}
float Vect3d::GetZ()
{
	return z;
}

float Vect3d::GetLength()
{
	return sqrt(x*x + y*y + z*z);
}

void Vect3d::Normalized()
{
	float length = this->GetLength();

	if ( length == 0 )	//prevent division of 0
		length = 1;

	x /= length;
	y /= length;
	z /= length;
}

float Vect3d::Dot(Vect3d v)
{
	return (x*v.GetX() + y*v.GetY() + z*v.GetZ());
}

Vect3d Vect3d::operator +(Vect3d v)
{
	return Vect3d(x+v.GetX(), y+v.GetY(), z+v.GetZ());
}

Vect3d Vect3d::operator -(Vect3d v)
{
	return Vect3d(x-v.GetX(), y-v.GetY(), z-v.GetZ());
}

void Vect3d::operator = (Vect3d v)
{
	x = v.GetX();
	y = v.GetY();
	z = v.GetZ();

//	return *this;
}

void Vect3d::operator+=( Vect3d v)
{
	x += v.GetX();
	y += v.GetY();
	z += v.GetZ();
}

void Vect3d::operator-= (Vect3d v)
{
	x -= v.GetX();
	y += v.GetY();
	z += v.GetZ();
}