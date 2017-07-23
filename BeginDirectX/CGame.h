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

class CGame
{
public:
	CGame();
	~CGame();

public:
	void Run();

protected:
	CWindow* m_pWindow;
	CDirectx* m_pDirectx;

protected:
	bool Init();
	void Destroy();

};

#endif