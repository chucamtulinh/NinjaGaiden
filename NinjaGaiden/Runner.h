#pragma once
#ifndef __RUNNER_H__
#define __RUNNER_H__


#define RUNNER_SPEED_X 0.19f
#define RUNNER_GRAVITY 0.005f


#include "GameObject.h"
class Runner : public GameObject
{
public:
	Runner(float X, float Y, int Direction);
	virtual ~Runner();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	virtual void Render(Camera *camera);

};


#endif  
