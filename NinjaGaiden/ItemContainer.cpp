#include "ItemContainer.h"



ItemContainer::ItemContainer(float X, float Y, int Model)
{
	model = Model;
	switch (Model)
	{
	case ITEMCONTAINER31:
		texture = TextureManager::GetInstance()->GetTexture(eType::ITEMCONTAINER_31);
		break;
	case ITEMCONTAINER32:
		//texture = TextureManager::GetInstance()->GetTexture(eType::ITEMCONTAINER_32);
		break;
	default: break;
	}
	sprite = new Sprite(texture, 100);
	this->x = X;
	this->y = Y;
	type = eType::ITEMCONTAINER;
	Health = 1;
}


ItemContainer::~ItemContainer()
{
}

void ItemContainer::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	sprite->Update(dt);
}

void ItemContainer::Render(Camera * camera)
{
	if (IS_DEBUG_RENDER_BBOX)
		RenderBoundingBox(camera);

	D3DXVECTOR2 pos = camera->Transform(x, y);
	sprite->Draw(pos.x, pos.y);
}
