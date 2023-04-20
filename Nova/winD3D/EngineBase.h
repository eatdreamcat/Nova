#pragma once

#include"Helper.h"
#include "Win32Application.h"

class EngineBase
{
public :
	EngineBase(UINT width, UINT height, std::wstring name, D3D_FEATURE_LEVEL d3dFeatureLevel);
	virtual ~EngineBase();


	virtual void OnInit() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnRender() = 0;
	virtual void OnDestroy() = 0;

	// Samples override the event handlers to handle specific messages.
	virtual void OnKeyDown(UINT8 /*key*/) {}
	virtual void OnKeyUp(UINT8 /*key*/) {}

	// Accessors.
	UINT GetWidth() const { return m_width; }
	UINT GetHeight() const { return m_height; }

	D3D_FEATURE_LEVEL GetFeatureLevel() const { return m_D3DFeatureLevel; }

	void SetWidth(UINT width) { m_width = width; }
	void SetHeight(UINT height) { m_height = height; }
	void UpdateAspectRatio() { m_aspectRatio = static_cast<float>(m_width) / static_cast<float>(m_height); }

	const WCHAR* GetTitle() const { return m_title.c_str(); }

	void ParseCommandLineArgs(_In_reads_(argc) WCHAR* argv[], int argc);

protected:

	std::wstring GetAssetFullPath(LPCWSTR assetName);

	void GetHardwareAdapter(
		_In_ IDXGIFactory1* pFactory,
		_Outptr_result_maybenull_ IDXGIAdapter1** ppAdapter,
		bool requestHighPerformanceAdapter = false);

	void SetCustomWindowText(LPCWSTR text);

	// Viewport dimensions.
	UINT m_width;
	UINT m_height;
	float m_aspectRatio;

	// Adapter info. 是否使用集成显卡
	bool m_useWarpDevice;

	// level
	D3D_FEATURE_LEVEL m_D3DFeatureLevel;
private:
	// Window title.
	std::wstring m_title;
	// Root assets path.
	std::wstring m_assetsPath;
};
