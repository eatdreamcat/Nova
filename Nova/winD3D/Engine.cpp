#include "stdafx.h"
#include "Engine.h"

Engine::Engine(UINT width, UINT height, std::wstring name) :
    EngineBase(width, height, name),
    m_frameIndex(0),
    m_rtvDescriptorSize(0)
{
}

void Engine::OnInit()
{
  
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