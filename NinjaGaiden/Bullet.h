#ifndef __BULLET_H__
#define __BULLET_H__


#include "Weapon.h" 
#define BULLET_SPEED 0.21f

class Bullet :
	public Weapon
{
private:
	Camera *camera;

public:
	Bullet(Camera *camera);
	virtual ~Bullet();

	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	void Attack(float X, float Y, int Direction);
	void RenderIcon(float X, float Y);

	void Render(Camera *camera);

};




#endif