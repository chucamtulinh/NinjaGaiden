#ifndef __SWORDSLASHWEAPON_H__
#define __SWORDSLASHWEAPON_H__

#define SWORDSLASHWEAPON_TIME_WAIT_ANI 120 // thời gian chờ chuyển frame của SWORD
#define SWORDSLASHWEAPON_ANI_LEVEL0_START 0
#define SWORDSLASHWEAPON_ANI_LEVEL0_END 3
#define SWORDSLASHWEAPON_ANI_LEVEL1_START 4
#define SWORDSLASHWEAPON_ANI_LEVEL1_END 7
#define SWORDSLASHWEAPON_ANI_LEVEL2_START 8
#define SWORDSLASHWEAPON_ANI_LEVEL2_END 11

#include "Weapon.h"
#include "GameObject.h" 
#include "TextureManager.h"
//#include "Sound.h"


class SwordSlashWeapon : public Weapon
{
protected:
	int level;
public:
	SwordSlashWeapon();
	~SwordSlashWeapon();

	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	void Render(Camera *camera);


	void Attack(float X, float Y, int Direction);

	void UpdatePositionFitSimon();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void RenderIcon(float X, float Y);

	void UpgradeLevel();

	int GetLevel();
	bool isCollision(GameObject* obj);
};



#endif  
