#include "Ball.h"



Ball::Ball(void)
{
}

void Ball::Init(MContent* content) {
	this->img = content->LoadTexture("ball.png");
	this->position = D3DXVECTOR2(300, 400);
	dx = dy = 1;
	speed = 3.0f;
	bball.x = position.x;
	bball.y = position.y;
	bball.w = 40.0f;
	bball.y = 40.0f;
	bball.vx = dx * speed;
	bball.vy = dy * speed;
}

void Ball::Update(float gameTime) {
	if (position.x + dx * speed < 10 || position.x + dx * speed + 40.0 > 590) dx = -dx;
	if (position.y + dy * speed < 10 || position.y + dy * speed + 40.0 > 790) dy = -dy;
	bball.vx = dx * speed;
	bball.vy = dy * speed;
	position.x += bball.vx;
	position.y += bball.vy;
	bball.x = position.x;
	bball.y = position.y;
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
