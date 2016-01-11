#include "DXHelper.h"

DXHelper::DXHelper() : initStatus(false), initValue(false)
{
	init();
}


DXHelper::~DXHelper()
{
}

//DXHelper::init returns true once it finds a D3D12 device and store the adapter in dxgiAdapter
bool DXHelper::init()
{
	//Prevent multiple calls to this function
	if (initStatus)
		return initValue;
	initStatus = true;

	IDXGIAdapter3* adapter = nullptr;

	//Create DXGIFactory and store it as IDXGIFACTORY4 (dxgi 1.4)
	if (FAILED(CreateDXGIFactory2(0, IID_PPV_ARGS(&dxgiFactory))))
		return false;

	//Loop on IDXGIAdapter3* and examine each adapter
	for (UINT adapterIndex = 0; DXGI_ERROR_NOT_FOUND != dxgiFactory->EnumAdapters1(adapterIndex, (IDXGIAdapter1**)&adapter); ++adapterIndex)
	{
		//Variable desc only usefull to examine adapter, set breakpoint to check contents
		DXGI_ADAPTER_DESC2 desc;
		adapter->GetDesc2(&desc);

		//Pick first device supporting D3D12
		if (SUCCEEDED(D3D12CreateDevice(adapter, D3D_FEATURE_LEVEL_11_0, __uuidof(ID3D12Device), nullptr)))
		{
			dxgiAdapter = adapter;
			initValue = true;
			return true;
		}

		//Release adapter to examine next adapter
		adapter->Release();
	}
	return false;
}