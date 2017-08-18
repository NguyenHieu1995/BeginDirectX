#include "CGame.h"
#include "CMacro.h"
#include "CObject.h"

CGame::CGame()
{
	m_pWindow = NULL;
	m_pDirectx = NULL;
	m_pGraphics = NULL;
	m_pFrameTime = NULL;
}

CGame::~CGame()
{

}

bool CGame::Init(HINSTANCE hInstance)
{
	HRESULT hr;

	m_pWindow = new CWindow(hInstance);
	hr = m_pWindow->CreateDesktopWindow(false);
	if (FAILED(hr))
	{
		return false;
	}

	m_pDirectx = new CDirectx();
	hr = m_pDirectx->InitD3D(*m_pWindow, false);
	if (FAILED(hr))
	{
		return false;
	}

	m_pGraphics = new CGraphics(m_pDirectx->GetDevice());

	m_pFrameTime = new CFrameTime();

	return true;
}

void CGame::Run(HINSTANCE hInstance)
{
	if (!Init(hInstance))
	{
		return;
	}

	HRESULT hr = S_OK;

	CObjectStatic objectStatic;
	CObjectDynamic objectDynamic;
	CObjectPlayer objectPlayer;

	objectDynamic.Init(m_pDirectx);
	objectStatic.Init(m_pDirectx);
	objectPlayer.Init(m_pDirectx);

	CInput input;
	input.Init(m_pWindow);

	if (!IsWindowVisible(m_pWindow->GetWindowHandle()))
	{
		ShowWindow(m_pWindow->GetWindowHandle(), SW_SHOW);
	}

	m_pFrameTime->Reset();

	// The render loop is controlled here.
	//bool bGotMsg;
	MSG  msg;
	ZeroMemory(&msg, sizeof(MSG));
	//msg.message = WM_NULL;
	//PeekMessage(&msg, NULL, 0U, 0U, PM_NOREMOVE);

	while (msg.message != WM_QUIT)
	{
		// Process window events.

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// Translate and dispatch the message
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			// Update the scene.
			//renderer->Update();

			// Render frames during idle time (when no messages are waiting).
			//renderer->Render();


			// Present the frame to the screen.
			//deviceResources->Present();

			//Update Time
			m_pFrameTime->Update();

			//Update Keyboard
			input.GetState();

			//Update Game
			objectPlayer.Update(m_pFrameTime->getDeltaTime(), &input);
			objectStatic.Update(m_pFrameTime->getDeltaTime());
			objectDynamic.Update(m_pFrameTime->getDeltaTime());

			//Render
			m_pGraphics->Begin(m_pDirectx->GetDevice());
			objectStatic.Render(m_pGraphics);
			objectPlayer.Render(m_pGraphics);
			objectDynamic.Render(m_pGraphics);
			m_pGraphics->End(m_pDirectx->GetDevice());
		}
	}

	objectDynamic.Destroy();
	objectStatic.Destroy();
	objectPlayer.Destroy();

	this->Destroy();
}

void CGame::Destroy()
{
	SAFE_DELETE(m_pWindow);
	SAFE_DELETE(m_pDirectx);
	SAFE_DELETE(m_pGraphics);
}