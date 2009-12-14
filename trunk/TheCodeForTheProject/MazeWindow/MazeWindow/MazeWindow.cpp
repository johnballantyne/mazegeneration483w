// MazeWindow.cpp : main project file.

#include "stdafx.h"
#include "MazeForm.h"

using namespace MazeWindow;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew MazeForm());
	return 0;
}
