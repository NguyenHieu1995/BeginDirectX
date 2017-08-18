
#include "CObjectPlayer.h"
#include "CMacro.h"

CObjectPlayer::CObjectPlayer() : CObject()
{
	m_lpTexture = NULL;

	m_vPos.x = 0;
	m_vPos.y = 0;

	m_vSpeed.x = 0;
	m_vSpeed.y = 0;

	m_eTypeObject = PLAYER;
}

bool CObjectPlayer::Init(CDirectx* directx)
{
	m_lpTexture = LoadTexture(directx->GetDevice(), "..\\Resource\\mario.png");

	m_vSpeed.x = 100;
	m_vSpeed.y = 100;

	return true;
}

void CObjectPlayer::Update(float deltaTime, CInput* input)
{
	m_vSpeed.x = 0;
	m_vSpeed.y = 0;

	if (input != NULL)
	{
		if (input->IsKeyDown(DIK_LEFT))
		{
				m_vSpeed.x = -100;
		}

		if (input->IsKeyDown(DIK_RIGHT))
		{
				m_vSpeed.x = 100;
		}

		if (input->IsKeyDown(DIK_UP))
		{
			m_vSpeed.y = -100;
		}

		if (input->IsKeyDown(DIK_DOWN))
		{
			m_vSpeed.y = 100;
		}
	}

	/*
	if (m_vPos.x < 0 || m_vPos.x > 600)
	m_vSpeed.x *= -1;

	if (m_vPos.y < 0 || m_vPos.y > 400)
	m_vSpeed.y *= -1;
	*/

	m_vPos.x += (m_vSpeed.x * deltaTime);
	m_vPos.y += (m_vSpeed.y * deltaTime);
}

void CObjectPlayer::Render(CGraphics* graphics)
{
	graphics->DrawTexture(m_lpTexture, m_vPos, D3DCOLOR_XRGB(255, 255, 255));
}

void CObjectPlayer::Destroy()
{
	SAFE_RELEASE(m_lpTexture);
}
