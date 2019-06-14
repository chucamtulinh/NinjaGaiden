#include "Ryu.h"


Ryu::Ryu(Camera* camera)
{
	texture = TextureManager::GetInstance()->GetTexture(eType::RYU);
	sprite = new Sprite(texture, 200);
	_sprite_death = new Sprite(TextureManager::GetInstance()->GetTexture(eType::RYU_DEATH), 250);
	type = eType::RYU;

	this->camera = camera;
	//this->sound = Sound::GetInstance();
	mapWeapon[eType::SWORDSLASHWEAPON] = new SwordSlashWeapon();

	Init();
}


Ryu::~Ryu()
{
	SAFE_DELETE(_sprite_death);
}

void Ryu::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	if (isSitting == true)
	{
		left = x;
		top = y;
		right = x + Ryu_BBOX_WIDTH;
		bottom = y + Ryu_BBOX_SITTING_HEIGHT;
		if (isAttacking == true)
		{
			//bottom -= 1.0f;
		}
	}
	else
	{
		left = x;
		top = y;
		right = x + Ryu_BBOX_WIDTH;
		bottom = y + Ryu_BBOX_HEIGHT;

		if (isJumping) {
			bottom = y + Ryu_BBOX_JUMPING_HEIGHT;
		}
	}

}

void Ryu::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (x < camera->GetBoundaryLeft() - 16)
		x = camera->GetBoundaryLeft() - 16;
	if (x + Ryu_BBOX_WIDTH > camera->GetBoundaryRight() + SCREEN_WIDTH)
		x = (float)(camera->GetBoundaryRight() + SCREEN_WIDTH - Ryu_BBOX_WIDTH);
	/* Không cho lọt khỏi camera */

#pragma region Update về sprite

	int index = sprite->GetCurrentFrame();
	
	if (isHurting)
		{
			sprite->SelectFrame(Ryu_ANI_HURTING);
		}
	else
		{
			if (isSitting == true)
			{
				if (isAttacking == true) // tấn công
				{
					/* Xử lí ani ngồi đánh */
					if (index < Ryu_ANI_SITTING_ATTACKING_BEGIN) // nếu ani chưa đúng
					{
						sprite->SelectFrame(Ryu_ANI_SITTING_ATTACKING_BEGIN); // set lại ani bắt đầu
						sprite->timeAccumulated = dt;
					}
					else
					{
						/* Update ani bình thường */
						sprite->timeAccumulated += dt;
						if (sprite->timeAccumulated >= Ryu_TIME_WAIT_ANI_ATTACKING)
						{
							sprite->timeAccumulated -= Ryu_TIME_WAIT_ANI_ATTACKING;
							sprite->SelectFrame(sprite->GetCurrentFrame() + 1);
						}
						/* Update ani bình thường */

						if (sprite->GetCurrentFrame() > Ryu_ANI_SITTING_ATTACKING_END) // đã đi vượt qua frame cuối
						{
							isAttacking = false;
							y = y - 1.0f;
							sprite->SelectFrame(Ryu_ANI_SITTING);
						}
					}
					/* Xử lí ani ngồi đánh */
					DebugOut(L"update ani Ryu dt = %d, tich luy = %d\n", dt, sprite->timeAccumulated);

				}
				else
					sprite->SelectFrame(Ryu_ANI_SITTING);
			}
			else
				if (isAttacking == true && isSitting == false)
				{
					/* Xử lí ani đứng đánh */
					if (index < Ryu_ANI_STANDING_ATTACKING_BEGIN) // nếu ani chưa đúng
					{
						sprite->SelectFrame(Ryu_ANI_STANDING_ATTACKING_BEGIN); // set lại ani bắt đầu
						sprite->timeAccumulated = dt;
					}
					else
					{
						/* Update ani bình thường */
						sprite->timeAccumulated += dt;
						if (sprite->timeAccumulated >= Ryu_TIME_WAIT_ANI_ATTACKING)
						{
							sprite->timeAccumulated -= Ryu_TIME_WAIT_ANI_ATTACKING;
							sprite->SelectFrame(sprite->GetCurrentFrame() + 1);
						}
						/* Update ani bình thường */

						if (sprite->GetCurrentFrame() > Ryu_ANI_STANDING_ATTACKING_END) // đã đi vượt qua frame cuối
						{
							//mapWeapon[TypeWeaponCollect]->Start(this->x, this->y);

							isAttacking = false;
							sprite->SelectFrame(Ryu_ANI_IDLE);
						}
					}
					/* Xử lí ani đứng đánh */

				}
				else
					if (isRunning == true) // đang di chuyển
					{
						if (isJumping == false) // ko nhảy
						{
							if (index < Ryu_ANI_RUNNING_BEGIN || index >= Ryu_ANI_RUNNING_END)
								sprite->SelectFrame(Ryu_ANI_RUNNING_BEGIN);

							//cập nhật frame mới
							sprite->Update(dt); // dt này được cập nhật khi gọi update; 
						}
						else						
						{
							sprite->timeAccumulated += dt;
							if (index < Ryu_ANI_JUMPING_BEGIN || index > Ryu_ANI_JUNPING_END) // nếu ani chưa đúng
								sprite->SelectFrame(Ryu_ANI_JUMPING_BEGIN); // set lại ani bắt đầu
							sprite->Update(dt);

						}
					}
					else if (isJumping == true) // nếu ko đi mà chỉ nhảy
					{
						sprite->timeAccumulated += dt;
						if (index < Ryu_ANI_JUMPING_BEGIN || index > Ryu_ANI_JUNPING_END) // nếu ani chưa đúng
						{
							sprite->SelectFrame(Ryu_ANI_JUMPING_BEGIN); // set lại ani bắt đầu
							sprite->timeAccumulated = dt;
						}
						else
						{
							/* Update ani bình thường */
							sprite->timeAccumulated += dt;
							if (sprite->timeAccumulated >= Ryu_TIME_WAIT_ANI_JUMPING)
							{
								sprite->timeAccumulated -= Ryu_TIME_WAIT_ANI_JUMPING;
								sprite->SelectFrame(sprite->GetCurrentFrame() + 1);
							}
							/* Update ani bình thường */

							if (sprite->GetCurrentFrame() > Ryu_ANI_JUNPING_END) // đã đi vượt qua frame cuối
							{
								sprite->SelectFrame(Ryu_ANI_IDLE); // set lại ani bắt đầu							
								isJumping == false;
							}
						}

					}
					else
					{
						sprite->SelectFrame(Ryu_ANI_IDLE);		// Ryu đứng yên
						DebugOut(L"update ani Ryu y = %f", y);
					}
		}
	
