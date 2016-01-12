#include "DXWindow.h"
#include "Win32Application.h"

DXWindow::DXWindow(IDXGIFactory4 & factory, IDXGIAdapter3 & adapter, UINT width, UINT height) : _factory(factory), _adapter(adapter), _width(width), _height(height), initStatus(false), initValue(false)
{
	_title = "DX12-HelloWorld";
}


DXWindow::~DXWindow()
{
}

bool DXWindow::init()
{
	//Prevent multiple calls to this function
	if (initStatus)
		return initValue;
	initStatus = true;
	
	if (FAILED(D3D12CreateDevice(&_adapter, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&_device))))
		return false;

	D3D12_COMMAND_QUEUE_DESC queueDesc = {};
	queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
	queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;

	if (FAILED(_device->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&_commandQueue))))
		return false;

	DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {};
	swapChainDesc.Width = _width;
	swapChainDesc.Height = _height;
	swapChainDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.Stereo = false;
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.BufferCount = FrameCount;
	swapChainDesc.Scaling = DXGI_SCALING_NONE;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	swapChainDesc.AlphaMode = DXGI_ALPHA_MODE_UNSPECIFIED;
	swapChainDesc.Flags = 0;

	if (FAILED(_factory.CreateSwapChainForHwnd(_commandQueue, Win32Application::GetHwnd(), &swapChainDesc, NULL, NULL, (IDXGISwapChain1**)&_swapChain)))
		return false;

	if (FAILED(_factory.MakeWindowAssociation(Win32Application::GetHwnd(), DXGI_MWA_NO_ALT_ENTER)))
		return false;

	_frameIndex = _swapChain->GetCurrentBackBufferIndex();

	initValue = true;
	return true;
}