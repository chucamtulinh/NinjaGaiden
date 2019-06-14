#include "Banshee.h"


Banshee::Banshee(float X, float Y, int Direction, Simon* simon, vector<Weapon*> *listWeaponOfEnemy, Camera * camera)
{
	texture = TextureManager::GetInstance()->GetTexture(eType::FISHMEN);
	sprite = new GSprite(texture, 200);
	type = eType::FISHMEN;

	this->x = X;
	this->y = Y;
	this->direction = Direction;
	this->Health = 1;
	vx = 0;
	vy = -FISHMEN_SPEED_Y_UP;

	yInit = y;
	xInit = x;
	xAccumulationAttack = 0;

	sprite->SelectFrame(FISHMEN_ANI_JUMP);

	isRunning = 0;
	isAttacking = false;

	this->simon = simon;
	this->listWeaponOfEnemy = listWeaponOfEnemy;
	this->camera = camera;
}

Fishmen::~Fishmen()
{
}

void Fishmen::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x + 5;
	top = y + 15;
	right = x + texture->GetFrameWidth() - 5;
	bottom = y + texture->GetFrameHeight();
}

void Fishmen::Update(DWORD dt, vector<LPGAMEOBJECT>* listObject)
{
	if (y <= yInit - FISHMEN_DY_JUMP)
	{
		vy = FISHMEN_SPEED_Y_DOWN;
	}


	if (abs(x - xInit) >= FISHMEN_DX_LIMIT) // di d? kho?ng c? d?nh
	{
		if ((direction == -1 && !(simon->GetX() < x)) ||
			(direction == 1 && !(x < simon->GetX()))) // di v? hu?ng c?a simon m� d� vu?t simon th� m?i d?i hu?ng
		{
			direction *= -1; //d?i hu?ng di
			xInit = x;
		}
	}


	if (xAccumulationAttack >= FISHMEN_DX_ATTACK_LIMIT)
	{
		xAccumulationAttack = 0;
		Attack();
	}

	xBefore = x;


	if (isRunning)
	{
		vx = direction * FISHMEN_SPEED_X;
		vy += FISHMEN_GRAVITY;
	}

	GameObject::Update(dt);

#pragma region Xu li va cham Brick
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;
	coEvents.clear();
	vector<LPGAMEOBJECT> list_Brick;
	list_Brick.clear();

	for (UINT i = 0; i < listObject->size(); i++)
		if (listObject->at(i)->GetType() == eType::BRICK)
			list_Brick.push_back(listObject->at(i));

	CalcPotentialCollisions(&list_Brick, coEvents);

	float min_tx, min_ty, nx = 0, ny;
	FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

	if (ny == -1)
	{
		vy = 0;
		y += min_ty * dy + ny * 0.4f;
		isRunning = true;
	}
	else
	{
		y += dy;
	}

	if (!isAttacking) // dang t?n c�ng th� v?n cho tr?ng l?c k�o xu?ng
	{
		bool isCollisionDirectionX = false;
		for (UINT i = 0; i < coEventsResult.size(); i++) // kh�ng cho fishmen vu?t qua g?ch lo?i nh? theo tr?c x
		{
			if (coEventsResult[i]->nx != 0)
			{
				Brick * brick = dynamic_cast<Brick*>(coEventsResult[i]->obj);
				if (brick->GetModel() == BRICK_MODEL_3)
				{
					x += min_tx * dx + nx * 0.4f;
					direction *= -1; // quay ngu?c hu?ng di 
					isCollisionDirectionX = true;
				}
			}
		}

		if (!isCollisionDirectionX) // ko va ch?m v?i tr?c x 
			x += dx;
	}


	for (UINT i = 0; i < coEvents.size(); i++)
		delete coEvents[i];
#pragma endregion


	if (isAttacking)
	{
		DWORD now = GetTickCount();
		if (now - TimeAttack >= FISHMEN_TIME_LIMIT_WAIT_AFTER_ATTACK)
		{
			isAttacking = false;
		}
	}

	xAfter = x;
	xAccumulationAttack += abs(xAfter - xBefore);


#pragma region Update Animation
	if (isAttacking)
	{
		sprite->SelectFrame(FISHMEN_ANI_ATTACK);
	}
	else
		if (isRunning)
		{
			int index = sprite->GetCurrentFrame();

			if (FISHMEN_ANI_WALK_BEGIN <= index && index <= FISHMEN_ANI_WALK_END)
				sprite->Update(dt);

			if (sprite->GetCurrentFrame() == FISHMEN_ANI_ATTACK) // dang trong tr?ng th�i di m� quay v? frame attack th� set th�nh frame di
				sprite->SelectFrame(FISHMEN_ANI_WALK_BEGIN);

		}
#pragma endregion

}

void Fishmen::Render(Camera * camera)
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

void Fishmen::Attack()
{
	if (isAttacking)
		return;

	if (weapon == NULL)
	{
		weapon = new FireBall(camera);
		listWeaponOfEnemy->push_back(weapon);
	}

	if (weapon->GetFinish() == false)
		return;

	isAttacking = true;
	TimeAttack = GetTickCount();

	weapon->SetSpeed(FIREBALL_SPEED * direction, 0);
	weapon->Attack(x + 10, y + 3, direction);

}
