//
//Created: 23/7/2017
//Creator: Zero.Se08
//Class: CDirectx
//
#ifndef __CDIRECTX_H__
#define __CDIRECTX_H__

#include <d3d9.h>
#include "CWindow.h"

class CDirectx
{
public:
	CDirectx();
	~CDirectx();

public:
	HRESULT InitD3D(CWindow, bool isFullScreen = false);

	void Render();

	LPDIRECT3D9 GetD3D() { return m_lpD3D; }
	LPDIRECT3DDEVICE9 GetDevice(){ return m_lpDevice; }

private:
	LPDIRECT3D9 m_lpD3D; // the pointer to our Direct3D interface
	LPDIRECT3DDEVICE9 m_lpDevice; // the pointer to the device class

};

#endif