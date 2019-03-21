#include "Bat.h"



Bat::Bat(void)
{
}


Bat::~Bat(void)
{
}


void Bat::InitDown(MContent* content) {
	this->img = content->LoadTexture("bat.png");
	this->position = D3DXVECTOR2(200, 600 - 30);
	speed = 5;
}

void Bat::InitUp(MContent* content) {
	this->img = content->LoadTexture("bat.png");
	this->position = D3DXVECTOR2(200, 0);
	speed = 5;
}

void Bat::Update(float gameTime, MKeyboard* key) {

	if (key->IsKeyDown(DIK_LEFT)) {
		if (position.x > 0.0f) this->position.x -= speed;
	}
	if (key->IsKeyDown(DIK_RIGHT)) {
		if (position.x + 90.0f < 300.0f) this->position.x += speed;
	}
	rect.left = position.x;
	rect.right = rect.left + 90;
	rect.top = position.y;
	rect.bottom = 30;
}

void Bat::Update2(float gameTime, MKeyboard* key) {

	if (key->IsKeyDown(DIK_A)) {
		if (position.x > 0.0f) this->position.x -= speed;
	}
	if (key->IsKeyDown(DIK_D)) {
		if (position.x + 90.0f < 300.0f) this->position.x += speed;
	}
	rect.left = position.x;
	rect.right = rect.left + 90;
	rect.top = position.y;
	rect.bottom = 30;
}

void Bat::Update(float gameTime, long x) {
	this->position.x = x;
	rect.left = position.x;
	rect.right = rect.left + 90;
	rect.top = position.y;
	rect.bottom = 30;
}

void Bat::Render(MGraphic* graphic) {
	graphic->DrawTexture(img, position, D3DCOLOR_XRGB(255, 255, 255));
}