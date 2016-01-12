#include <iostream>
#include <Windows.h>
#include "DXHelper.h"
#include "DXWindow.h"
#include "Win32Application.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
	DXHelper dxhelper;
	if (dxhelper.init())
	{
		OutputDebugString("Initialized dxhelper\n");
		DXWindow window(dxhelper.getFactory(), dxhelper.getAdapter());
		return Win32Application::Run(window, hInstance, nCmdShow);
	}
	else
		OutputDebugString("Error initialize dxhelper\n");
	return -1;
}