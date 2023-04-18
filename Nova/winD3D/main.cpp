#include"stdafx.h"
#include"Engine.h"
#include "Win32Application.h"

_Use_decl_annotations_ // use to override default SAL
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
	auto engine = Engine(1280, 720, L"Hello Nove");
	return Win32Application::Run(&engine, hInstance, nCmdShow);
}