#pragma endregion

	/* Update về sprite */


	GameObject::Update(dt);
	if (isJumping)
		{
			if (isRunning == true) vx = Ryu_RUNNING_SPEED * direction;
			dx = vx * dt;
			dy = vy * dt;
			vy += Ryu_GRAVITY_JUMPING * dt;
		}
	else
		{
			if (isHurting)
			{
				vy += Ryu_GRAVITY_HURTING * dt;
			}
			else
				vy += Ryu_GRAVITY * dt;// Simple fall down
		}
	
	CollisionWithGround(coObjects); // check Collision and update x, y for Ryu
	for (auto& objWeapon : mapWeapon)
	{
		if (objWeapon.second->GetFinish() == false) // vũ khi này chưa kết thúc thì update
		{
			if (objWeapon.second->GetType() == eType::SWORDSLASHWEAPON)
			{
				objWeapon.second->SetPosition(this->x, this->y);
				objWeapon.second->SetSpeed(vx, vy); // set vận tốc để kt va chạm
				objWeapon.second->UpdatePositionFitRyu();
			}

			objWeapon.second->Update(dt, coObjects);
		}
	}
}

void Ryu::Render(Camera* camera)
{
	if (IS_DEBUG_RENDER_BBOX)
		RenderBoundingBox(camera);

	D3DXVECTOR2 pos = camera->Transform(x, y);

	int alpha = 255;

	if (untouchable)
		alpha = 128;

	if (isDeath && isCollisionAxisYWithGround)
	{
		if (direction == -1)
			_sprite_death->Draw(pos.x, pos.y, 255);
		else
			_sprite_death->DrawFlipX(pos.x, pos.y, 255);
	}
	else
	{
		if (this->GetFreeze() == true)
		{
			if (direction == -1)
				sprite->Draw(pos.x, pos.y, alpha, rand() % 256, rand() % 256, rand() % 256);
			else
				sprite->DrawFlipX(pos.x, pos.y, alpha, rand() % 256, rand() % 256, rand() % 256);

		}
		else
		{
			if (direction == -1)
				sprite->Draw(pos.x, pos.y, alpha);
			else
				sprite->DrawFlipX(pos.x, pos.y, alpha);
		}
	}

	for (auto& objWeapon : mapWeapon)
	{

		if (objWeapon.second->GetFinish() == false ) // vũ khi này chưa kết thúc thì render
		{
			objWeapon.second->Render(camera);
		}
	}
}

