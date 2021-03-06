﻿#include "Panther.h"

Panther::Panther(float X, float Y, int Direction, float autoGoX_Distance, Ryu * ryu)
{
	type = eType::PANTHER;
	Health = 1;
	vx = vy = 0;
	direction = Direction;
	x = X;
	y = Y;
	AutoGoX_Backup_X = x;
	AutoGoX_Distance = autoGoX_Distance;

	texture = TextureManager::GetInstance()->GetTexture(type);
	sprite = new Sprite(texture, 120);

	isWait = 1;
	isRunning = 0;
	isJumping = 0;
	isStart = 0;
	isAutoGoX = 0;

	this->ryu = ryu;
}



void Panther::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	GameObject::Update(dt);


	if (isJumping)
	{
		dx = vx * dt;
		dy = vy * dt;
		vy += PANTHER_GRAVITY_JUMPING * dt;
	}
	else
		vy += PANTHER_GRAVITY * dt;// Simple fall down

	if (isWait)
	{
		isWait = false;
		isRunning = true;
		// chuyển qua trạng thái chạy
		Run();

		isStart = 1;
		isAutoGoX = 1;
	}


	if (isWait)
	{
		sprite->SelectFrame(PANTHER_ANI_WAIT);
	}
	else
	{
		if (isRunning)
		{
			if (!isJumping) // ko đang nhảy thì chạy => đang nhảy thì cho animation đứng yên
			{
				if (PANTHER_ANI_RUNNING_BEGIN <= sprite->GetCurrentFrame() && sprite->GetCurrentFrame() < PANTHER_ANI_RUNNING_END)
				{
					sprite->Update(dt);
				}
				else
					sprite->SelectFrame(PANTHER_ANI_RUNNING_BEGIN);
			}

		}
	}



#pragma region Xét va chạm đất

	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;
	coEvents.clear();
	vector<LPGAMEOBJECT> list_Brick;
	list_Brick.clear();
	for (UINT i = 0; i < coObjects->size(); i++)
	{
		if (coObjects->at(i)->GetType() == eType::GROUND)
			list_Brick.push_back(coObjects->at(i));
	}

	CalcPotentialCollisions(&list_Brick, coEvents);
	if (coEvents.size() == 0)
	{
		x += dx;
		y += dy;
	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;
		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		x += dx;
		if (ny == -1)
			y += min_ty * dy + ny * 0.4f;
		else
			y += dy;

		if (ny == -1)
		{
			vy = 0;
			if (isJumping)
			{
				isJumping = false; // kết thúc nhảy
				Run();
			}
		}
	}
	for (UINT i = 0; i < coEvents.size(); i++)
		delete coEvents[i];
#pragma endregion


	if (isAutoGoX == true)
	{
		if (abs(x - AutoGoX_Backup_X) >= AutoGoX_Distance)
		{
			x = x - (abs(x - AutoGoX_Backup_X) - AutoGoX_Distance);
			isAutoGoX = false;
			vx = 0;

			Jump(); // Sau khi chạy xong thì nhảy

			DebugOut(L"[PANTHER] end auto go X\n");
		}
	}

}

void Panther::Render(Camera * camera)
{
	if (Health <= 0)
		return;

	//	sprite->Update(dt);

	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (direction == -1)
		sprite->Draw(pos.x, pos.y);
	else
		sprite->DrawFlipX(pos.x, pos.y);

	if (IS_DEBUG_RENDER_BBOX)
		RenderBoundingBox(camera);

}

bool Panther::GetIsStart()
{
	return isStart;
}

void Panther::Jump()
{
	if (isJumping == true)
		return;
	vy = -PANTHER_VYJUMP;
	vx = PANTHER_VXJUMP * direction;
	isJumping = true;

}

void Panther::Run()
{
	vx = PANTHER_SPEED_RUNNING * direction;
	isRunning = true;
}



Panther::~Panther()
{
}
