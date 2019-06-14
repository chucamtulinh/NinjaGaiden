#ifndef __CROUCHSLASHWEAPON_H__
#define __CROUCHSLASHWEAPON_H__

#define CROUCHSLASHWEAPON_TIME_WAIT_ANI 70 // thời gian chờ chuyển frame của SWORD
#define CROUCHSLASHWEAPON_ANI_START 0
#define CROUCHSLASHWEAPON_ANI_END 2

#include "Weapon.h"
#include "GameObject.h" 
#include "TextureManager.h"
//#include "Sound.h"


class CrouchSlashWeapon : public Weapon
{
public:
	CrouchSlashWeapon();
	~CrouchSlashWeapon();

	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	void Render(Camera *camera);


	void Attack(float X, float Y, int Direction);

	void UpdatePositionFitRyu();
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void RenderIcon(float X, float Y);

	bool isCollision(GameObject* obj);
};



#endif  
