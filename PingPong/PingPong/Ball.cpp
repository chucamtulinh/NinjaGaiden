#include "Ball.h"



Ball::Ball(void)
{
}

void Ball::Init(MContent* content) {
	this->img = content->LoadTexture("ball.png");
	this->position = D3DXVECTOR2(300, 400);
	dx = dy = 1;
}

void Ball::Update(float gameTime) {
	float speed = 4;
	if (position.x < 10 || position.x + 35.0 > 590) dx = -dx;
	if (position.y < 10 || position.y + 35.0 > 790) dy = -dy;
	position.x += dx * speed;
	position.y += dy * speed;
	rect.left = position.x;
	rect.top = position.y;
	rect.right = 40;
	rect.bottom = 40;
}

void Ball::Render(MGraphic* graphic) {
	graphic->DrawTexture(this->img, this->position, D3DCOLOR_XRGB(255, 255, 255));
}

Ball::~Ball(void)
{
}
