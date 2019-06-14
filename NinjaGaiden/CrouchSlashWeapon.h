#ifndef __CROUCHSLASHWEAPON_H__
#define __CROUCHSLASHWEAPON_H__

#define CROUCHSLASHWEAPON_TIME_WAIT_ANI 120 // thời gian chờ chuyển frame của SWORD
#define CROUCHSLASHWEAPON_ANI_LEVEL0_START 0
#define CROUCHSLASHWEAPON_ANI_LEVEL0_END 3
#define CROUCHSLASHWEAPON_ANI_LEVEL1_START 4
#define CROUCHSLASHWEAPON_ANI_LEVEL1_END 7
#define CROUCHSLASHWEAPON_ANI_LEVEL2_START 8
#define CROUCHSLASHWEAPON_ANI_LEVEL2_END 11

#include "Weapon.h"
#include "GameObject.h" 
#include "TextureManager.h"
//#include "Sound.h"


class CrouchSlashWeapon : public Weapon
{
protected:
	int level;
public:
	CrouchSlashWeapon();
	~CrouchSlashWeapon();

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
