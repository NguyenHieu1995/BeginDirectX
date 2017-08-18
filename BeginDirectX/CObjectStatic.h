//
// Object cac doi tuong tinh
//

#ifndef __COBJECTSTATIC_H__
#define __COBJECTSTATIC_H__

#include "CObject.h"



class CObjectStatic : public CObject
{
public:
	CObjectStatic();
	virtual ~CObjectStatic(){};

public:
	//ke thua Object
	bool Init(CDirectx*);
	void Update(float, CInput* input = NULL);
	void Render(CGraphics*);
	void Destroy();

	//private function

};

#endif