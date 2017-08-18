#include "CObjectStatic.h"
#include "CMacro.h"

CObjectStatic::CObjectStatic() : CObject()
{
	m_lpTexture = NULL;

	m_vPos.x = 0;
	m_vPos.y = 0;

	m_eTypeObject = STATIC;
}

bool CObjectStatic::Init(CDirectx* directx)
{
	m_lpTexture = LoadTexture(directx->GetDevice(), "..\\Resource\\mario.png");

	return true;
}

void CObjectStatic::Update(float deltaTime, CInput* input)
{
	
}

void CObjectStatic::Render(CGraphics* graphics)
{
	graphics->DrawTexture(m_lpTexture, m_vPos, D3DCOLOR_XRGB(255, 255, 255));
}

void CObjectStatic::Destroy()
{
	SAFE_RELEASE(m_lpTexture);
}
