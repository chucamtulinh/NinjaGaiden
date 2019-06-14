#include "Banshee.h"

Banshee::Banshee(float X, float Y, int Direction, float autoGoX_Distance, float autoGoX_Distance2, Ryu * ryu, vector<Weapon*> *listWeaponOfEnemy, Camera * camera)
{
	type = eType::PANTHER;
	Health = 1;
	vx = vy = 0;
	direction = Direction;
	x = X;
	y = Y;
	AutoGoX_Backup_X = x;
	AutoGoX_Distance = autoGoX_Distance;
	AutoGoX_Distance2 = autoGoX_Distance2;

	texture = TextureManager::GetInstance()->GetTexture(type);
	sprite = new Sprite(texture, 120);
	TimeAttack = GetTickCount();
	isWait = 1;
	isStart = 0;
	isAttacking = 0;
	isAutoGoX = 0;

	this->ryu = ryu;
	this->listWeaponOfEnemy = listWeaponOfEnemy;
	this->camera = camera;
}



void Banshee::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	GameObject::Update(dt);

	vy += BANSHEE_GRAVITY * dt;// Simple fall down

	// chuyển qua trạng thái chạy
	if (isWait)
	{
		isWait = false;
		isStart = true;
		vx = BANSHEE_SPEED_RUNNING * direction;
		isAutoGoX = 1;
	}


	if (isWait)
	{
		sprite->SelectFrame(BANSHEE_ANI_WAIT);
	}
	else
	{
		if (isStart)
		{
			if (BANSHEE_ANI_RUNNING_BEGIN <= sprite->GetCurrentFrame() && sprite->GetCurrentFrame() < BANSHEE_ANI_RUNNING_END)
			{
				sprite->Update(dt);
			}
			else
				sprite->SelectFrame(BANSHEE_ANI_RUNNING_BEGIN);
		}
	}

	TimeDelay = GetTickCount();
	if (TimeDelay - TimeAttack > 1000)
	{
		Attack();
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

		}
	}
	for (UINT i = 0; i < coEvents.size(); i++)
		delete coEvents[i];
#pragma endregion


	if (isAutoGoX == true)
	{
		if (abs(x - AutoGoX_Backup_X) >= AutoGoX_Distance)
		{
			isAutoGoX = false;
			AutoGoX_Backup_X = x;
			vx *= -1;
			DebugOut(L"[SWORDMAN] end auto go X\n");
		}
	}
	if (abs(x - AutoGoX_Backup_X) >= AutoGoX_Distance2)
	{
		isAutoGoX = false;
		AutoGoX_Backup_X = x;
		vx *= -1;
	}
	if ((direction == -1 && !(ryu->GetX() < x)) ||
		(direction == 1 && !(x < ryu->GetX()))) // đi về hướng của simon mà đã vượt simon thì mới đổi hướng
	{
		direction *= -1; //đổi hướng đi
		//xInit = x;
	}
}

void Banshee::Render(Camera * camera)
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

bool Banshee::GetIsStart()
{
	return isStart;
}

Banshee::~Banshee()
{
}

void Banshee::Attack()
{
	if (weapon1 == NULL)
	{
		weapon1 = new ThrowCross(camera);
		listWeaponOfEnemy->push_back(weapon1);
	}

	if (weapon1->GetFinish() == false)
		return;

	isAttacking = true;
	TimeAttack = GetTickCount();

	//weapon1->SetSpeed(THROWINGAXE_SPEED_X * direction, 0);
	weapon1->Attack(x + 10, y + 3, direction);

}