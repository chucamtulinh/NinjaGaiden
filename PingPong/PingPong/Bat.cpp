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
	this->img = content->LoadTexture("batDown.png");
	this->position = D3DXVECTOR2(200, 760);
	speed = 5.0f;
	bbat.x = position.x;
	bbat.y = position.y;
	bbat.w = 90.0f;
	bbat.y = 30.0f;
	bbat.vx = speed;
	bbat.vy = speed;
}

void Bat::InitUp(MContent* content) {
	this->img = content->LoadTexture("batUp.png");
	this->position = D3DXVECTOR2(200, 10);
	speed = 1;
	bbat.x = position.x;
	bbat.y = position.y;
	bbat.w = 90.0f;
	bbat.y = 30.0f;
	bbat.vx = speed;
	bbat.vy = speed;
}

void Bat::Update(float gameTime, MKeyboard* key) {

	if (key->IsKeyDown(DIK_LEFT)) {
		if (position.x > 10.0f) this->position.x -= speed;
	}
	if (key->IsKeyDown(DIK_RIGHT)) {
		if (position.x + 90.0f < 590.0f) this->position.x += speed;
	}
	bbat.x = position.x;
	bbat.y = position.y;
	rect.left = position.x;
	rect.right = rect.left + 90;
	rect.top = position.y;
	rect.bottom = rect.top + 30;
}

void Bat::Update2(float gameTime, MKeyboard* key) {

	if (key->IsKeyDown(DIK_A)) {
		if (position.x > 10.0f) this->position.x -= speed;
	}
	if (key->IsKeyDown(DIK_D)) {
		if (position.x + 90.0f < 590.0f) this->position.x += speed;
	}
	bbat.x = position.x;
	bbat.y = position.y;
	rect.left = position.x;
	rect.right = rect.left + 90;
	rect.top = position.y;
	rect.bottom = rect.top + 30;
}

void Bat::Update(float gameTime, MMouse* mouse) {
	/*if (BUTTONDOWN(mouse->mouseState, 0) && position.x > 0.0f) this->position.x -= speed;
	if (BUTTONDOWN(mouse->mouseState, 1) && position.x + 90.0f < 300.0f) this->position.x += speed;*/
	if (mouse->curx + mouse->mouseState.lx > 10.0f && mouse->curx + mouse->mouseState.lx < 500.0f)	mouse->curx += mouse->mouseState.lx;
	this->position.x = mouse->curx;
	bbat.x = position.x;
	bbat.y = position.y;
	rect.left = position.x;
	rect.right = rect.left + 90;
	rect.top = position.y;
	rect.bottom = rect.top + 30;
}

void Bat::Render(MGraphic* graphic) {
	graphic->DrawTexture(img, position, D3DCOLOR_XRGB(255, 255, 255));
}