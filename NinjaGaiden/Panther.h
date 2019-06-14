#ifndef __PANTHER_H__
#define __PANTHER_H__

#define PANTHER_ANI_RUNNING_BEGIN 1
#define PANTHER_ANI_RUNNING_END 3

#define PANTHER_SPEED_RUNNING 0.18f
#define PANTHER_VYJUMP 0.3f
#define PANTHER_VXJUMP 0.2f

#define PANTHER_GRAVITY 0.005f
#define PANTHER_GRAVITY_JUMPING 0.001f

#include "GameObject.h"
#include "Ryu.h"

class Panther : public GameObject
{
private:
	//trạng thái
	bool isJumping;

	float AutoGoX_Distance; // khoảng cách cần chạy
	bool isAutoGoX;
	float AutoGoX_Backup_X;

	Ryu * ryu;

public:
	Panther(float X, float Y, int Direction, float autoGoX_Distance, Ryu * ryu);
	virtual ~Panther();

	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	void Render(Camera *camera);

	bool GetIsStart();

	void Jump();
	void Run();
};


#endif