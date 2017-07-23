#ifndef __CGRAPHICS_H__
#define __CGRAPHICS_H__

#include <d3dx9.h>
#include <string>

// load texture
LPDIRECT3DTEXTURE9 LoadTexture(LPDIRECT3DDEVICE9 device, std::string path);

//load sufface
LPDIRECT3DSURFACE9 LoadSurface(LPDIRECT3DDEVICE9 device, std::string path);

class CGraphics
{
public:
	CGraphics(LPDIRECT3DDEVICE9);
	~CGraphics();

public:
	void DrawTexture(LPDIRECT3DTEXTURE9, D3DXVECTOR2, D3DCOLOR);
	void DrawSurface();

	void Begin(LPDIRECT3DDEVICE9);
	void End(LPDIRECT3DDEVICE9);


private:
	LPD3DXSPRITE m_pSprite;
	
};

#endif