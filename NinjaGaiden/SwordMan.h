#ifndef __SWORDMAN_H__
#define __SWORDMAN_H__

#define SWORDMAN_ANI_WAIT 0
#define SWORDMAN_ANI_RUNNING_BEGIN 1
#define SWORDMAN_ANI_RUNNING_END 3

#define SWORDMAN_SPEED_RUNNING 0.18f
#define SWORDMAN_SPEED_X 0.09f
#define SWORDMAN_GRAVITY 0.005f

#define PANTHER_GRAVITY 0.005f

#include "GameObject.h"
#include "Ryu.h"

class SwordMan : public GameObject
{
private:
	bool isWait;
	bool isStart; // trạng thái bắt đầu

	float AutoGoX_Distance; // khoảng cách cần chạy
	float AutoGoX_Distance2; // khoảng cách 
	bool isAutoGoX;
	float AutoGoX_Backup_X;

	Ryu * ryu;

public:
	SwordMan(float X, float Y, int Direction, float autoGoX_Distance, float autoGoX_Distance2, Ryu * ryu);
	SwordMan(float X, float Y, int Direction);
	virtual ~SwordMan();

	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	void Render(Camera *camera);

	bool GetIsStart();

	//void Jump();
	//void Run();
};


#endif