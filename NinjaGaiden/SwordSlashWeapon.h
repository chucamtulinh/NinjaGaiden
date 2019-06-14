#ifndef __SWORDSLASHWEAPON_H__
#define __SWORDSLASHWEAPON_H__

#define SWORDSLASHWEAPON_TIME_WAIT_ANI 70 // thời gian chờ chuyển frame của SWORD
#define SWORDSLASHWEAPON_ANI_START 0
#define SWORDSLASHWEAPON_ANI_END 3

#include "Weapon.h"
#include "GameObject.h"
#include "TextureManager.h"
//#include "Sound.h"


class SwordSlashWeapon : public Weapon
{
public:
	SwordSlashWeapon();
	~SwordSlashWeapon();

	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	void Render(Camera *camera);


	void Attack(float X, float Y, int Direction);

	void UpdatePositionFitRyu();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void RenderIcon(float X, float Y);

	bool isCollision(GameObject* obj);
};



#endif
