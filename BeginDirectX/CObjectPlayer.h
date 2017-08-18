//
//Object quan ly nguoi choi
//
#ifndef __COBJECTPLAYER_H__
#define __COBJECTPLAYER_H__

#include "CObject.h"

class CObjectPlayer : public CObject
{
public:
	CObjectPlayer();
	virtual ~CObjectPlayer() {};

public:
	//ke thua Object
	bool Init(CDirectx*);
	void Update(float, CInput* input = NULL);
	void Render(CGraphics*);
	void Destroy();

	//private function
	void Collection();
	void Control();

protected:
	D3DXVECTOR2 m_vSpeed;
};

#endif