#include"stdafx.h"
#include"Engine.h"
#include "Win32Application.h"


#if defined(_DEBUG)

#include <io.h>
#include <fcntl.h>
#include <iostream>


// TODO:  Õ∑≈
void RedirectIOToConsole(void)
{
    AllocConsole();

    // Get the handle for STDOUT's file system.
    HANDLE stdOutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    // Redirect STDOUT to the new console by associating STDOUT's file
    // descriptor with an existing operating-system file handle.
    int hConsoleHandle = _open_osfhandle((intptr_t)stdOutputHandle, _O_TEXT);

    FILE* pFile = _fdopen(hConsoleHandle, "w");

    *stdout = *pFile;
    freopen_s(&pFile, "CONIN$", "r+t", stdout);
    freopen_s(&pFile, "CONOUT$", "w+t", stdout);

    setvbuf(stdout, NULL, _IONBF, 0);

    // This call ensures that iostream and C run-time library operations occur 
    // in the order that they appear in source code.
    std::ios::sync_with_stdio();

}

#endif

using namespace std;


_Use_decl_annotations_ // use to override default SAL
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{

#if defined(_DEBUG)
    RedirectIOToConsole();
#endif
    std::cout << "WinMain:" <<hInstance->unused<< std::endl;
	auto engine = Engine(1280, 720, L"Hello Nove", D3D_FEATURE_LEVEL_11_0);
	return Win32Application::Run(&engine, hInstance, nCmdShow);
}