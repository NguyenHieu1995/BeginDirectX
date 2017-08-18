//
// Object cac doi tuong dong
//

#ifndef __COBJECTDYNAMIC_H__
#define __COBJECTDYNAMIC_H__

#include "CObject.h"


class CObjectDynamic : public CObject
{
public:
	CObjectDynamic();
	virtual ~CObjectDynamic(){};

public:
	//ket thua Object
	bool Init(CDirectx*);
	void Update(float, CInput* input = NULL);
	void Render(CGraphics*);
	void Destroy();

	//private function
	void AI();
	void Collection();

protected:
	D3DXVECTOR2 m_vSpeed;
};

#endif