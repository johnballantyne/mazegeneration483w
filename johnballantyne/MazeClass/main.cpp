#include <stdlib.h>
#include <stdio.h>
#include "glut.h"
#include "Maze.h"
#include <windows.h>

#include "Vect3D.h"
#include "Object.h"

#define WIDTH 800
#define HEIGHT 600

//ADDED*************
#define MAZEW 12
#define MAZEL 12
int SizeOfMaze, GenAlgor, SolutionAlgor;


int Q = 3;
int S = 0;
//*************ADDED

bool TOPVIEW = false;

float angle = 0.0;
float DeltaAngle = 0.0;
int CameraMove = 0, SpecialKey;

Object Ground;		//Drawing the ground floor

//MODIFIED**********
Object Wall[(MAZEW*4+1)*(MAZEL*4+1)];
//**********MODIFIED

//ADDED*************
Maze maze(MAZEW, MAZEL);
//*************ADDED

Vect3d CamPos(0, 150, 0);		//Where the camera position is at, aka where the position where we look
Vect3d LookAtPos(0, 0, 0);	//The position that we're looking at

Vect3d LookDirection;
Vect3d Camera;
Vect3d LookAt;
Vect3d UpDirection(0, 0, -1);	//up down position of the camera


float mouseDX = 0, mouseDY;


void Init(char* windowTitle)
{
	//ADDED*************
	maze.initMaze(6, 6);
	maze.GenMaze_Recursive();
	//*************ADDED

	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow(windowTitle);
	glEnable(GL_LINE_SMOOTH);

	//ADDED*************
	int i1 = -1*MAZEL*2;
	int j1 = -1*MAZEW*2;
	for (int i=0; i<MAZEL*4+1; i++)
	{
		j1=-1*MAZEL;
		for (int j=0; j<MAZEL*4+1; j++)
		{
			if (maze.checkCoordinate(i, j))
			{
				Wall[S].SetCoord(j1*Q, 0, i1*Q);
				//printf("%d %d | ", j1*Q, i1*Q);
				//Wall[S].SetColor(rand()/(float)RAND_MAX, rand()/(float)RAND_MAX, rand()/(float)RAND_MAX, 0.3f);
				Wall[S].SetColor(1, 0, 0, 1);
				S++;
			}
			j1++;
		}
		i1++;
	}
	Wall[++S].SetCoord(0, 0, 0);
	Wall[S].SetColor(1, 1, 1, 1);
	//*************ADDED


/*
	for(int i=0; i<4; i++)
		Wall[i].SetColor(0, 1, 1, 0.3f);*/




	Ground.SetColor(0.5, 0.5, 0.5);
	Ground.SetCoord(0, 0, 0);

		Camera.SetCoord(0, 0, 5);	//set camera 5 unit toward the screen and center
		LookDirection.SetCoord(0, 0, 5);	//look 5 unit toward the screen
		UpDirection.SetCoord(0, -1, 0);		//Up direction point upward, that's why it's negative y
		LookAt = Camera + LookDirection;


	glLoadIdentity();
	gluLookAt(Camera.GetX(), Camera.GetY(), Camera.GetZ(),
				LookAt.GetX(), LookAt.GetY(), LookAt.GetZ(),
				UpDirection.GetX(), UpDirection.GetY(), UpDirection.GetZ());
				

	Ground.SetCoordY(5);

}


void RotY(float ang)	//Rotate the camera around the y-axis
{

	//This will rotate the camera around the origin axis
	
	//The rotation here is using Rotation Matrix around the Y-axis


	// (New Camera Position) = RotationMatrix * (Old Camera Position)
	/*
		| cos(ang)    0     -sin(ang)   0  |   | CamX |
		|    0        1        0        0  |   | CamY |
		| sin(ang)    0      cos(ang)   0  | * | CamZ |
		|    0        0        0        1  |   |  1   |
	*/

	Camera.SetCoord( Camera.GetX()*cos(ang) - Camera.GetZ()*sin(ang) ,
					 Camera.GetY(),
					 Camera.GetX()*sin(ang) + Camera.GetZ()*cos(ang) ) ;
	//Translated the camera, but we have to translate the Look direction as well
	LookDirection.SetCoord( LookDirection.GetX()*cos(ang) - LookDirection.GetZ()*sin(ang),
							LookDirection.GetY(),
							LookDirection.GetX()*sin(ang) + LookDirection.GetZ()*cos(ang));

	//Then we can find out the point where we are looking at

	LookAt = Camera + LookDirection;


}

void RotX(float ang)
{

}

void RotZ(float ang)
{
	

}


void MoveStraight(int direction)	//if the user move forward or backward
{

	Camera.SetCoord( Camera.GetX() + LookDirection.GetX()*direction*0.1,
					 Camera.GetY() + LookDirection.GetY()*direction*0.1,
					 Camera.GetZ() + LookDirection.GetZ()*direction*0.1);
	LookAt = Camera + LookDirection;

	printf("Camera position (%3.1f, %3.1f, %3.1f)\n", Camera.GetX(), Camera.GetY(), Camera.GetZ());
	printf("Look at position (%3.1f, %3.1f, %3.1f)\n", LookAt.GetX(), LookAt.GetY(), LookAt.GetZ());
	printf("Look Direction (%3.1f, %3.1f, %3.1f)\n\n", LookDirection.GetX(), LookDirection.GetY(), LookDirection.GetZ());

}


