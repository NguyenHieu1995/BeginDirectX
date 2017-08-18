#include "CObject.h"
#include "CMacro.h"

CObject::CObject()
{
	m_lpTexture = NULL;
	
	m_vPos.x = 0;
	m_vPos.y = 0;

	m_vSize.x = 0;
	m_vSize.y = 0;
}

CObject::~CObject()
{
	SAFE_RELEASE(m_lpTexture);
}

void CObject::setPosition(D3DXVECTOR2 pos)
{
	m_vPos.x = pos.x;
	m_vPos.y = pos.y;
}

D3DXVECTOR2 CObject::getPosition()
{
	return m_vPos;
}