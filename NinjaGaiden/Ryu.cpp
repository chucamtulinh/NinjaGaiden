﻿#include "Ryu.h"


Ryu::Ryu(Camera* camera)
{
	texture = TextureManager::GetInstance()->GetTexture(eType::RYU);
	sprite = new Sprite(texture, 250);
	_sprite_death = new Sprite(TextureManager::GetInstance()->GetTexture(eType::RYU_DEATH), 250);
	type = eType::RYU;


	this->camera = camera;
	//this->sound = Sound::GetInstance();
	//mapWeapon[eType::MORNINGSTAR] = new MorningStar();

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
		left = x + 15;
		top = y - 1;
		right = x + Ryu_BBOX_WIDTH - 15;
		bottom = y + Ryu_BBOX_SITTING_HEIGHT;
	}
	else
	{
		left = x + 15;
		top = y - 1;
		right = x + Ryu_BBOX_WIDTH - 15;
		bottom = y + Ryu_BBOX_HEIGHT;

		if (isJumping)
			bottom = y + Ryu_BBOX_JUMPING_HEIGHT;
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

	if (isOnStair)
	{
		if (isAttacking == true) // tấn công
		{
			if (directionY == -1) // đang đi lên
			{
				/* Xử lí ani đánh khi đang đi lên thang*/
				if (index < Ryu_ANI_STAIR_UP_ATTACKING_BEGIN) // nếu ani chưa đúng
				{
					sprite->SelectFrame(Ryu_ANI_STAIR_UP_ATTACKING_BEGIN); // set lại ani bắt đầu
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

					if (sprite->GetCurrentFrame() > Ryu_ANI_STAIR_UP_ATTACKING_END) // đã đi vượt qua frame cuối
					{
						isAttacking = false;
						sprite->SelectFrame(Ryu_ANI_STAIR_STANDING_UP);
					}
				}
				/* Xử lí ani đánh khi đang đi lên thang*/

			}
			else
			{
				/* Xử lí ani đánh khi đang đi xuống thang*/
				if (index < Ryu_ANI_STAIR_DOWN_ATTACKING_BEGIN) // nếu ani chưa đúng
				{
					sprite->SelectFrame(Ryu_ANI_STAIR_DOWN_ATTACKING_BEGIN); // set lại ani bắt đầu
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

					if (sprite->GetCurrentFrame() > Ryu_ANI_STAIR_DOWN_ATTACKING_END) // đã đi vượt qua frame cuối
					{

						isAttacking = false;
						sprite->SelectFrame(Ryu_ANI_STAIR_STANDING_DOWN);
					}
				}
				/* Xử lí ani đánh khi đang đi xuống thang*/

			}



		}
		else
		{
			if (isWalking == true)
			{
				if (isProcessingOnStair == 1) // nếu ở giai đoạn bước chân thì set frame 12
				{
					if (vy < 0) // ddi len
						sprite->SelectFrame(Ryu_ANI_STAIR_GO_UP_BEGIN);
					else
						sprite->SelectFrame(Ryu_ANI_STAIR_GO_DOWN_BEGIN);
				}


				if (isProcessingOnStair == 2) // nếu ở giai đoạn bước chân trụ thì set frame 13
				{
					if (vy < 0) // ddi len
						sprite->SelectFrame(Ryu_ANI_STAIR_GO_UP_END);
					else
						sprite->SelectFrame(Ryu_ANI_STAIR_GO_DOWN_END);
				}

				DoCaoDiDuoc = DoCaoDiDuoc + abs(vy) * 16.0f;

				if (DoCaoDiDuoc >= 8.0f && isProcessingOnStair == 1)
					isProcessingOnStair++;

				if (DoCaoDiDuoc >= 16)
				{
					isProcessingOnStair++;

					/* fix lỗi mỗi lần đi vượt quá 16px */
					if (direction == 1 && directionY == -1) // đi lên bên phải
					{
						x -= (DoCaoDiDuoc - 16.0f);
						y += (DoCaoDiDuoc - 16.0f);
					}
					if (direction == -1 && directionY == -1) // đi lên bên trái
					{
						x += (DoCaoDiDuoc - 16.0f);
						y += (DoCaoDiDuoc - 16.0f);
					}

					if (direction == 1 && directionY == 1) // đi xuống bên phải
					{
						x -= (DoCaoDiDuoc - 16.0f);
						y -= (DoCaoDiDuoc - 16.0f);
					}
					if (direction == -1 && directionY == 1) // đi xuống bên trái
					{
						x += (DoCaoDiDuoc - 16.0f);
						y -= (DoCaoDiDuoc - 16.0f);
					}
					DoCaoDiDuoc = 0;
				}
				//	DebugOut(L"DoCaoDiDuoc = %f . dy = %f . y = %f\n", DoCaoDiDuoc, dy, y);

			}
			else
			{
				if (this->directionY == -1) // ddang di len
					sprite->SelectFrame(Ryu_ANI_STAIR_STANDING_UP);
				else
					sprite->SelectFrame(Ryu_ANI_STAIR_STANDING_DOWN);
			}
		}

		//	DebugOut(L"sprite index = %d \n", sprite->GetCurrentFrame());

	}
	else
	{
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
				if (isAttacking == true)
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
					if (isWalking == true) // đang di chuyển
					{
						if (isJumping == false) // ko nhảy
						{
							if (index < Ryu_ANI_WALKING_BEGIN || index >= Ryu_ANI_WALKING_END)
								sprite->SelectFrame(Ryu_ANI_WALKING_BEGIN);

							//cập nhật frame mới
							sprite->Update(dt); // dt này được cập nhật khi gọi update; 
						}
						else
						{
							sprite->SelectFrame(Ryu_ANI_JUMPING);
						}

					}
					else
						if (isJumping == true) // nếu ko đi mà chỉ nhảy
						{
							sprite->SelectFrame(Ryu_ANI_JUMPING);
						}
						else
						{
							sprite->SelectFrame(Ryu_ANI_IDLE);		// Ryu đứng yên

						}


		}
	}
