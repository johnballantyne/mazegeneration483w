#ifndef OBJECT_H
#define OBJECT_H

#include "Vect3D.h"

class Object
{
private:
	Vect3d Coord;	//Coordinate of the object

	float W, L, H;
	float w, l, h;
	float r, g, b, alpha;

public:

	Object()
	{
		w = l = h = 0.0;
		W = L = H = 0.0;
		r = g = b = alpha = 1;

		Coord.SetX(0.0);
		Coord.SetY(0.0);
		Coord.SetZ(0.0);
	}

	void SetColor(float red, float green, float blue, float al = 1.0)
	{
		r = red;
		g = green;
		b = blue;
		alpha = al;
	}

	void SetSize(float width, float length, float height )
	{
		W = width;
		L = length;
		H = height;
	}

	float GetCoordX()
	{
		return Coord.GetX();
	}

	float GetCoordY()
	{
		return Coord.GetY();
	}
	float GetCoordZ()
	{
		return Coord.GetZ();
	}

	void SetCoordX(float x)
	{
		Coord.SetX(x);
	}

	void SetCoordY(float y)
	{
		Coord.SetY(y);
	}

	void SetCoordZ(float z)
	{
		Coord.SetZ(z);
	}

	void SetCoord(float x, float y, float z)
	{
		Coord.Set(x, y, z);
	}


	/*
		'w' = the width of the object = x-axis
		'l' = the length of the object = z-axis
		'h' = the height of the object = y-axis

	*/

	void RenderObject()
	{
		float x = Coord.x();
		float y = Coord.y();
		float z = Coord.z();


		//Draw the bottom first
		glBegin(GL_QUADS);
			glColor4f(r, g, b, alpha);
			glVertex3f( x - (W/2), y, z + (L/2));
			glVertex3f( x - (W/2), y, z - (L/2));
			glVertex3f( x + (W/2), y, z - (L/2));
			glVertex3f( x + (W/2), y, z + (L/2));
		glEnd();

		if ( H > 0 )
		{
			
			glBegin(GL_QUADS);
				//Draw left side
				 glColor4f(r, g, b, alpha);
				 glVertex3f( x - (W/2), y, z + (L/2));
				 glVertex3f( x - (W/2), y, z - (L/2));
				 glVertex3f( x - (W/2), y+H, z - (L/2));
				 glVertex3f( x - (W/2), y+H, z + (L/2));


				 //Draw back side
				 glColor4f(r, g, b, alpha);
				 glVertex3f( x - (W/2), y, z - (L/2));
				 glVertex3f( x + (W/2), y, z - (L/2));
				 glVertex3f( x + (W/2), y+H, z - (L/2));
				 glVertex3f( x - (W/2), y+H, z - (L/2));

				 //Draw right side
				 glColor4f( r, g, b, alpha);
				 glVertex3f( x + (W/2), y, z + (L/2));
				 glVertex3f( x + (W/2), y, z - (L/2));
				 glVertex3f( x + (W/2), y+H, z - (L/2));
				 glVertex3f( x + (W/2), y+H, z + (L/2));

				 //Draw front side
				 glColor4f(r, g, b, alpha);
				 glVertex3f( x - (W/2), y, z + (L/2));
				 glVertex3f( x + (W/2), y, z + (L/2));
				 glVertex3f( x + (W/2), y+H, z + (L/2));
				 glVertex3f( x - (W/2), y+H, z + (L/2));

				 //Draw top side
				 glColor4f(r, g, b, alpha);
				 glVertex3f( x - (W/2), y+H, z + (L/2));
				 glVertex3f( x - (W/2), y+H, z - (L/2));
				 glVertex3f( x + (W/2), y+H, z - (L/2));
				 glVertex3f( x + (W/2), y+H, z + (L/2));

			glEnd();
		}


		//Draw the Border line of the object
			glBegin(GL_LINE_LOOP);
			//glColor4f(r, g, b, alpha);
			glColor4f(1, 1, 1, alpha);
			glVertex3f( x - (W/2), y, z + (L/2));
			glVertex3f( x - (W/2), y, z - (L/2));
			glVertex3f( x + (W/2), y, z - (L/2));
			glVertex3f( x + (W/2), y, z + (L/2));
		glEnd();

		if ( H > 0 )
		{
			
			glBegin(GL_LINE_LOOP);
				//Draw left side
				 //glColor4f(r, g, b, alpha);
				glColor4f(1, 1, 1, alpha);
				 glVertex3f( x - (W/2), y, z + (L/2));
				 glVertex3f( x - (W/2), y, z - (L/2));
				 glVertex3f( x - (W/2), y+H, z - (L/2));
				 glVertex3f( x - (W/2), y+H, z + (L/2));
			 glEnd();


				 //Draw back side
			 glBegin(GL_LINE_LOOP);
			 glColor4f(1, 1, 1, alpha);
				 //glColor4f(r, g, b, alpha);
				 glVertex3f( x - (W/2), y, z - (L/2));
				 glVertex3f( x + (W/2), y, z - (L/2));
				 glVertex3f( x + (W/2), y+H, z - (L/2));
				 glVertex3f( x - (W/2), y+H, z - (L/2));

				 glEnd();

				 glBegin(GL_LINE_LOOP);
				 //Draw right side
				 //glColor4f( r, g, b, alpha);
				 glColor4f(1, 1, 1, alpha);
				 glVertex3f( x + (W/2), y, z + (L/2));
				 glVertex3f( x + (W/2), y, z - (L/2));
				 glVertex3f( x + (W/2), y+H, z - (L/2));
				 glVertex3f( x + (W/2), y+H, z + (L/2));
				 glEnd();

				 //Draw front side
				 glBegin(GL_LINE_LOOP);
				 //glColor4f(r, g, b, alpha);
				 glColor4f(1, 1, 1, alpha);
				 glVertex3f( x - (W/2), y, z + (L/2));
				 glVertex3f( x + (W/2), y, z + (L/2));
				 glVertex3f( x + (W/2), y+H, z + (L/2));
				 glVertex3f( x - (W/2), y+H, z + (L/2));
				 glEnd();

				 //Draw top side
				 glBegin(GL_LINE_LOOP);
				 //glColor4f(r, g, b, alpha);
				 glColor4f(1, 1, 1, alpha);
				 glVertex3f( x - (W/2), y+H, z + (L/2));
				 glVertex3f( x - (W/2), y+H, z - (L/2));
				 glVertex3f( x + (W/2), y+H, z - (L/2));
				 glVertex3f( x + (W/2), y+H, z + (L/2));

			glEnd();
		}

	}

};


#endif