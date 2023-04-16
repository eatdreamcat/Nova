#pragma once
#include <string>

class WindowBase
{
public :
	WindowBase(UINT width, UINT height, std::wstring name);
	virtual ~WindowBase();

	// Accessors.
	UINT GetWidth() const { return m_width; }
	UINT GetHeight() const { return m_height; }
	const WCHAR* GetTitle() const { return m_title.c_str(); }s

protected:
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

