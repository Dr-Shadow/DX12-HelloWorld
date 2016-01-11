#include <iostream>
#include <Windows.h>
#include "DXHelper.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
	DXHelper dxhelper;
	if (dxhelper.init())
	{
		OutputDebugString("Initialized dxhelper\n");
	}
	else
		OutputDebugString("Error initialize dxhelper\n");
	return 0;
}