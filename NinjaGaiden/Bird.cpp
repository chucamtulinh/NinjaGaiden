#include "Bird.h"


Bird::Bird(float X, float Y, int Direction, Ryu* ryu)
{
	type = eType::BIRD;
	texture = TextureManager::GetInstance()->GetTexture(type);
	sprite = new Sprite(texture, 70);

	this->x = X;
	this->y = Y;
	this->direction = Direction;
	this->Health = 1;

	vy = BIRD_SPEED_Y;
	vx = BIRD_SPEED_X * Direction;

	this->ryu= ryu;
}

Bird::~Bird()
{
}


void Bird::Update(DWORD dt, vector<LPGAMEOBJECT>* listObject)
{
	if (ryu->GetY() > y)
	{
		y += 1.5;
	}
	else if (ryu->GetY() < y)
	{
		y -= 1;
	}

	if ((direction == -1 && !(ryu->GetX() > x))) // đi về hướng của ryu mà đã vượt simon thì mới đổi hướng
	{
		vx += -0.005;
	}
	else
	{
		vx += 0.008;
	}

	if (!vx)
	{
		direction *= -1;
	}
	GameObject::Update(dt); // Update dt, dx, dy

	y += dy;
	x += dx;

	sprite->Update(dt);
	if (sprite->GetCurrentFrame() == 0)
		sprite->Update(dt);
}

void Bird::Render(Camera * camera)
{
	if (Health <= 0)
		return;

	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (direction == -1)
		sprite->Draw(pos.x, pos.y);
	else
		sprite->DrawFlipX(pos.x, pos.y);

	if (IS_DEBUG_RENDER_BBOX)
		RenderBoundingBox(camera);
}
