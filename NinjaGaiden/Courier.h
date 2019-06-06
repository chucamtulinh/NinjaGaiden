#ifndef __COURIER_H__
#define __COURIER_H__

#include "GameObject.h"
#include "TextureManager.h"

class Courier : public GameObject
{
public:
	Courier(float X = 0, float Y = 0);
	~Courier();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	virtual void Render(Camera * camera);
};

#endif // !__COURIER_H__