#include "CDirectx.h"
#include "CMacro.h"

CDirectx::CDirectx()
{
	m_lpD3D = NULL;
}

CDirectx::~CDirectx()
{
	SAFE_RELEASE(m_lpD3D);
	SAFE_RELEASE(m_lpDevice);
}

HRESULT CDirectx::InitD3D(CWindow window, bool isFullScreen)
{
	HRESULT hr;
	hr = MB_OK;

	 m_lpD3D = Direct3DCreate9(D3D_SDK_VERSION); // create the Direct3D interface

	 if (!m_lpD3D)
	 {
		 return E_FAIL;
	 }

	D3DPRESENT_PARAMETERS d3dpp; // create a struct to hold various device information

	ZeroMemory(&d3dpp, sizeof(d3dpp));    // clear out the struct for use
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;    // discard old frames
	d3dpp.hDeviceWindow = window.GetWindowHandle();    // set the window to be used by Direct3D

	if (isFullScreen)
	{
		d3dpp.Windowed = FALSE;    // program fullscreen, not windowed
		d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;    // set the back buffer format to 32-bit
		d3dpp.BackBufferWidth = window.GetWidth();    // set the width of the buffer
		d3dpp.BackBufferHeight = window.GetHeight();    // set the height of the buffer
		//SetWindowLong(window.GetWindowHandle(), GWL_STYLE, WS_POPUP | WS_SYSMENU | WS_VISIBLE);
	}
	else
	{
		d3dpp.Windowed = TRUE;
		d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	}

	// create a device class using this information and the info from the d3dpp stuct
	hr = m_lpD3D->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		window.GetWindowHandle(),
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&m_lpDevice);
	
	return hr;
}

void CDirectx::Render()
{
	
}
