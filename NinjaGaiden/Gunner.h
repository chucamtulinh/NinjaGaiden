#ifndef __GUNNER_H__
#define __GUNNER_H__

#define GUNNER_ANI_WAIT 0
#define GUNNER_ANI_RUNNING_BEGIN 1
#define GUNNER_ANI_RUNNING_END 3

#define GUNNER_SPEED_RUNNING 0.08f

#define PANTHER_GRAVITY 0.005f

#include "GameObject.h"
#include "Ryu.h"
#include "Bullet.h"

class Gunner : public GameObject
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
	Gunner(float X, float Y, int Direction, float autoGoX_Distance, float abc, Ryu * ryu, vector<Weapon*> *listWeaponOfEnemy, Camera * camera);
	virtual ~Gunner();

	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	void Render(Camera *camera);
	void Attack();
	bool GetIsStart();

	//void Jump();
	//void Run();
};


#endif