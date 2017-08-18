#ifndef __CINPUT_H__
#define __CINPUT_H__

#include <dinput.h>
#include "CWindow.h"

class CInput
{
public:
	CInput();
	~CInput();

public:
	void GetState();
	bool Init(CWindow* window);
	bool IsKeyDown(int Key);

private:
	LPDIRECTINPUT8 m_lpInput;
	LPDIRECTINPUTDEVICE8 m_lpInputDevice;
	BYTE key_buffer[256];
};

#endif