//
//Created: 23/07/2017
//Creator: Zero.Se08
//Class: CGame 
//Main loop Game
//
#ifndef __CGAME_H__
#define __CGAME_H__

#include "CWindow.h"
#include "CDirectx.h"
#include "CGraphics.h"

class CGame
{
public:
	CGame();
	~CGame();

public:
	void Run(HINSTANCE hInstance = NULL);

protected:
	CWindow* m_pWindow;
	CDirectx* m_pDirectx;
	CGraphics* m_pGraphics;

protected:
	bool Init(HINSTANCE hInstance);
	void Destroy();

};

#endif