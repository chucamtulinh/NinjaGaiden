#ifndef __ITEMCONTAINER_H__
#define __ITEMCONTAINER_H__

#include "GameObject.h"
#include "TextureManager.h"
#include "GameDefine.h"

class ItemContainer : public GameObject
{
public:
	ItemContainer(float X, float Y);
	~ItemContainer();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	virtual void Render(Camera * camera);
};
#endif // !



