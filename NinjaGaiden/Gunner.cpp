#include "Gunner.h"


Gunner::Gunner(float X, float Y, int Direction, Ryu* ryu, vector<Weapon*> *listWeaponOfEnemy, Camera * camera)
{
	texture = TextureManager::GetInstance()->GetTexture(eType::GUNGUY);
	sprite = new Sprite(texture, 200);
	type = eType::GUNNER;

	this->x = X;
	this->y = Y;
	this->direction = Direction;
	this->Health = 1;
	vx = 0;
	vy = 0;

	isAttacking = false;
	sprite->SelectFrame(GUNNER_ANI_ATTACK);
	this->ryu = ryu;
	this->listWeaponOfEnemy = listWeaponOfEnemy;
	this->camera = camera;
}

Gunner::~Gunner()
{
}

void Gunner::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x + 5;
	top = y + 15;
	right = x + texture->GetFrameWidth() - 5;
	bottom = y + texture->GetFrameHeight();
}

void Gunner::Update(DWORD dt, vector<LPGAMEOBJECT>* listObject)
{
		if ((direction == -1 && !(ryu->GetX() < x)) ||
			(direction == 1 && !(x < ryu->GetX()))) // hướng mặt về phía ryu, mà đã vượt ryu thì mới đổi hướng
		{
			direction *= -1; //đổi hướng đi

		}
	DWORD gh = GetTickCount();

	if (gh - TimeDelay >= TIME_ATTACK_DELAY)
	{
		Attack();
	}
	GameObject::Update(dt);

#pragma region Xu li va cham Ground
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;
	coEvents.clear();
	vector<LPGAMEOBJECT> list_Ground;
	list_Ground.clear();

	for (UINT i = 0; i < listObject->size(); i++)
		if (listObject->at(i)->GetType() == eType::GROUND)
			list_Ground.push_back(listObject->at(i));

	CalcPotentialCollisions(&list_Ground, coEvents);

	float min_tx, min_ty, nx = 0, ny;
	FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

	if (ny == -1)
	{
		vy = 0;
		y += min_ty * dy + ny * 0.4f;
	}
	else
	{
		y += dy;
	}

	for (UINT i = 0; i < coEvents.size(); i++)
		delete coEvents[i];
#pragma endregion


	if (isAttacking)
	{
		DWORD now = GetTickCount();
		if (now - TimeAttack >= TIME_ATTACK_DELAY)
		{
			isAttacking = false;
			TimeDelay = GetTickCount();
		}
	}

	//xAfter = x;
	//xAccumulationAttack += abs(xAfter - xBefore);


#pragma region Update Animation
	if (isAttacking)
	{
		sprite->SelectFrame(GUNNER_ANI_ATTACK);
	}
	
#pragma endregion

}

void Gunner::Render(Camera * camera)
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

void Gunner::Attack()
{
	if (isAttacking)
		return;

	if (weapon == NULL)
	{
		weapon = new Bullet(camera);
		listWeaponOfEnemy->push_back(weapon);
	}

	if (weapon->GetFinish() == false)
		return;

	isAttacking = true;
	TimeAttack = GetTickCount();

	weapon->SetSpeed(BULLET_SPEED * direction, 0);
	weapon->Attack(x + 10, y + 3, direction);

}
