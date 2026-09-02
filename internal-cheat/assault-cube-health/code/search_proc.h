#pragma once 

#include "includes.h"
#include <Windows.h>


//on initialise nos prototypes de fonctions
DWORD GetProcessID(const wchar_t* procName);
DWORD GetModuleBaseAddress(DWORD procId, const wchar_t* modName);

