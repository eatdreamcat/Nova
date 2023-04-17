#include"stdafx.h"
#include "WindowBase.h"
#include "Helper.h"

using namespace Microsoft::WRL;

WindowBase::WindowBase(UINT width, UINT height, std::wstring name) :
	m_width(width),
	m_height(height),
	m_title(name)
{
	WCHAR assetsPath[512];
	GetAssetsPath(assetsPath, _countof(assetsPath));
	m_assetsPath = assetsPath;

	m_aspectRatio = static_cast<float>(width) / static_cast<float>(height);
}

WindowBase::~WindowBase()
{

}

// Helper function for resolving the full path of assets.
std::wstring WindowBase::GetAssetFullPath(LPCWSTR assetName)
{
	return m_assetsPath + assetName;
}