#include <stdlib.h>
#include <stdio.h>
#include <gl/glut.h>


#include "Vect3D.h"
#include "Object.h"
#include "Cube.h"
#include "camera.h"

#define WIDTH 800
#define HEIGHT 600

bool TOPVIEW = false;

float angle = 0.0;
float DeltaAngle = 0.0;
int CameraMove = 0, SpecialKey;

Object Ground;		//Drawing the ground floor
Object Wall[4];
Cube MyCube;

Vect3d CamPos(0, 0, 0);		//Where the camera position is at, aka where the position where we look
Vect3d LookAtPos(0, 0, -1);	//The position that we're looking at

Vect3d LookDirection;
Vect3d camera;
Vect3d LookAt;
Vect3d UpDirection(0, 1, 0);	//up down position of the camera

Camera MyCamera;


float mouseDX = 0, mouseDY;


void Init(char* windowTitle)
{
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow(windowTitle);
	glEnable(GL_LINE_SMOOTH);


	
	//Left wall top view
	Wall[0].SetCoord(-25, 0, 0);
	Wall[0].SetSize(5, 50, 5);
	Wall[0].SetColor(1, 0, 0, 0.3);		

	
	//Right wall top view
	Wall[1].SetCoord(25, 0, 0);
	Wall[1].SetSize(5, 50, 5);
	Wall[1].SetColor(0, 1, 0, 0.3);

	
	//Top wall top view
	Wall[2].SetCoord(0, 0, -25);
	Wall[2].SetSize(50, 5, 5);
	Wall[2].SetColor(0, 0, 1, 0.3);

	
	//bottom wall top view
	Wall[3].SetCoord(0, 0, 25);
	Wall[3].SetSize(50, 5, 5);
	Wall[3].SetColor(0, 1, 1, 0.3);

	Ground.SetColor(0, 0.3, 0.3);
	Ground.SetCoord(0, -5, 0);
	Ground.SetSize(50, 50, 5);

	MyCube.SetColor(1, 1, 1);

		camera.SetCoord(0, 0, 5);	//set camera 5 unit toward the screen and center
		LookDirection.SetCoord(0, 0, -1);	//look 5 unit toward the screen
		UpDirection.SetCoord(0, 1, 0);		//Up direction point upward, that's why it's negative y
		LookAt = camera + LookDirection;


	glLoadIdentity();
	gluLookAt(camera.GetX(), camera.GetY(), camera.GetZ(),
				LookAt.GetX(), LookAt.GetY(), LookAt.GetZ(),
				UpDirection.GetX(), UpDirection.GetY(), UpDirection.GetZ());
				



}


void RotY(float ang)	//Rotate the camera around the y-axis
{

	//This will rotate the camera around the origin axis
	
	//The rotation here is using Rotation Matrix around the Y-axis


	// (New camera Position) = RotationMatrix * (Old camera Position)
	/*
		| cos(ang)    0     -sin(ang)   0  |   | CamX |
		|    0        1        0        0  |   | CamY |
		| sin(ang)    0      cos(ang)   0  | * | CamZ |
		|    0        0        0        1  |   |  1   |
	*/
/*
	camera.SetCoord( camera.GetX()*cos(ang) - camera.GetZ()*sin(ang) ,
					 camera.GetY(),
					 camera.GetX()*sin(ang) + camera.GetZ()*cos(ang) ) ;*/
	//Translated the camera, but we have to translate the Look direction as well
	LookDirection.SetCoord( LookDirection.GetX()*cos(ang) - LookDirection.GetZ()*sin(ang),
							LookDirection.GetY(),
							LookDirection.GetX()*sin(ang) + LookDirection.GetZ()*cos(ang));

	//Then we can find out the point where we are looking at

	LookAt = camera + LookDirection;


}




void MoveStraight(int direction)	//if the user move forward or backward
{

	MyCamera.MoveStraight(direction*0.1);

	camera.SetCoord( camera.GetX() + LookDirection.GetX()*direction*0.1,
					 camera.GetY() + LookDirection.GetY()*direction*0.1,
					 camera.GetZ() + LookDirection.GetZ()*direction*0.1);
	LookAt = camera + LookDirection;

	printf("camera position (%3.1f, %3.1f, %3.1f)\n", camera.GetX(), camera.GetY(), camera.GetZ());
	printf("Look at position (%3.1f, %3.1f, %3.1f)\n", LookAt.GetX(), LookAt.GetY(), LookAt.GetZ());
	printf("Look Direction (%3.1f, %3.1f, %3.1f)\n\n", LookDirection.GetX(), LookDirection.GetY(), LookDirection.GetZ());

}


void NormalKeyPress(unsigned char key, int x, int y)
{
	if ( key == 27 )	//if user press 'Escape' button
		exit(0);

	if ( key == 'r')	//reset the view
	{
		TOPVIEW = false;
		MyCamera.ThirdPersonCamera();

	}



	if ( key == 'u')	//reset viewport to looking up from the top view
	{
		MyCamera.TopViewCamera();
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
	gluLookAt(camera.GetX(), camera.GetY(), camera.GetZ(),
				LookAt.GetX(), LookAt.GetY(), LookAt.GetZ(),
				UpDirection.GetX(), UpDirection.GetY(), UpDirection.GetZ());


}

void DrawScene()
{



	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH);
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
		MyCamera.MoveStraight(CameraMove*0.1);


	MyCamera.SetCamera();

//	Ground.DrawObject(100, 100, 0);

	Ground.RenderObject();
	for ( int i=0; i<4; i++ )
		Wall[i].RenderObject();


	//Draw the maze section here//
	//==========================//

//	MyCube.DrawCube(1);



	glutSwapBuffers();

}

void ProcessActiveMouse(int x, int y)
{
	float mouseToAngleY = (mouseDX - x)*0.005f;		//Find out the angle for rotation
	//RotY(mouseToAngleY);

	MyCamera.RotateY(mouseToAngleY);
	//float mouseToAngleX = (mouseDY - y)*0.005f;
	//RotX(mouseToAngleX);
	//MyCamera.RotateX(mouseToAngleX);
	printf("Look Direction (%3.1f, %3.1f, %3.1f)\n\n", LookDirection.GetX(), LookDirection.GetY(), LookDirection.GetZ());	//Just for testing
	mouseDX = x;
	mouseDY = y;

}

void ProcessMouse(int button, int state, int x, int y)
{

	if ( state == GLUT_DOWN )
	{
		mouseDX = x;			//Monitor the position of the mouse on the screen
		mouseDY = y;
	}

	
}


int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	Init("Maze Navigator");

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