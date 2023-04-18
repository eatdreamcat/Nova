#pragma once
#include "EngineBase.h"


class EngineBase;
class Win32Application
{
public:
	static int Run(EngineBase* pEngine, HINSTANCE hInstance, int mCmdShow);
	static HWND GetHwnd() { return m_hwnd; }
protected:
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
private:
	static HWND m_hwnd;
};