void Ryu::Left()
{
	direction = -1;
}

void Ryu::Right()
{
	direction = 1;
}

void Ryu::Go()
{
	if (isAttacking == true)
		return;

	vx = Ryu_RUNNING_SPEED * direction;
	isRunning = 1;

}

void Ryu::Sit()
{
	vx = 0;
	isRunning = false;
	isSitting = true;
}

void Ryu::ResetSit()
{
	if (isSitting == true)
	{
		isSitting = 0;
		y = y - PULL_UP_Ryu_AFTER_SITTING;
	}
}

void Ryu::Jump()
{
	if (isJumping == true)
		return;

	if (isSitting == true)
		return;

	if (isAttacking == true)
		return;

	if (isHurting)
		return;

	vy = -Ryu_VJUMP;
	isJumping = true;
}

void Ryu::Stop()
{
	if (isAttacking == true)
		return;

	if (isHurting)
		return;

	vx = 0;
	//DebugOut(L"[STOP] Set vx = %f \n", vx);


	isRunning = 0;
	if (isSitting == true)
	{
		isSitting = 0;
		y = y - PULL_UP_Ryu_AFTER_SITTING;
	}

}

void Ryu::SetHurt(LPCOLLISIONEVENT e)
{
	if (isHurting == true)
		return;

	if (e->nx == 0 && e->ny == 0) // ko có va chạm
		return;

	isRunning = 0;
	isAttacking = 0;
	isJumping = 0;

	ResetSit();

	mapWeapon[eType::SWORDSLASHWEAPON]->SetFinish(true);

	if (!isAutoGoX) // ko "đang tự đi" và ko "đang trên thang" thì bật ra
	{
		if (e->nx != 0)
		{
			vx = Ryu_RUNNING_SPEED * e->nx;
			vy = -Ryu_VJUMP_HURTING;
			isHurting = 1;
			//DebugOut(L"[SetHurt] Set vx = %f \n", vx);
		}

		if (e->ny != 0)
		{
			vy = -Ryu_VJUMP_HURTING;
			isHurting = 1;
			//DebugOut(L"[SetHurt] Set vy = %f \n", vy);
		}
	}
	else
	{
		isRunning = 1;
		//isHurting = 1;
	}

	StartUntouchable(); // không cho các object đụng tiếp


	SubHealth(2); // chạm enemy -2 máu
	//sound->Play(eSound::soundHurting);
}

void Ryu::SetManaCollect(int h)
{
	ManaCollect = h;
}

int Ryu::GetManaCollect()
{
	return ManaCollect;
}

void Ryu::CollisionWithGround(const vector<LPGAMEOBJECT>* coObjects)
{
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	vector<LPGAMEOBJECT> list_Ground;
	list_Ground.clear();
	for (UINT i = 0; i < coObjects->size(); i++)
		if (coObjects->at(i)->GetType() == eType::GROUND)
			list_Ground.push_back(coObjects->at(i));

	CalcPotentialCollisions(&list_Ground, coEvents);

	if (coEvents.size() == 0)
	{
		x += dx;
		y += dy;
		isCollisionAxisYWithGround = false; // đang ko va chạm trục y
										   //	DebugOut(L"%d : Col y = false (size = 0) - dt = %d - y = %f - dy = %f\n",GetTickCount(),dt,y, dy);
	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;
		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		x += min_tx * dx + nx * 0.4f;

		if (ny == -1)
			y += min_ty * dy + ny * 0.4f;
		else
			y += dy;

		if (ny == -1)
		{
			vy = 0.1f;
			dy = vy * dt;

			if (isJumping)
			{
				isJumping = false;
				y = y - PULL_UP_Ryu_AFTER_JUMPING;
			}
		}


		if (ny != 0)
		{
			isCollisionAxisYWithGround = true;
			//		DebugOut(L"%d : Col y = true - dt=%d - y = %f - dy = %f\n", GetTickCount(), dt,y, dy);
		}
		else
		{
			//	DebugOut(L"%d : Col y = false - dt=%d\n", GetTickCount(), dt);
			isCollisionAxisYWithGround = false;// đang ko va chạm trục y
		}



		if (nx != 0 || ny != 0)
		{
			isHurting = 0;
		}

	}

	for (UINT i = 0; i < coEvents.size(); i++)
		delete coEvents[i];
}

