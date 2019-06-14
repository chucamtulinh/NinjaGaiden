#ifndef __BIRD_H__
#define __BIRD_H__

#include "GameObject.h" 

#define BIRD_SPEED_X 0.1f 
#define BIRD_SPEED_Y 0.05f

#define DeltaY 20 // Biên giao động trục y


class Bird : public GameObject
{
private:
	float yBackup; // vị trí của y ban dầu

public:
	Bird(float X = 0, float Y = 0, int Direction = -1);
	virtual ~Bird();

	void Update(DWORD dt, vector<LPGAMEOBJECT> *listObject = NULL);
	void Render(Camera * camera);

};

#endif