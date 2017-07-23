#include "CWindow.h"

HINSTANCE CWindow::m_hInstance = NULL;

CWindow::CWindow(HINSTANCE hIstance)
{
	m_hWnd = NULL;
	m_isFullScreen = false;
	m_hInstance = hIstance;
}

CWindow::~CWindow()
{

}

HRESULT CWindow::CreateDesktopWindow(BOOL isFullScreen)
{
	HRESULT hr;

	if (m_hInstance == NULL)
	{
		m_hInstance = (HINSTANCE)GetModuleHandle(NULL);
	}

	hr = InitApplication(isFullScreen);
	if (FAILED(hr))
		return hr;

	hr = InitInstance(WINDOW_SMALL, isFullScreen);
	if (FAILED(hr))
		return hr;

	return MB_OK;
	
}

HRESULT CWindow::InitApplication(bool isFullScreen)
{
	//struct holds information for the window class
	WNDCLASSEX wcx;

	HICON hIcon = NULL;
	WCHAR szExePath[MAX_PATH];
	GetModuleFileName(NULL, (LPSTR)szExePath, MAX_PATH);

	// If the icon is NULL, then use the first one found in the exe
	if (hIcon == NULL)
		hIcon = ExtractIcon(m_hInstance, (LPSTR)szExePath, 0);

	//clear out the window class for use
	ZeroMemory(&wcx, sizeof(WNDCLASSEX));

	// Register the windows class
	wcx.cbSize = sizeof(WNDCLASSEX);
	wcx.style = CS_HREDRAW | CS_VREDRAW;
	wcx.lpfnWndProc = CWindow::WindowProc;
	wcx.cbClsExtra = 0;
	wcx.cbWndExtra = 0;
	wcx.hInstance = m_hInstance;
	wcx.hIcon = hIcon;
	wcx.hCursor = LoadCursor(NULL, IDC_ARROW);

	if (!isFullScreen)
	{
		wcx.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	}
	
	wcx.lpszMenuName = NULL;
	wcx.lpszClassName = WINDOW_CLASS_NAME;

	if (!RegisterClassEx(&wcx))
	{
		DWORD dwError = GetLastError();
		if (dwError != ERROR_CLASS_ALREADY_EXISTS)
			return HRESULT_FROM_WIN32(dwError);
	}

	return MB_OK;
}

HRESULT CWindow::InitInstance(WindowSize winSize, bool isFullScreen)
{	
	// No menu in this example.
	m_hMenu = NULL;

	// This example uses a non-resizable 640 by 480 viewport for simplicity.
	int nDefaultWidth = 0;
	int nDefaultHeight = 0;

	switch (winSize)
	{
	case WINDOW_SMALL:
		nDefaultWidth = 640;
		nDefaultHeight = 480;
		break;
	case WINDOW_MEDIUM:
		nDefaultWidth = 800;
		nDefaultHeight = 600;
		break;
	case WINDOW_BIG:
		nDefaultWidth = 1024;
		nDefaultHeight = 768;
		break;
	}

	SetRect(&m_rc, 0, 0, nDefaultWidth, nDefaultHeight);
	AdjustWindowRect(
		&m_rc,
		WS_OVERLAPPEDWINDOW,
		(m_hMenu != NULL) ? true : false
		);

	

	if (m_isFullScreen)
	{
		m_hWnd = CreateWindowEx(
			NULL,
			WINDOW_CLASS_NAME,
			WINDOW_TITLE,
			WS_EX_TOPMOST | WS_POPUP,    // fullscreen values
			0, 0,    // the starting x and y positions should be 0
			(m_rc.right - m_rc.left), (m_rc.bottom - m_rc.top),
			(HWND)NULL,
			m_hMenu,
			m_hInstance,
			(LPVOID)NULL);
	}
	else
	{
		// create the window and use the result as the handle
		m_hWnd = CreateWindowEx(
			NULL, //The extended window style of the window being created.
			WINDOW_CLASS_NAME,    // name of the window class
			WINDOW_TITLE,   // title of the window
			WS_OVERLAPPEDWINDOW,    // window style
			CW_USEDEFAULT,    // x-position of the window
			CW_USEDEFAULT,    // y-position of the window
			(m_rc.right - m_rc.left), (m_rc.bottom - m_rc.top),
			(HWND)NULL,    // we have no parent window, NULL
			m_hMenu,    // we aren't using menus, NULL
			m_hInstance,    // application handle
			(LPVOID)NULL);    // used with multiple windows, NULL
	}

	if (m_hWnd == NULL)
	{
		DWORD dwError = GetLastError();
		return HRESULT_FROM_WIN32(dwError);
	}

	return S_OK;
}

// Main message handler for program
//hWnd: A handle to the window procedure to receive the message.
// message: For lists of the system-provided messages.
// lParam, wParam: Additional message - specific information.
LRESULT CALLBACK CWindow::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{

	case WM_CLOSE:
	{
					 HMENU hMenu;
					 hMenu = GetMenu(hWnd);
					 if (hMenu != NULL)
					 {
						 DestroyMenu(hMenu);
					 }
					 DestroyWindow(hWnd);
					 UnregisterClass(
						 WINDOW_CLASS_NAME,
						 (HINSTANCE)m_hInstance
						 );
					 return 0;
	}

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}