#include "Bird.h"


Bird::Bird(float X, float Y, int Direction)
{
	type = eType::BIRD;
	texture = TextureManager::GetInstance()->GetTexture(type);
	sprite = new Sprite(texture, 70);

	this->x = X;
	this->y = Y;
	this->yBackup = y;
	this->direction = Direction;
	this->Health = 1;

	vy = BIRD_SPEED_Y;
	vx = BIRD_SPEED_X * Direction;
}

Bird::~Bird()
{
}


void Bird::Update(DWORD dt, vector<LPGAMEOBJECT>* listObject)
{
	// vượt quá biên độ trục y cho phép thì đổi chiều vy
	if (y - yBackup >= DeltaY)
	{
		vy = -BIRD_SPEED_Y;
	}
	else
		if (y - yBackup <= -DeltaY)
		{
			vy = BIRD_SPEED_Y;
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