//bool Ryu::isCollisionWithItem(Item * objItem)
//{
//	if (objItem->GetFinish() == true)
//		return false;
//
//	float l, t, r, b;
//	float l1, t1, r1, b1;
//	this->GetBoundingBox(l, t, r, b);  // lấy BBOX của Ryu
//
//	objItem->GetBoundingBox(l1, t1, r1, b1);
//	if (Game::GetInstance()->checkAABB(l, t, r, b, l1, t1, r1, b1) == true)
//	{
//		return true; // check with AABB
//	}
//
//	return isCollitionObjectWithObject(objItem);
//}

void Ryu::Attack(eType typeWeapon)
{
	//if (typeWeapon == eType::NON_WEAPON_COLLECT) // nếu dùng type NON_WEAPON_COLLECT thì bỏ qua
	//{
	//	return;
	//}

	/* Kiểm tra còn đủ ManaCollect ko? */
	switch (typeWeapon)
	{
	case SWORDSLASHWEAPON:
	{
		if (isAttacking)
		{
			return;
		}
		break;
	}

	default: // các vũ khí còn lại
	{
		if (ManaCollect >= 1)
		{
			//	ManaCollect -= 1;
		}
		else
			return;// ko đủ ManaCollect thì ko attack
		break;
	}
	}

	bool isAllowSubManaCollect = false;

	if (mapWeapon[typeWeapon]->GetFinish()) // vũ khí đã kết thúc thì mới đc tấn công tiếp
	{
		isAttacking = true; // set trang thái tấn công
		sprite->SelectFrame(0);
		sprite->ResetTime();

		mapWeapon[typeWeapon]->Attack(this->x, this->y, this->direction); // set vị trí weapon theo Ryu
		isAllowSubManaCollect = true;
	}

	if (isAllowSubManaCollect)
	{
		switch (typeWeapon)
		{
		case SWORDSLASHWEAPON:
		{
			// ko trừ
			break;
		}

		/*case :
		{
			ManaCollect -= 5;
			break;
		}*/

		default: // các vũ khí còn lại
		{
			ManaCollect -= 1;
			break;
		}
		}
	}

}

int Ryu::GetLives()
{
	return Lives;
}

void Ryu::SetLives(int l)
{
	Lives = l;
}

int Ryu::GetScore()
{
	return score;
}

void Ryu::SetScore(int s)
{
	score = s;
}

bool Ryu::GetFreeze()
{
	return isFreeze;
}

void Ryu::SetFreeze(int f)
{
	isFreeze = f;
	TimeFreeze = 0; // thời gian đã đóng băng
}

void Ryu::UpdateFreeze(DWORD dt)
{
	if (TimeFreeze + dt >= TIME_FREEZE_MAX)
	{
		SetFreeze(false); // kết thúc đóng băng
	}
	else
		TimeFreeze += dt;
}

void Ryu::StartUntouchable()
{
	untouchable = true;
	untouchable_start = GetTickCount();
}

void Ryu::SetAutoGoX(int DirectionGo, int directionAfterGo, float Distance, float Speed)
{
	if (isAutoGoX == true)
		return;

	isAutoGoX = true;// chưa vào chế độ autoGo thì set

	AutoGoX_Backup_X = x; // set lại vị trí trước khi đi tự động

						  //Backup trạng thái
	isRunning_Backup = isRunning;
	isJumping_Backup = isJumping;
	isSitting_Backup = isSitting;
	isAttacking_Backup = isAttacking;
	directionY_Backup = directionY;

	AutoGoX_Distance = Distance;
	AutoGoX_Speed = Speed;
	AutoGoX_DirectionGo = (float)DirectionGo;
	this->directionAfterGo = directionAfterGo;


	direction = DirectionGo;
	vx = Speed * DirectionGo;
	isRunning = 1;
	isJumping = 0;
	isSitting = 0;
	isAttacking = 0;
}

