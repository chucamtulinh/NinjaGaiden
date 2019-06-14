#include "Bullet.h"



Bullet::Bullet(Camera *camera)
{
	texture = TextureManager::GetInstance()->GetTexture(eType::BULLET);
	sprite = new Sprite(texture, 0);
	type = eType::BULLET;
	isFinish = true;
	this->camera = camera;
}


Bullet::~Bullet()
{
}

void Bullet::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (isFinish)
		return;

	if (!camera->CHECK_OBJECT_IN_CAMERA(this)) // ra khỏi cam thì kết thúc
	{
		isFinish = true;
		return;
	}

	GameObject::Update(dt); // update dt,dx,dy 
	x += dx;
	y += dy;
	// xử lí ra khỏi cam thì xóa

}

void Bullet::Attack(float X, float Y, int Direction)
{
	Weapon::Attack(X, Y, Direction);
}

void Bullet::RenderIcon(float X, float Y)
{
}


void Bullet::Render(Camera * camera)
{
	if (isFinish)
		return;

	Weapon::Render(camera);
}
