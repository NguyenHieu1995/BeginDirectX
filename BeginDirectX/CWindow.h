//
//Created: 23/07/2017
//Creator: Zero.Se08
//Class: CWindow
//Detail: Quan ly cua so cua chuong trinh
//
#ifndef __CWINDOW_H__
#define __CWINDOW_H__

#include <Windows.h>
#include <iostream>

#define WINDOW_CLASS_NAME "window class"
#define WINDOW_TITLE "Simple"

enum WindowSize
{
	WINDOW_SMALL,
	WINDOW_MEDIUM,
	WINDOW_BIG
};

//The window Procedure function prototype
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

class CWindow
{
public:
	CWindow();
	~CWindow();

protected:
	HWND m_hWnd;
	RECT m_rc;
	BOOL m_isFullScreen;
	HMENU     m_hMenu;

protected:
	HRESULT InitApplication(bool isFullScreen);
	HRESULT InitInstance(WindowSize, bool isFullScreen);

public:
	HRESULT CreateDesktopWindow(BOOL isFullScreen = false);
	HWND GetWindowHandle() { return m_hWnd; };
	INT32 GetHeight() { return m_rc.bottom - m_rc.top; }
	INT32 GetWidth(){ return m_rc.right - m_rc.left; }

	static LRESULT CALLBACK WindowProc(
		HWND hWnd,
		UINT uMsg,
		WPARAM wParam,
		LPARAM lParam
		);

	
};

static HINSTANCE m_hInstance;

#endif