void NormalKeyPress(unsigned char key, int x, int y)
{
	if ( key == 27 )	//if user press 'Escape' button
		exit(0);

	if ( key == 'r')	//reset the view
	{
		
		Camera.SetCoord(0, 0, 5);	//set camera 5 unit toward the screen and center
		LookDirection.SetCoord(0, 0, 5);	//look 5 unit toward the screen
		UpDirection.SetCoord(0, -1, 0);		//Up direction point upward, that's why it's negative y
		LookAt = Camera + LookDirection;
		TOPVIEW = false;

	}



	if ( key == 'u')	//reset viewport to looking up from the top view
	{

		Camera.SetCoord(0, 150, 0);		//Set camera on top view
		LookDirection.SetCoord(0, -5, 0);	//Look down 5 units (positive y direction)
		UpDirection.SetCoord(0, 0, -1);		//Now the up direction will be toward the negative z axis
		LookAt = Camera + LookDirection;
		TOPVIEW = true;
	}


}

void PressKey(int key, int x, int y)	//special keys are pressed
{
	switch ( key )
	{
		case GLUT_KEY_LEFT:
			DeltaAngle = 0.01;
			break;
		case GLUT_KEY_RIGHT:
			DeltaAngle = -0.01;
			break;
		case GLUT_KEY_UP:
			CameraMove = 1;
			break;
		case GLUT_KEY_DOWN:			
			CameraMove = -1;
			break;
	}
}

void ReleaseKey(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_LEFT:
			DeltaAngle = 0;
			break;			
		case GLUT_KEY_RIGHT:
			DeltaAngle = 0;
			break;
		case GLUT_KEY_UP:
			CameraMove = 0;
			break;
		case GLUT_KEY_DOWN:
			CameraMove = 0;
			break;
	}
}


void Resize(int w, int h)
{
	if ( h == 0)
		h = 1;

	float ratio = 1.0*w / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);

	gluPerspective(45, ratio, 1, 10000);
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	gluLookAt(Camera.GetX(), Camera.GetY(), Camera.GetZ(),
				LookAt.GetX(), LookAt.GetY(), LookAt.GetZ(),
				UpDirection.GetX(), UpDirection.GetY(), UpDirection.GetZ());


}

void DrawScene()
{



	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
	glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//Draw the ground surface

	if ( DeltaAngle )
	{
		angle = DeltaAngle;
		RotY(angle);
		printf("Look Direction (%3.1f, %3.1f, %3.1f)\n\n", LookDirection.GetX(), LookDirection.GetY(), LookDirection.GetZ());
	}
	if ( CameraMove )
		MoveStraight(CameraMove);

	glLoadIdentity();
	gluLookAt(Camera.GetX(), Camera.GetY(), Camera.GetZ(),
				LookAt.GetX(), LookAt.GetY(), LookAt.GetZ(),
				UpDirection.GetX(), UpDirection.GetY(), UpDirection.GetZ());


	//Ground.DrawObject(MAZEW*10, 0, MAZEL*10);

	for (int i=0; i<S; i++)
		Wall[i].DrawObject(Q, Q, Q);
	
	//Wall[S].SetCoordX(Wall[S].GetCoordX()+1);
	

	glutSwapBuffers();

}

void ProcessActiveMouse(int x, int y)
{
	float mouseToAngle = (mouseDX - x)*0.005f;		//Find out the angle for rotation
	RotY(mouseToAngle);
	printf("Look Direction (%3.1f, %3.1f, %3.1f)\n\n", LookDirection.GetX(), LookDirection.GetY(), LookDirection.GetZ());	//Just for testing
	mouseDX = x;

}

void ProcessMouse(int button, int state, int x, int y)
{

	if ( state == GLUT_DOWN )
	{
		mouseDX = x;			//Monitor the position of the mouse on the screen
	}

	
}


int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	Init("Maze Navigator");

	SizeOfMaze = argv[1];
	GenAlgor = argv[2];
	SolutionAlgor = argv[3];

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(NormalKeyPress);
//	glutSpecialFunc(processSpecialKeys);
	glutSpecialFunc(PressKey);
	glutSpecialUpFunc(ReleaseKey);

	glutMotionFunc(ProcessActiveMouse);
	glutMouseFunc(ProcessMouse);

	glutDisplayFunc(DrawScene);
	glutIdleFunc(DrawScene);
	glutReshapeFunc(Resize);

	printf("Up direction %5.2f, %5.2f, %5.2f\n", UpDirection.GetX(), UpDirection.GetY(), UpDirection.GetZ());


	glutMainLoop();



	return 0;
}