#ifndef __SWORDMAN_H__
#define __SWORDMAN_H__


#define SWORDMAN_SPEED_X 0.19f
#define SWORDMAN_GRAVITY 0.005f


#include "GameObject.h"
class SwordMan : public GameObject
{
public:
	SwordMan(float X, float Y, int Direction);
	virtual ~SwordMan();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	virtual void Render(Camera *camera);

};


#endif  


