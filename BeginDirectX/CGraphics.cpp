#include "CGraphics.h"
#include "CMacro.h"

LPDIRECT3DTEXTURE9 LoadTexture(LPDIRECT3DDEVICE9 device, std::string path)
{
	LPDIRECT3DTEXTURE9 texture = NULL;
	D3DXIMAGE_INFO info;
	HRESULT hr;
	ZeroMemory(&info, sizeof(info));
	hr = D3DXGetImageInfoFromFile(path.c_str(), &info);
	if (hr != D3D_OK)
		return NULL;
	
	hr = D3DXCreateTextureFromFileEx(device,
		path.c_str(),
		info.Width,
		info.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT, 
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 255, 255),
		&info,
		NULL,
		&texture);

	if (hr != D3D_OK)
		return NULL;
	return texture;
}

LPDIRECT3DSURFACE9 LoadSurface(LPDIRECT3DDEVICE9 device, std::string path)
{
	LPDIRECT3DSURFACE9 surface = NULL;
	D3DXIMAGE_INFO info;
	HRESULT hr;
	ZeroMemory(&info, sizeof(info));
	hr = D3DXGetImageInfoFromFile(path.c_str(), &info);
	if (hr != D3D_OK)
		return NULL;
	hr = device->CreateOffscreenPlainSurface(
		info.Width,
		info.Height,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		&surface,
		NULL);
	if (hr != D3D_OK)
		return NULL;
	
	hr = D3DXLoadSurfaceFromFile(surface, NULL, NULL, path.c_str(), NULL, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255), &info);
	if (hr != D3D_OK)
		return NULL;

	return surface;
}

CGraphics::CGraphics(LPDIRECT3DDEVICE9 device)
{
	D3DXCreateSprite(device, &m_pSprite);
}

CGraphics::~CGraphics()
{
	SAFE_RELEASE(m_pSprite);
}

void CGraphics::Begin(LPDIRECT3DDEVICE9 device)
{
	// clear the window to a deep blue
	device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 255, 0), 1.0f, 0);
	device->BeginScene();    // begins the 3D scene
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
}

void CGraphics::End(LPDIRECT3DDEVICE9 device)
{
	m_pSprite->End();
	// do 3D rendering on the back buffer here
	device->EndScene();    // ends the 3D scene
	device->Present(NULL, NULL, NULL, NULL);   // displays the created frame on the screen
}

void CGraphics::DrawSurface()
{

}

void CGraphics::DrawTexture(LPDIRECT3DTEXTURE9 texture, D3DXVECTOR2 postion, D3DCOLOR color)
{
	m_pSprite->Draw(
		texture,
		NULL,
		NULL,
		&D3DXVECTOR3(postion.x, postion.y, 0),
		color
		);
}