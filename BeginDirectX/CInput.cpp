#include "CInput.h"

CInput::CInput()
{
	this->m_lpInput = NULL;
	this->m_lpInputDevice = NULL;
	ZeroMemory(&this->key_buffer, sizeof(key_buffer));
}

CInput::~CInput()
{

}

bool CInput::Init(CWindow* window)
{
	HRESULT hr = DirectInput8Create(
		window->GetInstanceHandle(),
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&this->m_lpInput,
		NULL);
	if (FAILED(hr))
		return false;
	
	hr = this->m_lpInput->CreateDevice(GUID_SysKeyboard, &this->m_lpInputDevice, NULL);
	if (FAILED(hr))
		return false;
	
	hr = this->m_lpInputDevice->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(hr))
		return false;
	
	hr = this->m_lpInputDevice->SetCooperativeLevel(window->GetWindowHandle(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if (FAILED(hr))
		return false;
	
	hr = this->m_lpInputDevice->Acquire();
	if (FAILED(hr))
		return false;
	return true;
}

void CInput::GetState()
{
	HRESULT hr = m_lpInputDevice->GetDeviceState(sizeof(this->key_buffer), (LPVOID)&this->key_buffer);
	if (FAILED(hr))
	{
		while (this->m_lpInputDevice->Acquire() == DIERR_INPUTLOST);
	}
}

bool CInput::IsKeyDown(int Key)
{
	return (key_buffer[Key] & 0x80);
}