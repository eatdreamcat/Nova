#pragma once
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers.
#endif

#include <windows.h>

#include <D3d12.h>
#include <wrl.h>
using namespace Microsoft;
using namespace Microsoft::WRL;

#define D3DCOMPILE_DEBUG 1

