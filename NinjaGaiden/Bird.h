#ifndef __Bird_H__
#define __Bird_H__

#include "GameObject.h" 
#include "Ryu.h"

#define BIRD_SPEED_X 0.005f 
#define BIRD_SPEED_Y 0.01f

class Bird : public GameObject
{
private:
	Ryu* ryu;
public:
	Bird(float X, float Y, int Direction, Ryu* ryu);
	virtual ~Bird();

	void Update(DWORD dt, vector<LPGAMEOBJECT> *listObject = NULL);
	void Render(Camera * camera);

};

#endif