#include "Bat.h"

#define BUTTONDOWN(name, key) (name.rgbButtons[key] & 0x80)

enum {
	NONE = 0,
	LEFT_ARROW,
	RIGHT_ARROW,
	CIRCLE
};

Bat::Bat(void)
{
}


Bat::~Bat(void)
{
}


void Bat::InitDown(MContent* content) {
	this->img = content->LoadTexture("bat.png");
	this->position = D3DXVECTOR2(200, 800 - 30);
	speed = 5;
}

void Bat::InitUp(MContent* content) {
	this->img = content->LoadTexture("bat.png");
	this->position = D3DXVECTOR2(200, 0);
	speed = 1;
}

void Bat::Update(float gameTime, MKeyboard* key) {

	if (key->IsKeyDown(DIK_LEFT)) {
		if (position.x > 0.0f) this->position.x -= speed;
	}
	if (key->IsKeyDown(DIK_RIGHT)) {
		if (position.x + 90.0f < 600.0f) this->position.x += speed;
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
		if (position.x + 90.0f < 600.0f) this->position.x += speed;
	}
	rect.left = position.x;
	rect.right = rect.left + 90;
	rect.top = position.y;
	rect.bottom = 30;
}

void Bat::Update(float gameTime, MMouse* mouse) {
	/*if (BUTTONDOWN(mouse->mouseState, 0) && position.x > 0.0f) this->position.x -= speed;
	if (BUTTONDOWN(mouse->mouseState, 1) && position.x + 90.0f < 300.0f) this->position.x += speed;*/
	if (mouse->curx + mouse->mouseState.lx > 0.0f && mouse->curx + mouse->mouseState.lx < 510.0f)	mouse->curx += mouse->mouseState.lx;
	this->position.x = mouse->curx;
	rect.left = position.x;
	rect.right = rect.left + 90;
	rect.top = position.y;
	rect.bottom = 30;
}

void Bat::Render(MGraphic* graphic) {
	graphic->DrawTexture(img, position, D3DCOLOR_XRGB(255, 255, 255));
}