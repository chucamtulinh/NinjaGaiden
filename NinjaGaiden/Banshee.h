#ifndef __BANSHEE_H__
#define __BANSHEE_H__

#include "GameObject.h" 
#include "Ground.h"
#include "Ryu.h"
#include "Bullet.h"

#define BANSHEE_ANI_WALK_BEGIN 1 // ani b?t d?u di
#define BANSHEE_ANI_WALK_END 2 
#define BANSHEE_ANI_ATTACK 0 // ani l�c fishmen attack

#define FISHMEN_GRAVITY 0.01f
#define FISHMEN_SPEED_X 0.07f

#define FISHMEN_DX_LIMIT 140 // di du?c kho?ng 140px th� d?i hu?ng
#define FISHMEN_DX_ATTACK_LIMIT 130 // di du?c kho?ng 140px th� d?i hu?ng

#define FISHMEN_TIME_LIMIT_WAIT_AFTER_ATTACK 700 // th?i gian fishmen ph?i d?ng l?i ch? tru?c khi di ti?p, sau khi attack

class Banshee : public GameObject
{
private:
	float yInit; // v? tr� y l�c kh?i t?o
	float xInit;

	float xBefore;
	float xAfter;
	float xAccumulationAttack; // qu�ng du?ng d� di t�ch luy, d? khi di d? gi?i h?n s? attack
	DWORD TimeAttack; // th?i di?m attack

	bool isRunning;
	FireBall * weapon;
	bool isAttacking;

	/* Luu th�nh ph?n ngo�i ph?c v? x? l� */
	Simon* simon;
	vector<Weapon*> *listWeaponOfEnemy;
	Camera * camera;

public:
	Fishmen(float X, float Y, int Direction, Simon* simon, vector<Weapon*> *listWeaponOfEnemy, Camera * camera);
	virtual ~Fishmen();

	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void Update(DWORD dt, vector<LPGAMEOBJECT> *listObject = NULL);
	void Render(Camera * camera);
	void Attack();
};

#endif 




