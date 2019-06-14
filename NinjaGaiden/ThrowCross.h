#ifndef  __THROWCROSS_H__
#define __THROWCROSS_H__

#define THROWCROSS_SPEED_X 0.2f
#define THROWCROSS_SPEED_Y 0.55f
#define THROWCROSS_GRAVITY 0.0015f


#include "Weapon.h"
//#include "Sound.h"
class ThrowCross :
	public Weapon
{
private:
	Sprite * _spriteIcon;
	Camera * camera;

public:

	ThrowCross(Camera * camera);
	virtual ~ThrowCross();

	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	void Attack(float X, float Y, int Direction);
	virtual void RenderIcon(float X, float Y);

};

#endif
