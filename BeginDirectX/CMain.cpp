#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

#include "CMain.h"
#include "CWindow.h"
#include "CGame.h"

//the entry point for any Windows program
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{	
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	HRESULT hr = S_OK;

	m_hInstance = hInstance;

	// return this part of the WM_QUIT message to Windows
	CGame* game = new CGame();
	game->Run();

	_CrtDumpMemoryLeaks();
	UNREFERENCED_PARAMETER(lpCmdLine);

	return hr;
}

