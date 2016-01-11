#pragma once

#include <Windows.h>
#include <DXGI1_4.h>
#include <d3d12.h>

class DXHelper
{
private:
	IDXGIFactory4* dxgiFactory;
	IDXGIAdapter3* dxgiAdapter;
	bool initStatus;
	bool initValue;
public:
	DXHelper();
	virtual ~DXHelper();
public:
	bool init();
	IDXGIAdapter3& getAdapter() const { return *dxgiAdapter; }
	IDXGIFactory4& getFactory() const { return *dxgiFactory; }
};
