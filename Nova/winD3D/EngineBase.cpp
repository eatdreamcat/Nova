#include"stdafx.h"
#include "EngineBase.h"

using namespace Microsoft::WRL;

EngineBase::EngineBase(UINT width, UINT height, std::wstring name):
	m_width(width),
	m_height(height),
	m_title(name),

