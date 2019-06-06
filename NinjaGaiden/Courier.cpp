#include "Courier.h"



Courier::Courier(float X, float Y)
{
	texture = TextureManager::GetInstance()->GetTexture(eType::COURIER);
	sprite = new Sprite(texture, 100);
	this->x = X;
	this->y = Y;
	type = eType::COURIER;
	Health = 1;
}


Courier::~Courier()
{
}

void Courier::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	sprite->Update(dt); // update animation
}
