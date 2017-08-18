#include "CObjectDynamic.h"
#include "CMacro.h"

CObjectDynamic::CObjectDynamic() : CObject()
{
	m_lpTexture = NULL;

	m_vPos.x = 0;
	m_vPos.y = 0;

	m_vSpeed.x = 0;
	m_vSpeed.y = 0;

	m_eTypeObject = DYNAMIC;
}

bool CObjectDynamic::Init(CDirectx* directx)
{
	m_lpTexture = LoadTexture(directx->GetDevice(), "..\\Resource\\mario.png");

	m_vSpeed.x = 100;
	m_vSpeed.y = 100;

	return true;
}

void CObjectDynamic::Update(float deltaTime, CInput* input)
{
	if (m_vPos.x < 0 || m_vPos.x > 600)
		m_vSpeed.x *= -1;

	if (m_vPos.y < 0 || m_vPos.y > 400)
		m_vSpeed.y *= -1;

	m_vPos.x += (m_vSpeed.x * deltaTime);
	m_vPos.y += (m_vSpeed.y * deltaTime);
}

void CObjectDynamic::Render(CGraphics* graphics)
{
	graphics->DrawTexture(m_lpTexture, m_vPos, D3DCOLOR_XRGB(255, 255, 255));
}

void CObjectDynamic::Destroy()
{
	SAFE_RELEASE(m_lpTexture);
}
