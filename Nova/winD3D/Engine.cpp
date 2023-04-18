#include "stdafx.h"
#include "Engine.h"



Engine::Engine(UINT width, UINT height, std::wstring name, D3D_FEATURE_LEVEL d3dFeatureLevel) :
    EngineBase(width, height, name, d3dFeatureLevel),
    m_frameIndex(0),
    m_rtvDescriptorSize(0),
    m_fenceValue(0),
    m_fenceEvent(nullptr),
    m_fence(nullptr) 
{
}

void Engine::OnInit()
{
    LoadPipeline();
    LoadAssets();
}

void Engine::OnUpdate()
{

}

void Engine::OnRender()
{

}

void Engine::OnDestroy()
{

}

// Load the rendering pipeline dependencies.
void Engine::LoadPipeline()
{
    UINT dxgiFactoryFlags = 0;

#if defined(_DEBUG)
    // Enable the debug layer (requires the Graphics Tools "optional feature").
    // NOTE: Enabling the debug layer after device creation will invalidate the active device.
    {
        ComPtr<ID3D12Debug> debugController;
        if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController))))
        {
            debugController->EnableDebugLayer();

            // Enable additional debug layers.
            dxgiFactoryFlags |= DXGI_CREATE_FACTORY_DEBUG;
        }
    }
#endif

    ComPtr<IDXGIFactory4> factory;
    ThrowIfFailed(CreateDXGIFactory2(dxgiFactoryFlags, IID_PPV_ARGS(&factory)));

    if (m_useWarpDevice)
    {
        ComPtr<IDXGIAdapter> warpAdapter;
        ThrowIfFailed(factory->EnumWarpAdapter(IID_PPV_ARGS(&warpAdapter)));

        ThrowIfFailed(D3D12CreateDevice(
            warpAdapter.Get(),
            m_D3DFeatureLevel,
            IID_PPV_ARGS(&m_device)
        ));
    }
    else
    {
        ComPtr<IDXGIAdapter1> hardwareAdapter;
        GetHardwareAdapter(factory.Get(), &hardwareAdapter);

        ThrowIfFailed(D3D12CreateDevice(
            hardwareAdapter.Get(),
            m_D3DFeatureLevel,
            IID_PPV_ARGS(&m_device)
        ));
    }
}

// Load the sample assets.
void Engine::LoadAssets()
{

}