#pragma endregion

	/* Update về sprite */


	GameObject::Update(dt);
	if (isOnStair == false) // ko trên cầu thang thì mới có trọng lực
	{
		if (isJumping)
		{
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
	}


	if (isOnStair == false)
	{
		if (isAutoGoX == false)
			CollisionWithGround(coObjects); // check Collision and update x, y for Ryu
		else
			x += dx;
	}

	if (isOnStair == true)
		CollisionIsOnStair(coObjects);

	//for (auto& objWeapon : mapWeapon)
	//{
	//	if (objWeapon.second->GetFinish() == false) // vũ khi này chưa kết thúc thì update
	//	{
	//		if (objWeapon.second->GetType() == eType::MORNINGSTAR)
	//		{
	//			objWeapon.second->SetPosition(this->x, this->y);
	//			objWeapon.second->SetSpeed(vx, vy); // set vận tốc để kt va chạm
	//			objWeapon.second->UpdatePositionFitRyu();
	//		}

	//		objWeapon.second->Update(dt, coObjects);
	//	}
	//}



	if (isProcessingOnStair == 3)
	{
		isProcessingOnStair = 0;
		vx = 0;
		vy = 0;
		isWalking = false;
	}


	if (isAutoGoX == true)
	{
		if (abs(x - AutoGoX_Backup_X) >= AutoGoX_Distance)
		{
			x = x - (abs(x - AutoGoX_Backup_X) - AutoGoX_Distance);
			RestoreBackupAutoGoX();
			isAutoGoX = false;

			DebugOut(L"[Ryu] end auto go X\n");
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



	//for (auto& objWeapon : mapWeapon)
	//{
	//	if (objWeapon.second->GetFinish() == false) // vũ khi này chưa kết thúc thì render
	//	{
	//		objWeapon.second->Render(camera);
	//	}
	//}


}

void Ryu::Left()
{
	if (isOnStair == true)
		return;
	direction = -1;
}

void Ryu::Right()
{
	if (isOnStair == true)
		return;
	direction = 1;
}

void Ryu::Go()
{
	if (isOnStair == true)
	{
		return;
	}

	if (isAttacking == true)
		return;

	vx = Ryu_WALKING_SPEED * direction;
	isWalking = 1;

}

void Ryu::Sit()
{
	if (isOnStair == true)
		return;

	vx = 0;
	isWalking = 0;

	if (isSitting == false)
		y = y + PULL_UP_Ryu_AFTER_SITTING;

	isSitting = 1;
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

	if (isOnStair == true)
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

	if (isOnStair)
		return;

	if (isHurting)
		return;

	vx = 0;
	//DebugOut(L"[STOP] Set vx = %f \n", vx);


	isWalking = 0;
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

	isWalking = 0;
	isAttacking = 0;
	isJumping = 0;

	ResetSit();

	//mapWeapon[eType::MORNINGSTAR]->SetFinish(true);

	if (!isOnStair && !isAutoGoX) // ko "đang tự đi" và ko "đang trên thang" thì bật ra
	{
		if (e->nx != 0)
		{
			vx = Ryu_WALKING_SPEED * e->nx;
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
		isWalking = 1;
		//isHurting = 1;
	}

	StartUntouchable(); // không cho các object đụng tiếp


	SubHealth(2); // chạm enemy -2 máu
	//sound->Play(eSound::soundHurting);
}

void Ryu::SetHeartCollect(int h)
{
	HeartCollect = h;
}

int Ryu::GetHeartCollect()
{
	return HeartCollect;
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


void Ryu::CollisionIsOnStair(vector<LPGAMEOBJECT> *coObjects)
{
	if (directionY == 1) // đang đi xuống
	{
		int CountCollisionBottom = 0;
		vector<LPGAMEOBJECT> listobj;
		listobj.clear();
		//for (UINT i = 0; i < (*coObjects).size(); i++)
		//	if ((*coObjects)[i]->GetType() == eType::STAIR_BOTTOM) // nếu là object ở dưới
		//	{
		//		if (this->isCollitionObjectWithObject((*coObjects)[i]))
		//		{
		//			CountCollisionBottom++;
		//			break;
		//		}
		//	}

		if (CountCollisionBottom > 0) // có va chạm với bottom
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
			}
			else
			{
				float min_tx, min_ty, nx = 0, ny;

				FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);
				x += min_tx * dx + nx * 0.4f;
				y += min_ty * dy + ny * 0.4f;
				if (nx != 0 || ny != 0)
				{
					vx = 0;
					vy = 0;
					isOnStair = false; // kết thúc việc đang trên cầu thang
					isWalking = false;
					isProcessingOnStair = 0;
				}
			}

			for (UINT i = 0; i < coEvents.size(); i++)
				delete coEvents[i];

			return;
		}

	}


	if (directionY == -1) // đang đi lên
	{
		vector<LPGAMEOBJECT> listobj;
		//float xCenterStairTop; // vị trí x ở giữa của box top
		int CountCollisionTop = 0;
		listobj.clear();
		//for (UINT i = 0; i < (*coObjects).size(); i++)
		//	if ((*coObjects)[i]->GetType() == eType::STAIR_TOP) // nếu là object ở trên
		//	{
		//		if (this->isCollitionObjectWithObject((*coObjects)[i])) // có va chạm với top stair
		//		{
		//			CountCollisionTop++;
		//			//xCenterStairTop = (*coObjects)[i]->GetX(); //25 là kích thước 1/2 của box top
		//			break;
		//		}
		//	}

		if (CountCollisionTop > 0) // có va chạm với top, và nó đang đi lên
		{
			float backupVy = vy;

			y = y - 50; // kéo Ryu lên cao, để tạo va chạm giả xuống mặt đất, tránh overlaping. tính thời gian tiếp đất
			vy = 9999999999.0f; // vận tốc kéo xuống lớn để chạm đất ngay trong 1 frame
			dy = vy * dt; // cập nhật lại dy

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
			}
			else
			{
				float min_tx, min_ty, nx = 0, ny;

				FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);
				x += min_tx * dx + nx * 0.4f;
				y += min_ty * dy + ny * 0.4f;
				if (nx != 0 || ny != 0)
				{
					vx = 0;
					vy = 0;
					isOnStair = false; // kết thúc việc đang trên cầu thang
					isWalking = false;
					//	x = xCenterStairTop;
					isProcessingOnStair = 0;
				}
			}

			for (UINT i = 0; i < coEvents.size(); i++)
				delete coEvents[i];

			vy = backupVy;
			dy = vy * dt; // cập nhật lại dy

			return; // ko cần xét tiếp
		}

	}

	// nếu không đụng top và bot thì di chuyển bt
	x += dx;
	y += dy;

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

	/* Kiểm tra còn đủ HeartCollect ko? */
	switch (typeWeapon)
	{
	/*case MORNINGSTAR:
	{
		if (isAttacking)
		{
			return;
		}
		break;
	}

	case STOPWATCH:
	{
		if (HeartCollect >= 5)
		{
			//HeartCollect -= 5;
		}
		else
			return; // ko đủ HeartCollect thì ko attack
		break;
	}*/

	default: // các vũ khí còn lại
	{
		if (HeartCollect >= 1)
		{
			//	HeartCollect -= 1;
		}
		else
			return;// ko đủ HeartCollect thì ko attack
		break;
	}
	}

	bool isAllowSubHeartCollect = false;

	//if (mapWeapon[typeWeapon]->GetFinish()) // vũ khí đã kết thúc thì mới đc tấn công tiếp
	//{
	//	if (isUseDoubleShot && typeWeapon != eType::MORNINGSTAR && IsUsingWeapon(eType::WEAPON_DOUBLE_SHOT)) // Double shot, sub weapon , và vũ khí phụ còn hoạt động thì bỏ qua
	//		return;

	//	isAttacking = true; // set trang thái tấn công
	//	sprite->SelectFrame(0);
	//	sprite->ResetTime();

	//	mapWeapon[typeWeapon]->Attack(this->x, this->y, this->direction); // set vị trí weapon theo Ryu
	//	isAllowSubHeartCollect = true;
	//}
	//else // xử lí Double Shot
	//{
	//	if (isUseDoubleShot && typeWeapon != eType::MORNINGSTAR && typeWeapon != eType::STOPWATCH) // đang ở chế độ DoubleShot và k phải là Morning star VÀ STOPWATCH
	//	{
	//		if (GetTickCount() - mapWeapon[typeWeapon]->GetLastTimeAttack() >= 250) // sau 250 ms thì mới được dùng Double Shot
	//		{
	//			bool isMustRecreateDoubleShot = false; // ban đầu k cần tạo lại


	//			if (mapWeapon.find(eType::WEAPON_DOUBLE_SHOT) == mapWeapon.end()) // chưa tạo Double shot
	//			{
	//				isMustRecreateDoubleShot = true; // chưa tạo thì phải tạo lại
	//			}
	//			else
	//			{
	//				if (mapWeapon[eType::WEAPON_DOUBLE_SHOT]->GetFinish() == false) // vũ khí đã tạo vẫn còn đang chạy
	//				{
	//					return; // thoát luôn
	//				}
	//				else
	//				{
	//					if (mapWeapon[eType::WEAPON_DOUBLE_SHOT]->GetType() != typeWeapon) // vũ khí đã tạo khác với vũ khí đang dùng để tấn công
	//					{
	//						isMustRecreateDoubleShot = true; // tạo lại cho đúng
	//					}
	//				}
	//			}

	//			if (isMustRecreateDoubleShot)
	//			{
	//				SAFE_DELETE(mapWeapon[eType::WEAPON_DOUBLE_SHOT]); // DELETE vũ khí hiện tại
	//				eType t = GetTypeWeaponCollect();
	//				switch (t)
	//				{

	//				case DAGGER:
	//				{
	//					mapWeapon[eType::WEAPON_DOUBLE_SHOT] = new Dagger(camera);
	//					break;
	//				}

	//				case HOLYWATER:
	//				{
	//					mapWeapon[eType::WEAPON_DOUBLE_SHOT] = new HolyWater(camera);
	//					break;
	//				}

	//				case STOPWATCH:
	//				{
	//					mapWeapon[eType::WEAPON_DOUBLE_SHOT] = new StopWatch();
	//					break;
	//				}

	//				case THROWINGAXE:
	//				{
	//					mapWeapon[eType::WEAPON_DOUBLE_SHOT] = new ThrowingAxe(camera);
	//					break;
	//				}

	//				case BOOMERANG:
	//				{
	//					mapWeapon[eType::WEAPON_DOUBLE_SHOT] = new Boomerang(camera, this);
	//					break;
	//				}
	//				default:
	//					break;
	//				}
	//			}


	//			isAttacking = true; // set trang thái tấn công
	//			sprite->SelectFrame(0);
	//			sprite->ResetTime();


	//			mapWeapon[eType::WEAPON_DOUBLE_SHOT]->Attack(this->x, this->y, this->direction);
	//			isAllowSubHeartCollect = true;

	//		}

	//	}
	//}

	if (isAllowSubHeartCollect)
	{
		switch (typeWeapon)
		{
		//case MORNINGSTAR:
		//{
		//	// ko trừ
		//	break;
		//}

		//case STOPWATCH:
		//{
		//	HeartCollect -= 5;
		//	break;
		//}

		default: // các vũ khí còn lại
		{
			HeartCollect -= 1;
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
	isWalking_Backup = isWalking;
	isJumping_Backup = isJumping;
	isSitting_Backup = isSitting;
	isAttacking_Backup = isAttacking;
	isOnStair_Backup = isOnStair;
	isProcessingOnStair_Backup = isProcessingOnStair;
	directionStair_Backup = directionStair;
	directionY_Backup = directionY;

	AutoGoX_Distance = Distance;
	AutoGoX_Speed = Speed;
	AutoGoX_DirectionGo = (float)DirectionGo;
	this->directionAfterGo = directionAfterGo;


	direction = DirectionGo;
	vx = Speed * DirectionGo;
	isWalking = 1;
	isJumping = 0;
	isSitting = 0;
	isAttacking = 0;
	isOnStair = 0;
	isProcessingOnStair = 0;
}

bool Ryu::GetIsAutoGoX()
{
	return isAutoGoX;
}

void Ryu::RestoreBackupAutoGoX()
{
	isWalking = isWalking_Backup;
	isJumping = isJumping_Backup;
	isSitting = isSitting_Backup;
	isAttacking = isAttacking_Backup;
	isOnStair = isOnStair_Backup;
	isProcessingOnStair = isProcessingOnStair_Backup;
	directionStair = directionStair_Backup;
	directionY = directionY_Backup;

	direction = directionAfterGo; // set hướng sau khi đi

	isWalking = 0; // tắt trạng thái đang đi
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
	isWalking = 0;
	isOnStair = 0;

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
	//if (this->mapWeapon.find(typeWeapon) != this->mapWeapon.end()) // có tồn tại
	//{
	//	if (this->mapWeapon[typeWeapon]->GetFinish() == false) //chưa kết thúc
	//		return true;
	//}
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
	HeartCollect = Ryu_DEFAULT_HEARTCOLLECT;
	score = Ryu_DEFAULT_SCORE;

	Reset();
}

void Ryu::Reset()
{

	direction = 1;

	isSitting = 0;
	isProcessingOnStair = 0;// ko phải đang xử lí
	isOnStair = 0;
	isJumping = 0;
	isWalking = 0;
	isAttacking = 0;

	isAutoGoX = 0;
	isHurting = 0;

	vx = 0;
	vy = 0;
	DoCaoDiDuoc = 0;
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

	HeartCollect = Ryu_DEFAULT_HEARTCOLLECT;



	Reset();


	x = PositionBackup.x;
	y = PositionBackup.y;

	return true;
}
