#include "CGame.h"
#include "CMacro.h"

CGame::CGame()
{
	m_pWindow = NULL;
	m_pDirectx = NULL;
	this->Init();
}

CGame::~CGame()
{

}

bool CGame::Init()
{
	m_pWindow = new CWindow();
	m_pDirectx = new CDirectx();

	HRESULT hr;

	hr = m_pWindow->CreateDesktopWindow(false);
	if (FAILED(hr))
	{
		return false;
	}

	hr = m_pDirectx->InitD3D(*m_pWindow, false);
	if (FAILED(hr))
	{
		return false;
	}

	return true;
}

void CGame::Run()
{
	if (!Init())
	{
		return;
	}

	HRESULT hr = S_OK;

	if (!IsWindowVisible(m_pWindow->GetWindowHandle()))
	{
		ShowWindow(m_pWindow->GetWindowHandle(), SW_SHOW);
	}

	// The render loop is controlled here.
	//bool bGotMsg;
	MSG  msg;
	//msg.message = WM_NULL;
	//PeekMessage(&msg, NULL, 0U, 0U, PM_NOREMOVE);

	while (true)
	{
		// Process window events.

		while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// Translate and dispatch the message
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (msg.message == WM_QUIT)
			break;

			// Update the scene.
			//renderer->Update();

			// Render frames during idle time (when no messages are waiting).
			//renderer->Render();
			m_pDirectx->Render();

			// Present the frame to the screen.
			//deviceResources->Present();
	}


	this->Destroy(); 
}

void CGame::Destroy()
{
	SAFE_DELETE(m_pWindow);
	SAFE_DELETE(m_pDirectx);
}