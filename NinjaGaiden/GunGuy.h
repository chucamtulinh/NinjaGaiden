#ifndef __GUNGUY_H__
#define __GUNGUY_H__

#define GUNGUY_ANI_WAIT 0
#define GUNGUY_ANI_RUNNING_BEGIN 1
#define GUNGUY_ANI_RUNNING_END 3

#define GUNNER_SPEED_RUNNING 0.08f
#define PANTHER_GRAVITY 0.005f

#include "GameObject.h"
#include "Ryu.h"
#include "Bullet.h"

class GunGuy : public GameObject
{
private:
	bool isWait;
	//bool isRunning;
	//bool isJumping;
	bool isStart; // trạng thái bắt đầu
	Bullet *weapon;
	DWORD TimeAttack;
	DWORD TimeDelay;
	bool isAttacking;
	float AutoGoX_Distance; // khoảng cách cần chạy
	float AutoGoX_Distance2; // khoảng cách 
	bool isAutoGoX;
	float AutoGoX_Backup_X;

	vector<Weapon*> *listWeaponOfEnemy;
	Ryu * ryu;
	Camera * camera;

public:
	GunGuy(float X, float Y, int Direction, float autoGoX_Distance, float abc, Ryu * ryu, vector<Weapon*> *listWeaponOfEnemy, Camera * camera);
	virtual ~GunGuy();

	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	void Render(Camera *camera);
	void Attack();
	bool GetIsStart();

	//void Jump();
	//void Run();
};


#endif