bool Ryu::GetIsAutoGoX()
{
	return isAutoGoX;
}

void Ryu::RestoreBackupAutoGoX()
{
	isRunning = isRunning_Backup;
	isJumping = isJumping_Backup;
	isSitting = isSitting_Backup;
	isAttacking = isAttacking_Backup;
	directionY = directionY_Backup;

	direction = directionAfterGo; // set hướng sau khi đi

	isRunning = 0; // tắt trạng thái đang đi
	isAutoGoX = 0; // tắt trạng thái auto

	vx = 0;
	vy = 0;
	// đi xong thì cho Ryu đứng yên
}

void Ryu::SetPositionBackup(float X, float Y)
{
	PositionBackup = D3DXVECTOR2(X, Y);
}

void Ryu::SetDeath()
{
	SetIsDeath(true);
	TimeWaitedAfterDeath = 0;

	ResetSit();
	vx = 0;
	isRunning = 0;

	//sound->Play(eSound::musicLifeLost);

	Stop();
}

bool Ryu::GetIsDeath()
{
	return isDeath;
}

void Ryu::SetIsDeath(bool b)
{
	isDeath = b;
}

eType Ryu::GetTypeWeaponCollect()
{
	return TypeWeaponCollect;
}

void Ryu::SetTypeWeaponCollect(eType t)
{
	TypeWeaponCollect = t;
}

void Ryu::ProcessWeaponCollect(eType t)
{
	switch (t)
	{

	/*case DAGGER:
	{
		if (mapWeapon[t] == NULL)
		{
			mapWeapon[t] = new Dagger(camera);
		}

		break;
	}

	case HOLYWATER:
	{
		if (mapWeapon[t] == NULL)
		{
			mapWeapon[t] = new HolyWater(camera);
		}
		break;
	}

	case STOPWATCH:
	{
		if (mapWeapon[t] == NULL)
		{
			mapWeapon[t] = new StopWatch();
		}
		break;
	}

	case THROWINGAXE:
	{
		if (mapWeapon[t] == NULL)
		{
			mapWeapon[t] = new ThrowingAxe(camera);
		}
		break;
	}

	case BOOMERANG:
	{
		if (mapWeapon[t] == NULL)
		{
			mapWeapon[t] = new Boomerang(camera, this);
		}
		break;
	}*/
	default:
		break;
	}

	//sound->Play(eSound::soundCollectWeapon);
	SetTypeWeaponCollect(t); // set kiểu vũ khí đang nhặt được
}

bool Ryu::IsUsingWeapon(eType typeWeapon)
{
	if (this->mapWeapon.find(typeWeapon) != this->mapWeapon.end()) // có tồn tại
	{
		if (this->mapWeapon[typeWeapon]->GetFinish() == false) //chưa kết thúc
			return true;
	}
	return false;
}

bool Ryu::GetIsUseDoubleShot()
{
	return isUseDoubleShot;
}

void Ryu::SetIsUseDoubleShot(bool b)
{
	isUseDoubleShot = b;
}

void Ryu::Init()
{
	Health = Ryu_DEFAULT_HEALTH; // Ryu dính 16 phát là chết
	Lives = Ryu_DEFAULT_LIVES;
	ManaCollect = Ryu_DEFAULT_MANACOLLECT;
	score = Ryu_DEFAULT_SCORE;

	Reset();
}

void Ryu::Reset()
{

	direction = 1;

	isSitting = 0;
	isJumping = 0;
	isRunning = 0;
	isAttacking = 0;

	isAutoGoX = 0;
	isHurting = 0;

	vx = 0;
	vy = 0;
	isFreeze = 0;
	TimeFreeze = 0;

	isDeath = false;
	isUseDoubleShot = false;
	//TypeWeaponCollect = eType::NON_WEAPON_COLLECT;
}

bool Ryu::LoseLife()
{
	if (Lives - 1 < 0)
		return false;

	Health = Ryu_DEFAULT_HEALTH;
	Lives = Lives - 1;

	ManaCollect = Ryu_DEFAULT_MANACOLLECT;



	Reset();


	x = PositionBackup.x;
	y = PositionBackup.y;

	return true;
}
