#ifndef VECT3D_H
#define VECT3D_H
#include <cmath>
#include <iostream>
using namespace std;
class Vect3d
{
private:
	float X, Y, Z;

public:

	Vect3d()
	{
		X = Y = Z = 0.0;
	}

	Vect3d(float xCoord, float yCoord, float zCoord)
	{
		X = xCoord;
		Y = yCoord;
		Z = zCoord;
	}

	void SetX(float xCoord);
	void SetY(float yCoord);
	void SetZ(float zCoord);
	void SetCoord(float xCoord, float yCoord, float zCoord)
	{
		X = xCoord;
		Y = yCoord;
		Z = zCoord;
	}

	void Set(float xCoord, float yCoord, float zCoord)
	{
		X = xCoord;
		Y = yCoord;
		Z = zCoord;
	}

	Vect3d GetCoord()
	{
		return Vect3d(X, Y, Z);
	}



	float GetX();
	float GetY();
	float GetZ();

	float x();
	float y();
	float z();

	float operator[](int i)const 
	{
		if ( i==0 )
			return X;
		else if ( i==1 )
			return Y;
		else if ( i== 2 )
			return Z;
		else
		{
			cout<<"Out of range"<<endl;
			exit(1);
		}
	}

	float GetLength();
	float Dot(Vect3d v);
	Vect3d Cross(Vect3d v)
	{
		float x = (Y*v.z()) - (v.y() * Z);
		float y = -( (X * v.z()) - (v.x()*Z) );
		float z = (X * v.y()) - (v.x() * Y);

		return Vect3d(x, y, z);
	}
	void Normalized();

	Vect3d operator+(Vect3d v);
	Vect3d operator-(Vect3d v);


	void operator+=(Vect3d v);
	void operator-=(Vect3d v);
	void operator=(Vect3d v);

};

#endif