#ifndef VECT3D_H
#define VECT3D_H
#include <cmath>

class Vect3d
{
private:
	float x, y, z;

public:

	Vect3d()
	{
		x = y = z = 0.0;
	}

	Vect3d(float xCoord, float yCoord, float zCoord)
	{
		x = xCoord;
		y = yCoord;
		z = zCoord;
	}

	void SetX(float xCoord);
	void SetY(float yCoord);
	void SetZ(float zCoord);
	void SetCoord(float xCoord, float yCoord, float zCoord)
	{
		x = xCoord;
		y = yCoord;
		z = zCoord;
	}

	Vect3d GetCoord()
	{
		return Vect3d(x, y, z);
	}



	float GetX();
	float GetY();
	float GetZ();

	float GetLength();
	float Dot(Vect3d v);
	void Normalized();

	Vect3d operator+(Vect3d v);
	Vect3d operator-(Vect3d v);

	void operator+=(Vect3d v);
	void operator-=(Vect3d v);
	void operator=(Vect3d v);

};

#endif