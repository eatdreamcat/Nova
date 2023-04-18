#pragma once
#include <string>

class EngineBase
{
public :
	EngineBase(UINT width, UINT height, std::wstring name);
	virtual ~EngineBase();


	virtual void OnInit() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnDestroy() = 0;

	// Samples override the event handlers to handle specific messages.
	virtual void OnKeyDown(UINT8 /*key*/) {}
	virtual void OnKeyUp(UINT8 /*key*/) {}

	// Accessors.
	UINT GetWidth() const { return m_width; }
	UINT GetHeight() const { return m_height; }
	const WCHAR* GetTitle() const { return m_title.c_str(); }

protected:

	std::wstring GetAssetFullPath(LPCWSTR assetName);

	// Viewport dimensions.
	UINT m_width;
	UINT m_height;
	float m_aspectRatio;
private:
	// Window title.
	std::wstring m_title;
	// Root assets path.
	std::wstring m_assetsPath;
};