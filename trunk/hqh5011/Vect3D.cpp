#include "Vect3D.h"

void Vect3d::SetX(float xCoord)
{
	X = xCoord;
}

void Vect3d::SetY(float yCoord)
{
	Y = yCoord;
}

void Vect3d::SetZ(float zCoord)
{
	Z = zCoord;
}

float Vect3d::GetX()
{
	return X;
}
float Vect3d::GetY()
{
	return Y;
}
float Vect3d::GetZ()
{
	return Z;
}

float Vect3d::x(){ return X; }
float Vect3d::y(){ return Y; }
float Vect3d::z(){ return Z; }

float Vect3d::GetLength()
{
	return sqrt(X*X + Y*Y + Z*Z);
}

void Vect3d::Normalized()
{
	float length = this->GetLength();

	if ( length == 0 )	//prevent division of 0
		length = 1;

	X /= length;
	Y /= length;
	Z /= length;
}

float Vect3d::Dot(Vect3d v)
{
	return (X*v.GetX() + Y*v.GetY() + Z*v.GetZ());
}

Vect3d Vect3d::operator +(Vect3d v)
{
	return Vect3d(X+v.GetX(), Y+v.GetY(), Z+v.GetZ());
}

Vect3d Vect3d::operator -(Vect3d v)
{
	return Vect3d(X-v.GetX(), Y-v.GetY(), Z-v.GetZ());
}

void Vect3d::operator = (Vect3d v)
{
	X = v.GetX();
	Y = v.GetY();
	Z = v.GetZ();

//	return *this;
}

void Vect3d::operator+=( Vect3d v)
{
	X += v.GetX();
	Y += v.GetY();
	Z += v.GetZ();
}

void Vect3d::operator-= (Vect3d v)
{
	X -= v.GetX();
	Y += v.GetY();
	Z += v.GetZ();
}