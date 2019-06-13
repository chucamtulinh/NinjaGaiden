#ifndef __ITEMCONTAINER_H__
#define __ITEMCONTAINER_H__

#include "GameObject.h"
#include "TextureManager.h"
#include "GameDefine.h"

#define ITEMCONTAINER31 1
#define ITEMCONTAINER32 2

class ItemContainer : public GameObject
{
protected:
	int model;
public:
	ItemContainer(float X, float Y, int Model);
	~ItemContainer();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	virtual void Render(Camera * camera);
};
#endif // !



