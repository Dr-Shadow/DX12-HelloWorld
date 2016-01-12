#pragma once

#include <Windows.h>
#include "DXWindow.h"

class Win32Application
{
public:
	static int Run(DXWindow& pWindow, HINSTANCE hInstance, int nCmdShow);
	static HWND GetHwnd() { return _hwnd; }

protected:
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	static HWND _hwnd;
};
