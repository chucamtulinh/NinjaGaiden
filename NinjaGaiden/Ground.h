#ifndef __GROUND_H__
#define __GROUND_H__


#include "GameObject.h" 
#include "TextureManager.h"
#include "GameDefine.h"

#define GROUND3101 1
#define GROUND3102 2
#define GROUND3103 3
#define GROUND3104 4
#define GROUND3105 5
#define GROUND3106 6
#define GROUND3107 7
#define GROUND3108 8

class Ground : public GameObject
{
protected:
	int width;
	int height;
	int model;

public:
	Ground(float X, float Y, int W, int H, int Model);
	virtual void Render(Camera * camera);
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
	int GetModel();
};

#endif