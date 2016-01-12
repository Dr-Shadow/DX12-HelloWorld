#pragma once

#include <Windows.h>
#include <DXGI1_4.h>
#include <d3d12.h>
#include <string>

class DXWindow
{
private:
	IDXGIFactory4& _factory;
	IDXGIAdapter3& _adapter;
	ID3D12Device* _device;
	ID3D12CommandQueue* _commandQueue;
	IDXGISwapChain3* _swapChain;
	std::string _title;
	UINT _width;
	UINT _height;
	bool initStatus;
	bool initValue;
	static const UINT FrameCount = 2;
	UINT _frameIndex;
public:
	DXWindow() = delete;
	DXWindow(IDXGIFactory4 &, IDXGIAdapter3 &, UINT = 1280, UINT = 720);
	virtual ~DXWindow();
public:
	bool init();
	UINT getWidth() const { return _width; }
	UINT getHeight() const { return _height; }
	const char* GetTitle() const { return _title.c_str(); }
};

