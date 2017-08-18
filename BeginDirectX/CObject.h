#ifndef __COBJECT_H__
#define __COBJECT_H__

#include "CGraphics.h"
#include "CDirectx.h"
#include "CGraphics.h"
#include "CInput.h"

enum eTypeObject
{
	STATIC,
	DYNAMIC,
	PLAYER
};

class CObject
{
public:
	CObject();
	virtual ~CObject();

public:
	virtual bool Init(CDirectx*) = 0;
	virtual void Update(float, CInput* input = NULL) = 0;
	virtual void Render(CGraphics*) = 0;
	virtual void Destroy() = 0;
	void setPosition(D3DXVECTOR2);
	D3DXVECTOR2 getPosition();

protected:
	//Texture cua object
	LPDIRECT3DTEXTURE9 m_lpTexture; 
	D3DXVECTOR2 m_vPos; //vi tri
	eTypeObject m_eTypeObject; // loai object
	D3DXVECTOR2 m_vSize; //kich thuoc object

};



#endif