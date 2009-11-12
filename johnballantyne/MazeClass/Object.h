#ifndef OBJECT_H
#define OBJECT_H

#include "Vect3D.h"

class Object
{
private:
	Vect3d coord;	//Coordinate of the object

	float w, l, h;
	float r, g, b, alpha;

public:

	Object()
	{
		w = l = h = 0.0;
		r = g = b = alpha = 1;

		coord.SetX(0.0);
		coord.SetY(0.0);
		coord.SetZ(0.0);
	}

	void SetColor(float red, float green, float blue, float al = 1.0)
	{
		r = red;
		g = green;
		b = blue;
		alpha = al;
	}

	float GetCoordX()
	{
		return coord.GetX();
	}

	float GetCoordY()
	{
		return coord.GetY();
	}
	float GetCoordZ()
	{
		return coord.GetZ();
	}

	void SetCoordX(float x)
	{
		coord.SetX(x);
	}

	void SetCoordY(float y)
	{
		coord.SetY(y);
	}

	void SetCoordZ(float z)
	{
		coord.SetZ(z);
	}

	void SetCoord(float x, float y, float z)
	{
		coord.SetCoord(x, y, z);
	}


	/*
		'w' = the width of the object = x-axis
		'l' = the length of the object = z-axis
		'h' = the height of the object = y-axis

	*/
	
	void DrawObject(float w, float l, float h = 0.0)
	{
		float x = coord.GetX();
		float y = coord.GetY();
		float z = coord.GetZ();

		//Draw the surface of the box
		glColor4f(r, g, b, alpha);
		glBegin(GL_QUADS);
			glVertex3f( x-(w/2), y-(l/2), z+(h/2));		//(y-l/2) = (y - L/2) not (y - 1/2)
			glVertex3f( x+(w/2), y-(l/2), z+(h/2));
			glVertex3f( x+(w/2), y+(l/2), z+(h/2));
			glVertex3f( x-(w/2), y+(l/2), z+(h/2));

						//if the depth of the object is 0, we don't need to draw the other sides
			if ( h != 0 )
			{
				//Left side
				//glColor3f(1, 1, 1);
				glVertex3f( x-(w/2), y-(l/2), z+(h/2));
				glVertex3f( x-(w/2), y-(l/2), z-(h/2));
				glVertex3f( x-(w/2), y+(l/2), z-(h/2));
				glVertex3f( x-(w/2), y+(l/2), z+(h/2));

				//Back side
				glVertex3f( x-(w/2), y-(l/2), z-(h/2));
				glVertex3f( x+(w/2), y-(l/2), z-(h/2));
				glVertex3f( x+(w/2), y+(l/2), z-(h/2));
				glVertex3f( x-(w/2), y+(l/2), z-(h/2));

				//Right side
				glVertex3f( x+(w/2), y-(l/2), z+(h/2));
				glVertex3f( x+(w/2), y-(l/2), z-(h/2));
				glVertex3f( x+(w/2), y+(l/2), z-(h/2));
				glVertex3f( x+(w/2), y+(l/2), z+(h/2));

				//Top side
				glVertex3f( x-(w/2), y+(l/2), z+(h/2));
				glVertex3f( x-(w/2), y+(l/2), z-(h/2));
				glVertex3f( x+(w/2), y+(l/2), z-(h/2));
				glVertex3f( x+(w/2), y+(l/2), z+(h/2));

				//Bottom side
				//glColor4f(1, 1, 1, 0.1);
				glVertex3f( x-(w/2), y-(l/2), z+(h/2));
				glVertex3f( x-(w/2), y-(l/2), z-(h/2));
				glVertex3f( x+(w/2), y-(l/2), z-(h/2));
				glVertex3f( x+(w/2), y-(l/2), z+(h/2));

			}

		glEnd();



		//Draw the border of the box
		//draw front side
		glBegin(GL_LINE_LOOP);
			glVertex3f( x-(w/2), y-(l/2), z+(h/2));
			glVertex3f( x+(w/2), y-(l/2), z+(h/2));
			glVertex3f( x+(w/2), y+(l/2), z+(h/2));
			glVertex3f( x-(w/2), y+(l/2), z+(h/2));
			glEnd();

						//if the depth of the object is 0, we don't need to draw the other sides
			if ( h != 0 )
			{
				glBegin(GL_LINE_LOOP);
				//Left side
				//glColor3f(1, 1, 1);
				glVertex3f( x-(w/2), y-(l/2), z+(h/2));
				glVertex3f( x-(w/2), y-(l/2), z-(h/2));
				glVertex3f( x-(w/2), y+(l/2), z-(h/2));
				glVertex3f( x-(w/2), y+(l/2), z+(h/2));
				glEnd();

				glBegin(GL_LINE_LOOP);

				//Back side
				glVertex3f( x-(w/2), y-(l/2), z-(h/2));
				glVertex3f( x+(w/2), y-(l/2), z-(h/2));
				glVertex3f( x+(w/2), y+(l/2), z-(h/2));
				glVertex3f( x-(w/2), y+(l/2), z-(h/2));
				glEnd();

				glBegin(GL_LINE_LOOP);

				//Right side
				glVertex3f( x+(w/2), y-(l/2), z+(h/2));
				glVertex3f( x+(w/2), y-(l/2), z-(h/2));
				glVertex3f( x+(w/2), y+(l/2), z-(h/2));
				glVertex3f( x+(w/2), y+(l/2), z+(h/2));
				glEnd();

				glBegin(GL_LINE_LOOP);

				//Top side
				glVertex3f( x-(w/2), y+(l/2), z+(h/2));
				glVertex3f( x-(w/2), y+(l/2), z-(h/2));
				glVertex3f( x+(w/2), y+(l/2), z-(h/2));
				glVertex3f( x+(w/2), y+(l/2), z+(h/2));
				glEnd();

				glBegin(GL_LINE_LOOP);

				//Bottom side
				//glColor4f(1, 1, 1, 0.1);
				glVertex3f( x-(w/2), y-(l/2), z+(h/2));
				glVertex3f( x-(w/2), y-(l/2), z-(h/2));
				glVertex3f( x+(w/2), y-(l/2), z-(h/2));
				glVertex3f( x+(w/2), y-(l/2), z+(h/2));
		glEnd();
			}


	}





};


#endif