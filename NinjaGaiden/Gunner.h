#ifndef __GUNNER_H__
#define __GUNNER_H__

#include "GameObject.h" 
#include "Ground.h"
#include "Ryu.h"
#include "Bullet.h"

#define GUNNER_ANI_ATTACK 0 // ani lúc attack
#define GUNNER_TIME_LIMIT_WAIT_AFTER_ATTACK 700 // thời gian phải đứng lại chờ trước khi đi tiếp, sau khi attack
#define TIME_ATTACK_DELAY 1000 //Thời gian giữa 2 lần tấn công
class Gunner : public GameObject
{
private:
	DWORD TimeAttack; // thời điểm 
	DWORD TimeDelay;
	float xAccumulationAttack;
	Bullet * weapon;
	bool isAttacking;

	/* Lưu thành phần ngoài phục vụ xử lí */
	Ryu* ryu;
	vector<Weapon*> *listWeaponOfEnemy;
	Camera * camera;

public:
	Gunner(float X, float Y, int Direction, Ryu* ryu, vector<Weapon*> *listWeaponOfEnemy, Camera * camera);
	virtual ~Gunner();

	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void Update(DWORD dt, vector<LPGAMEOBJECT> *listObject = NULL);
	void Render(Camera * camera);
	void Attack();
};

#endif 




