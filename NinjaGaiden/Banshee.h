#ifndef __BANSHEE_H__
#define __BANSHEE_H__

#define BANSHEE_ANI_WAIT 0
#define BANSHEE_ANI_RUNNING_BEGIN 1
#define BANSHEE_ANI_RUNNING_END 3

#define BANSHEE_SPEED_RUNNING 0.08f

#define BANSHEE_GRAVITY 0.005f

#include "GameObject.h"
#include "Ryu.h"
#include "ThrowCross.h"

class Banshee : public GameObject
{
private:
	bool isWait;
	//bool isRunning;
	//bool isJumping;
	bool isStart; // trạng thái bắt đầu
	ThrowCross *weapon1, *weapon2;
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
	Banshee(float X, float Y, int Direction, float autoGoX_Distance, float abc, Ryu * ryu, vector<Weapon*> *listWeaponOfEnemy, Camera * camera);
	virtual ~Banshee();

	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	void Render(Camera *camera);
	void Attack();
	bool GetIsStart();

	//void Jump();
	//void Run();
};


#endif