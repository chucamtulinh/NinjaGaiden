﻿#include "SceneGame.h"

SceneGame::SceneGame()
{
	LoadResources();
}

SceneGame::~SceneGame()
{
	SAFE_DELETE(TileMap);
	//SAFE_DELETE(board);
	SAFE_DELETE(gridGame);
}

void SceneGame::KeyState(BYTE * state) //Xử lý phím ở đoạn này
{
	if (ryu->isAttacking) return;
	if (ryu->GetIsDeath() || isWaitResetGame || isGameOver)
	{
		return;
	}
	if (ryu->isHurting)
		return;
	if (Game::GetInstance()->IsKeyDown(ATK_btn))
	{
		ryu->Attack(eType::SWORDSLASHWEAPON);
	}

	if (Game::GetInstance()->IsKeyDown(JUMP_btn))
	{
		if (Game::GetInstance()->IsKeyDown(RIGHT_btn))
		{
			ryu->Right();
			ryu->Go();
		}
		if (Game::GetInstance()->IsKeyDown(LEFT_btn))
		{
			ryu->Left();
			ryu->Go();
		}
		else ryu->isRunning == false;
		ryu->Jump();
		return;
	}

	if (Game::GetInstance()->IsKeyDown(DOWN_btn) && ryu->isAttacking == false)
	{
		ryu->Sit();

		if (Game::GetInstance()->IsKeyDown(ATK_btn)) {
			ryu->isAttacking = true;
			ryu->Attack(eType::CROUCHSLASHWEAPON);
			ryu->Stop();
		}

		return;
	}

	if (Game::GetInstance()->IsKeyDown(ATK_btn)) ryu->isAttacking = true;

	if (ryu->isAttacking) // đang attack
	{
		float vx, vy;
		ryu->GetSpeed(vx, vy);
		ryu->SetSpeed(0, vy);
		DebugOut(L"RIGHT_btn & attack \n");
		return;
	}

	if (Game::GetInstance()->IsKeyDown(RIGHT_btn))
	{
		if(Game::GetInstance()->IsKeyDown(JUMP_btn))
		{
			ryu->Jump();
			ryu->isJumping = true;
			return;
		}
		else
		{
			ryu->Right();
			ryu->Go();
		}
	}
	else
		if (Game::GetInstance()->IsKeyDown(LEFT_btn))
		{
			if (Game::GetInstance()->IsKeyDown(JUMP_btn))
			{
				ryu->Jump();
				ryu->isJumping = true;
				return;
			}
			else
			{
				ryu->Left();
				ryu->Go();
			}
		}		
		else
		{
			ryu->Stop();
		}


}

void SceneGame::OnKeyDown(int KeyCode) // combo phím hack game :v
{
	if (KeyCode == DIK_R) // render bbox
	{
		if (isDebug_RenderBBox == 0)
			isDebug_RenderBBox = 1;
		else
			isDebug_RenderBBox = 0;
	}

	if (isGameOver)
	{
		switch (KeyCode)
		{
		case UP_btn:
		{
			GameOverSelect = GAMEOVER_SELECT_CONTINUE;
			break;
		}
		case DOWN_btn:
		{
			GameOverSelect = GAMEOVER_SELECT_END;
			break;
		}
		case DIK_RETURN:
		{
			if (GameOverSelect == GAMEOVER_SELECT_CONTINUE)
			{
				InitGame();
				isGameOver = false;
			}
			else
				if (GameOverSelect == GAMEOVER_SELECT_END)
				{
					DestroyWindow(Game::GetInstance()->GetWindowHandle()); // thoát
				}
			break;
		}
		}

		return;
	}

	if (ryu->GetIsDeath() || isWaitResetGame)
	{
		return;
	}

	if (KeyCode == DIK_ESCAPE)
		DestroyWindow(Game::GetInstance()->GetWindowHandle()); // thoát

#pragma region Keydown Debug

	if (KeyCode == DIK_1) // vị trí Ryu
	{
		DebugOut(L"[Ryu] X = %f , Y = %f \n", ryu->GetX(), ryu->GetY());
	}

	if (KeyCode == DIK_2) // lấy tọa độ world của chuột 
	{
		POINT p;
		GetCursorPos(&p);
		ScreenToClient(Game::GetInstance()->GetWindowHandle(), &p);
		DebugOut(L"[MOUSE POSITION] %d %d \n", p.x + (int)camera->GetXCam(), p.y + (int)camera->GetYCam());
	}

	if (KeyCode == DIK_3) // set vi tri Ryu   
	{
		DebugOut(L"[SET POSITION Ryu] x = 1140.0f \n");
		ryu->SetPosition(1140.0f, 0);
		ryu->isAttacking = 0;
		ryu->isRunning = 0;
	}

	if (KeyCode == DIK_4)
	{
		DebugOut(L"[SET POSITION Ryu] x = .... \n");
		ryu->SetPosition(2787.0f, 0);
		//	ryu->isOnStair = false;
	}

	if (KeyCode == DIK_5)
	{
		DebugOut(L"[SET POSITION Ryu] x = .... \n");
		ryu->SetPosition(2060.0f, 0);
	}

	if (KeyCode == DIK_7)
	{
		DebugOut(L"[SET POSITION Ryu] x = .... \n");
		ryu->SetPosition(4000.0f, 500.0f);
	}

	if (KeyCode == DIK_Y) // run boss
	{
		//boss->Start();
	}

	if (KeyCode == DIK_U)
	{
		if (isDebug_Untouchable == 1)
			isDebug_Untouchable = 0;
		else
			isDebug_Untouchable = 1;
	}

	if (KeyCode == DIK_R)
	{
		DebugOut(L"[RESET GRID]");
		gridGame->ReloadGrid();
	}

	if (KeyCode == DIK_F) // create hollywater
	{
		ryu->SetHealth(Ryu_DEFAULT_HEALTH);
		ryu->SetLives(99);
		ryu->SetManaCollect(99);
		gameTime->SetTime(0);
	}


#pragma endregion

	if (ryu->GetIsAutoGoX() == true) // đang chế độ tự đi thì ko xét phím
		return;

	if (camera->GetIsAutoGoX()) // camera đang chế độ tự đi thì ko xét phím
		return;


	if (ryu->isHurting)
		return;


	//if (KeyCode == ATK_btn && Game::GetInstance()->IsKeyDown(UP_btn) && ryu->isProcessingOnStair == 0)
	//{
	//	ryu->Attack(ryu->GetTypeWeaponCollect()); // attack với vũ khí phụ đang nhặt
	//}
	//else

	if (!(Game::GetInstance()->IsKeyDown(UP_btn) && Game::GetInstance()->IsKeyDown(ATK_btn) /*&& ryu->isProcessingOnStair == 0*/ && ryu->isAttacking == true))
		if (KeyCode == ATK_btn) // không phải đang xử lí việc đi trên thang thì đc đánh
		{
			//ryu->Attack(eType::MORNINGSTAR);
		}

	if (KeyCode == JUMP_btn)
	{
		if (Game::GetInstance()->IsKeyDown(LEFT_btn) || Game::GetInstance()->IsKeyDown(RIGHT_btn))
		{
			ryu->Stop();
			//ryu->SetSpeed(Ryu_WALKING_SPEED * ryu->GetDirection(), -Ryu_VJUMP);
			ryu->isJumping = 1;
			ryu->isRunning = 1;
		}
		else
		{
			ryu->Jump();
		}
	}

	if (KeyCode == DOWN_btn)
	{
		ryu->isSitting = true;
	}
}

void SceneGame::OnKeyUp(int KeyCode)
{
	if (ryu->GetFreeze() == true) // Đang bóng băng thì không quan tâm phím
	{
		return;
	}

	if (ryu->GetIsDeath() || isWaitResetGame || isGameOver)
	{
		return;
	}

	if (KeyCode == DOWN_btn)
	{
		ryu->isSitting = false;
	}
}

void SceneGame::LoadResources()
{
	TextureManager * _textureManager = TextureManager::GetInstance();
	//sound = Sound::GetInstance();

	gameTime = new GameTime();

	TileMap = new GameMap();
	gridGame = new Grid();

	camera = new Camera(SCREEN_WIDTH, SCREEN_HEIGHT);
	ryu = new Ryu(camera);
	//board = new Board(BOARD_DEFAULT_POSITION_X, BOARD_DEFAULT_POSITION_Y);

	//_spriteLagerMana = new Sprite(TextureManager::GetInstance()->GetTexture(eType::LARGEMANA), 100);

	InitGame();
}

Item * SceneGame::GetNewItem(int Id, eType Type, float X, float Y)
{
	if (mapCurrent == eType::MAP1)
	{
		if (Type == eType::ITEMCONTAINER)
		{
			/*if (Id == 1 || Id == 4)
				return new LargeHeart(X, Y);

			if (Id == 2 || Id == 3)
				return new UpgradeMorningStar(X, Y);

			if (Id == 5)
				return new ItemDagger(X, Y);*/
		}
	}

	if (mapCurrent == eType::MAP2)
	{
		if (Type == eType::ITEMCONTAINER)
		{
			/*switch (Id)
			{
			case 2:
				return new MoneyBag(X, Y, eType::MONEY_BAG_WHITE);
				break;

			case 40: case 71:
				return new ItemHolyWater(X, Y);
				break;

			case 76:
				return new ItemStopWatch(X, Y);
				break;

			case 109:
				return new InvisibilityPotion(X, Y);
				break;

			case 111:
				return new ItemThrowingAxe(X, Y);
				break;

			case 23: case 98:
				return new Cross(X, Y);
				break;

			default:
			{
				int random = rand() % 15;
				switch (random)
				{
				case 0:
					return new MoneyBag(X, Y, eType::MONEY_BAG_RED);
					break;
				case 1:
					return new MoneyBag(X, Y, eType::MONEY_BAG_WHITE);
					break;
				case 2:
					return new MoneyBag(X, Y, eType::MONEY_BAG_PURPLE);
					break;

				default:
					return new SmallHeart(X, Y);
					break;
				}
				break;
			}
			}*/

		}
	}

	return new Item();
}

void SceneGame::InitGame()
{
	LoadMap(eType::MAP1);
	ryu->Init();

	//ResetResource();


	gameTime->SetTime(0); // đếm lại từ 0

	ReplayMusicGame();


}

void SceneGame::ResetResource()
{
	gridGame->ReloadGrid(); // nạp lại lưới

	listItem.clear();
	//listEffect.clear();
	listEnemy.clear();
	//listWeaponOfEnemy.clear();

	/*isAllowCreateFishmen = false;
	TimeCreateFishmen = 0;
	TimeWaitCreateFishmen = 0;
	CountEnemyFishmen = 0;*/

	camera->SetAllowFollowRyu(true);

	/*if (boss != NULL)
	{
		boss->ResetResource();
	}*/

	/* Set Chờ hiển thị màn đen */
	isWaitResetGame = true;
	TimeWaitedResetGame = 0;

	/*init gameover*/
	isGameOver = false;
	GameOverSelect = GAMEOVER_SELECT_CONTINUE;
}

void SceneGame::Update(DWORD dt)
{
	if (isGameOver)
		return;

#pragma region process debug

	if (isDebug_Untouchable == 1)
		ryu->StartUntouchable();

#pragma endregion

#pragma region xử lí vẽ màn đen trước khi bắt đầu game
	if (isWaitResetGame)
	{
		TimeWaitedResetGame += dt;
		if (TimeWaitedResetGame >= TIME_LIMIT_WAIT_RESET_GAME)
		{
			isWaitResetGame = false;
		}
		else
			return;
	}
#pragma endregion

#pragma region Process_Freeze
	if (ryu->GetFreeze() == true)
	{
		ryu->UpdateFreeze(dt);
		if (ryu->GetFreeze() == true)
			return;
	}
#pragma endregion

//	ProcessClearState3(dt); // xử lí sau khi diệt xong boss

	if (isAllowProcessClearState3 == false)
	{

#pragma region Process_Gametime_OR_Health
		if (gameTime->GetTime() >= GAME_TIME_MAX || ryu->GetHealth() <= 0) // hết thời gian hoặc hết máu
		{
			if (ryu->GetIsDeath())
			{
				ryu->TimeWaitedAfterDeath += dt;
				if (ryu->TimeWaitedAfterDeath >= 1500)
				{
					bool result = ryu->LoseLife(); // đã khôi phục x,y

					if (result == true) // còn mạng để chơi tiếp, giảm mạng reset máu xong
					{
						camera->RestorePosition(); // khôi phục vị trí camera;
						camera->RestoreBoundary(); // khôi phục biên camera

						gameTime->SetTime(0);
						ReplayMusicGame();

						ResetResource(); // reset lại game
					}
					else
					{
						isGameOver = true;
					}
					return;
				}
			}
			else // chưa chết mà hết máu hoặc time thì set trạng thái isDeath
			{
				ryu->SetDeath();
			}

		}
		else
		{
			if (isAllowProcessClearState3 == false) // đang xử lí ClearState thì không đếm time
			{
				gameTime->Update(dt);
			}
		}




		if (GAME_TIME_MAX - gameTime->GetTime() <= 30) // đúng còn lại 30 giây thì bật sound loop
		{
			if (gameTime->CheckIsJustChanged() == true) // Kiểm tra _time vừa thay đổi thì mới chạy nhạc. Nếu chỉ kt <=30s thì cứ mỗi deltatime nó sẽ Play nhạc -> thừa, ko đều
			{
				//sound->Play(eSound::soundStopTimer);
			}
		}
#pragma endregion

	}

	gridGame->GetListObject(listObj, camera); // lấy hết các object "còn Alive" trong vùng camera;

	ryu->Update(dt, &listObj);

	if (camera->AllowFollowRyu())
		camera->SetPosition(ryu->GetX() - SCREEN_WIDTH / 2 + 30, camera->GetYCam()); // cho camera chạy theo Ryu

	camera->Update(dt);

	//chỗ này stage 3-2

//	if (mapCurrent == eType::MAP2)
//	{
#pragma region Process_Region_Create_Enemy_SwordMan

		//	DebugOut(L"now = %d - listenemy = %d\n", CountEnemySwordMan, listEnemy.size());
		DWORD now = GetTickCount();



		if (isWaitProcessCreateSwordMan == false) // nếu không phải chờ xử lí thì vào xử lí
		{
#pragma region Vùng 1 & Vùng 2
			if ((ryu->GetX() >= -16.0f && ryu->GetX() <= 825.0f) || (ryu->GetX() > 2200 && ryu->GetX() < 2775))
			{
				if (now - TimeCreateSwordMan >= ThoiGianChoGiua2SwordManDuocTao)
				{
					if (CountEnemySwordMan < 3)
					{
						if (ryu->GetVx() > 0) // vx>0 đang chạy về bên phải
						{
							// cho ghost chạy từ bên phải qua
							//listEnemy.push_back(new SwordMan(camera->GetXCam() + camera->GetWidth(), 326 - 10, -1));
						}
						else
							if (ryu->GetVx() < 0) // vx>0 đang chạy về bên trái
							{
								// cho ghost chạy từ bên trái qua 
								//listEnemy.push_back(new SwordMan(camera->GetXCam() - 34, 326 - 10, 1));
							}
							else // đứng yên thì cứ random
							{
								int random = rand() % 2;
								if (random == 0) // đi từ bên trái
								{
									//listEnemy.push_back(new SwordMan(camera->GetXCam() - 34, 326 - 10, 1));
								}
								else // đi từ bên phải
								{
									//listEnemy.push_back(new SwordMan(camera->GetXCam() + camera->GetWidth(), 326 - 10, -1));
								}
							}
						CountEnemySwordMan++;
						if (CountEnemySwordMan == 3)
						{
							isWaitProcessCreateSwordMan = true; // phải chờ đến khi cả 3 ghost bị giết
							isAllowCheckTimeWaitProcessCreateSwordMan = false;
						}
						TimeCreateSwordMan = now; // set lại thời điểm đã tạo ghost
					}
				}
			}
#pragma endregion

//#pragma region Vùng 3
//			if ((ryu->GetX() >= SWORDMAN_ZONE3_LEFT && ryu->GetX() <= SWORDMAN_ZONE3_RIGHT))
//			{
//				if (now - TimeCreateSwordMan >= ThoiGianChoGiua2SwordManDuocTao)
//				{
//					if (CountEnemySwordMan < 3)
//					{
//
//						int random = rand() % 2; // tỉ lệ 50%
//						switch (random)
//						{
//						case 0: // ở trên
//						{
//							if (ryu->GetX() <= SWORDMAN_ZONE3_COLUMN1)
//							{
//								listEnemy.push_back(new SwordMan(camera->GetXCam() + camera->GetWidth(), 185, -1));// bên phải chạy qua trái
//								break;
//							}
//							else
//								if (SWORDMAN_ZONE3_COLUMN2 <= ryu->GetX())
//								{
//									listEnemy.push_back(new SwordMan(camera->GetXCam() - 34, 185, 1));// bên trái qua phải
//									break;
//								}
//								else
//								{
//									// không break, để tự chạy tiếp tục vào case 1
//								}
//						}
//						case 1: // ở dưới
//						{
//							if (ryu->GetVx() > 0) // đang chạy về bên phải
//								listEnemy.push_back(new SwordMan(camera->GetXCam() + camera->GetWidth(), 330, -1));// bên phải chạy qua trái
//							else
//								if (ryu->GetVx() < 0) // đang chạy bên trái 
//									listEnemy.push_back(new SwordMan(camera->GetXCam() - 34, 330, 1)); // đi từ trái qua phải
//								else
//								{
//									if (rand() % 2 == 0)
//										listEnemy.push_back(new SwordMan(camera->GetXCam() + camera->GetWidth(), 330, -1));// bên phải chạy qua trái
//									else
//										listEnemy.push_back(new SwordMan(camera->GetXCam() - 34, 330, 1)); // đi từ trái qua phải 
//								}
//							break;
//						}
//
//						}
//
//						CountEnemySwordMan++;
//						if (CountEnemySwordMan == 3)
//						{
//							isWaitProcessCreateSwordMan = true; // phải chờ đến khi cả 3 ghost bị giết
//							isAllowCheckTimeWaitProcessCreateSwordMan = false;
//						}
//						TimeCreateSwordMan = now; // set lại thời điểm đã tạo ghost
//
//
//
//											   /*
//											   if (ryu->GetVx() > 0) // vx>0 đang chạy về bên phải
//											   {
//											   // cho ghost chạy từ bên phải qua
//											   listEnemy.push_back(new SwordMan(camera->GetXCam() + camera->GetWidth(), 326 - 10, -1));// 34 framewidth của ghost
//											   }
//											   else
//											   if (ryu->GetVx() < 0) // vx>0 đang chạy về bên trái
//											   {
//											   // cho ghost chạy từ bên trái qua
//											   listEnemy.push_back(new SwordMan(camera->GetXCam() - 34, 326 - 10, 1));
//											   }
//											   else // đứng yên thì cứ random
//											   {
//											   int random = rand() % 2;
//											   if (random == 0) // đi từ bên trái
//											   {
//											   listEnemy.push_back(new SwordMan(camera->GetXCam() - 34, 326 - 10, 1));
//											   }
//											   else // đi từ bên phải
//											   {
//											   listEnemy.push_back(new SwordMan(camera->GetXCam() + camera->GetWidth(), 326 - 10, -1));
//											   }
//											   }
//											   CountEnemySwordMan++;
//											   if (CountEnemySwordMan == 3)
//											   {
//											   isWaitProcessCreateSwordMan = true; // phải chờ đến khi cả 3 ghost bị giết
//											   isAllowCheckTimeWaitProcessCreateSwordMan = false;
//											   }
//											   TimeCreateSwordMan = now; // set lại thời điểm đã tạo ghost
//											   */
//					}
//				}
//			}
//#pragma endregion
			listEnemy.push_back(new SwordMan(240.0f, 198.0f, 1));
			listEnemy.push_back(new SwordMan(288.0f, 198.0f, 1));
			listEnemy.push_back(new SwordMan(336.0f, 198.0f, 1));
			listEnemy.push_back(new SwordMan(448.0f, 198.0f, 1));
			listEnemy.push_back(new SwordMan(1872.0f, 198.0f, 1));
			listEnemy.push_back(new SwordMan(1952.0f, 198.0f, 1));
		}
		else
		{
			if (isAllowCheckTimeWaitProcessCreateSwordMan)
			{
				if (now - TimeWaitProcessCreateSwordMan >= ThoiGianChoDeXuLiTaoSwordMan) // đã chờ đủ
				{
					isWaitProcessCreateSwordMan = false; // không phải chờ nữa
				}
			}
		}




#pragma endregion
//
//#pragma region Process_Region_Create_Panther
//		if (REGION_CREATE_PANTHER_LEFT < ryu->GetX() && ryu->GetX() < REGION_CREATE_PANTHER_RIGHT)
//		{
//			if (isAllowRenewPanther)
//			{
//				if (CountEnemyPanther == 0) // không còn Panther nào sống thì mới dc tạo lại cả 3
//				{
//					int directionPanther = abs(REGION_CREATE_PANTHER_LEFT - ryu->GetX()) < abs(REGION_CREATE_PANTHER_RIGHT - ryu->GetX()) ? -1 : 1; // hướng mặt của Panther quay về hướng Ryu
//					listEnemy.push_back(new Panther(1398.0f, 225.0f, directionPanther, directionPanther == -1 ? 20.0f : 9.0f, Ryu));
//					listEnemy.push_back(new Panther(1783.0f, 160.0f, directionPanther, directionPanther == -1 ? 278.0f : 180.0f, Ryu));
//					listEnemy.push_back(new Panther(1923.0f, 225.0f, directionPanther, directionPanther == -1 ? 68.0f : 66.0f, Ryu));
//					CountEnemyPanther += 3;
//				}
//				isAllowRenewPanther = false;
//			}
//		}
//		else
//		{
//			isAllowRenewPanther = true;
//		}
//#pragma endregion
//
//#pragma region Create_Bat 
//		if (isAllowCreateBat)
//		{
//			DWORD now = GetTickCount();
//			if (now - TimeCreateBat >= TimeWaitCreateBat) // đủ thời gian chờ
//			{
//				TimeCreateBat = now; // đặt lại thời gian đã tạo bat
//				if (ryu->GetX() < CREATE_BAT_BOUNDARY_DIVISION_DIRECTION_X || (ryu->GetX() > CREATE_BAT_BOUNDARY_DIVISION_DIRECTION_X && ryu->GetY() > CREATE_BAT_BOUNDARY_DIVISION_DIRECTION_Y))
//					listEnemy.push_back(new Bat(camera->GetXCam() + camera->GetWidth() - 10, ryu->GetY() + 40, -1));
//				else
//					listEnemy.push_back(new Bat(camera->GetXCam() - 10, ryu->GetY() + 40, 1));
//
//				TimeWaitCreateBat = 4000 + (rand() % 3000);
//			}
//		}
//#pragma endregion
//
//#pragma region Create Fishmen
//
//
//		if (isAllowCreateFishmen && CountEnemyFishmen < 2)
//		{
//			DWORD now = GetTickCount();
//			if (now - TimeCreateFishmen >= TimeWaitCreateFishmen) // đủ thời gian chờ
//			{
//				TimeCreateFishmen = now; // đặt lại thời gian đã tạo
//
//				float vtx = 0;
//
//				if (FISHMEN_ZONE_1_LEFT < ryu->GetX() && ryu->GetX() <= FISHMEN_ZONE_1_RIGHT)
//				{
//					vtx = (rand() % 2) ? (FISHMEN_POS_3) : (FISHMEN_POS_4);
//				}
//
//				if (FISHMEN_ZONE_2_LEFT < ryu->GetX() && ryu->GetX() <= FISHMEN_ZONE_2_RIGHT)
//				{
//					vtx = (rand() % 2) ? (FISHMEN_POS_1) : ((rand() % 2) ? (FISHMEN_POS_3) : (FISHMEN_POS_4));
//				}
//
//				if (FISHMEN_ZONE_3_LEFT < ryu->GetX() && ryu->GetX() <= FISHMEN_ZONE_3_RIGHT)
//				{
//					vtx = (rand() % 2) ? (FISHMEN_POS_4) : (FISHMEN_POS_5);
//				}
//
//				if (FISHMEN_ZONE_4_LEFT < ryu->GetX() && ryu->GetX() <= FISHMEN_ZONE_4_RIGHT)
//				{
//					vtx = (rand() % 2) ? (FISHMEN_POS_3) : (FISHMEN_POS_5);
//				}
//
//				if (FISHMEN_ZONE_5_LEFT < ryu->GetX() && ryu->GetX() <= FISHMEN_ZONE_5_RIGHT)
//				{
//					vtx = (rand() % 2) ? (FISHMEN_POS_4) : (FISHMEN_POS_6);
//				}
//
//				if (FISHMEN_ZONE_6_LEFT < ryu->GetX() && ryu->GetX() <= FISHMEN_ZONE_6_RIGHT)
//				{
//					vtx = (rand() % 2) ? (FISHMEN_POS_5) : ((rand() % 2) ? (FISHMEN_POS_7) : (FISHMEN_POS_8));
//				}
//
//				if (FISHMEN_ZONE_7_LEFT < ryu->GetX() && ryu->GetX() <= FISHMEN_ZONE_7_RIGHT)
//				{
//					vtx = (rand() % 2) ? (FISHMEN_POS_6) : (FISHMEN_POS_8);
//				}
//				if (FISHMEN_ZONE_8_LEFT < ryu->GetX() && ryu->GetX() <= FISHMEN_ZONE_8_RIGHT)
//				{
//					vtx = (rand() % 2) ? (FISHMEN_POS_6) : (FISHMEN_POS_7);
//				}
//				int directionFishmen = vtx < ryu->GetX() ? 1 : -1;
//
//
//				float vty = FISHMEN_POS_Y;
//
//				listEnemy.push_back(new Fishmen(vtx, vty, directionFishmen, Ryu, &listWeaponOfEnemy, camera));
//				CountEnemyFishmen++;
//
//				STEAM_ADD_EFFECT(listEffect, vtx, vty);
//
//				sound->Play(eSound::soundSplashwater);
//				TimeWaitCreateFishmen = 2000 + (rand() % 2000);
//			}
//		}
//
//#pragma endregion
//	}



#pragma region Process_Update_Object

	for (UINT i = 0; i < listObj.size(); i++)
		listObj[i]->Update(dt, &listObj);  // đã kiểm tra "Alive" lúc lấy từ lưới ra

	for (UINT i = 0; i < listItem.size(); i++)
		if (listItem[i]->GetFinish() == false)
			listItem[i]->Update(dt, &listObj); // trong các hàm update chỉ kiểm tra va chạm với đất

	/*for (UINT i = 0; i < listEffect.size(); i++)
		if (listEffect[i]->GetFinish() == false)
			listEffect[i]->Update(dt);*/
	/*for (UINT i = 0; i < listWeaponOfEnemy.size(); i++)
	{
		if (listWeaponOfEnemy[i]->GetFinish() == false)
		{
			listWeaponOfEnemy[i]->Update(dt, &listObj);
		}
	}*/

#pragma endregion


	if (!ryu->GetIsDeath())
	{
		CheckCollision();
	}

}

void SceneGame::Render()
{
	if (isWaitResetGame) // màn đen trước khi bắt đầu game
		return; // thoát và ko vẽ gì

	if (!isGameOver)
	{
		TileMap->DrawMap(camera);

		for (UINT i = 0; i < listObj.size(); i++)
			listObj[i]->Render(camera);

		for (UINT i = 0; i < listItem.size(); i++)
			if (listItem[i]->GetFinish() == false)
				listItem[i]->Render(camera);



		for (UINT i = 0; i < listEnemy.size(); i++)
			listEnemy[i]->Render(camera);


		ryu->Render(camera);


		/*for (UINT i = 0; i < listEffect.size(); i++)
			if (listEffect[i]->GetFinish() == false)
				listEffect[i]->Render(camera);*/

		/*if (boss != NULL)
			boss->Render(camera);*/
	}
	else //l
	{
		/*Text.Draw(200, 200, "GAME OVER");
		Text.Draw(215, 250, "CONTINUE");
		Text.Draw(215, 280, "END");
		switch (GameOverSelect)
		{
		case GAMEOVER_SELECT_CONTINUE:
		{
			_spriteLagerMana->Draw(175, 245);
			break;
		}
		case GAMEOVER_SELECT_END:
		{
			_spriteLagerMana->Draw(175, 275);
			break;
		}
		}*/
	}

	//board->Render(Ryu, StateCurrent, GAME_TIME_MAX - gameTime->GetTime(), boss);
}

void SceneGame::LoadMap(eType x)
{
	mapCurrent = x;

	switch (x)
	{
	case eType::MAP1:
		gridGame->SetFile("Resources/Maps/file_gameobject_map1.txt");
		TileMap->LoadMap(eType::MAP1);

		camera->SetAllowFollowRyu(true);

		camera->SetBoundary(0.0f, (float)(TileMap->GetMapWidth() - camera->GetWidth())); // set biên camera dựa vào kích thước map
		camera->SetBoundaryBackup(camera->GetBoundaryLeft(), camera->GetBoundaryRight()); // backup lại biên

		camera->SetPosition(0, 0);

		camera->SetAllowFollowRyu(true);

		ryu->SetPosition(Ryu_POSITION_DEFAULT);
		ryu->SetPositionBackup(Ryu_POSITION_DEFAULT);

		StateCurrent = 1;
		break;

	case eType::MAP2:

		gridGame->SetFile("Resources/Maps/file_gameobject_map2.txt");
		TileMap->LoadMap(eType::MAP2);

		camera->SetAllowFollowRyu(true);

		camera->SetPosition(0, 0);

		ryu->SetPosition(Ryu_POSITION_DEFAULT);
		ryu->SetPositionBackup(Ryu_POSITION_DEFAULT);
		break;
	}

	ResetResource();
}

void SceneGame::CheckCollision()
{
	CheckCollisionWeapon(listObj); // kt va chạm vũ khí với các object nền

	CheckCollisionRyuWithItem();
	CheckCollisionWithEnemy(); // kt vũ khí với enemy và Ryu với enemy

	CheckCollisionWithBoss(); // kt vũ khí với enemy và Ryu với boss

}

void SceneGame::CheckCollisionWeapon(vector<GameObject*> listObj)
{
	for (auto& objWeapon : ryu->mapWeapon)
	{
		if (objWeapon.second->GetFinish() == false) // Vũ khí đang hoạt động
		{
			for (UINT i = 0; i < listObj.size(); i++)
				if (objWeapon.second->GetLastTimeAttack() > listObj[i]->GetLastTimeAttacked()) // Nếu chưa xét va chạm của lượt attack này ở các frame trước
				{
					if (objWeapon.second->isCollision(listObj[i]) == true) // nếu có va chạm
					{
						bool RunEffectHit = false;
						GameObject *gameObj = listObj[i];
						switch (gameObj->GetType())
						{

						case eType::ITEMCONTAINER:
						{
							gameObj->SubHealth(1);
							listItem.push_back(GetNewItem(gameObj->GetId(), gameObj->GetType(), gameObj->GetX() + 5, gameObj->GetY()));// hiệu ứng hit
							RunEffectHit = true;
							break;
						}

						case eType::PANTHER:
						{
							gameObj->SubHealth(1);
							ryu->SetScore(ryu->GetScore() + 200);
							RunEffectHit = true;
							CountEnemyPanther--; // giảm số lượng Panther đang hoạt động
							break;
						}

						case eType::SWORDMAN:
						{
							gameObj->SubHealth(1);
							ryu->SetScore(ryu->GetScore() + 200);
							RunEffectHit = true;
							CountEnemySwordMan--; 
							break;
						}

						//case eType::BAT:
						//{
						//	gameObj->SubHealth(1);
						//	ryu->SetScore(ryu->GetScore() + 200);
						//	if (rand() % 2 == 1) // tỉ lệ 50%
						//	{
						//		listItem.push_back(GetNewItem(gameObj->GetId(), gameObj->GetType(), gameObj->GetX() + 5, gameObj->GetY()));

						//	}

						//	RunEffectHit = true;
						//	CountEnemySwordMan--; // giảm số lượng SwordMan đang hoạt động
						//	if (CountEnemySwordMan == 0)
						//	{
						//		TimeWaitProcessCreateSwordMan = GetTickCount(); // set thời điểm hiện tại
						//		isWaitProcessCreateSwordMan = true;
						//		isAllowCheckTimeWaitProcessCreateSwordMan = true;
						//	}
						//	break;
						//}						

						if (RunEffectHit)
						{
							//listEffect.push_back(new Hit(listObj[i]->GetX() + 10, listObj[i]->GetY() + 14)); // hiệu ứng hit
							//listEffect.push_back(new Fire(gameObj->GetX() - 5, gameObj->GetY() + 8)); // hiệu ứng lửa

							////sound->Play(eSound::soundHit);

							//if (objWeapon.second->GetType() == eType::DAGGER)
							//{
							//	objWeapon.second->SetFinish(true);
							//}

						}

						gameObj->SetLastTimeAttacked(objWeapon.second->GetLastTimeAttack()); // bị đánh trúng->update thời gian bị đánh lần cuối
						}
					}
				}
		}
	}
}

void SceneGame::CheckCollisionRyuWithItem()
{
	//for (UINT i = 0; i < listItem.size(); i++)
	//	if (listItem[i]->GetFinish() == false && listItem[i]->isWaitingDisplay() == false) // chưa kết thúc và "không phải" đang chờ để hiển thị
	//	{
	//		if (ryu->isCollisionWithItem(listItem[i]) == true) // có va chạm
	//		{
	//			switch (listItem[i]->GetType())
	//			{				

	//			default:
	//				DebugOut(L"[CheckCollisionRyuWithItem] Khong nhan dang duoc loai Item!\n");
	//				break;
	//			}
	//		}
	//	}
}

void SceneGame::CheckCollisionWithEnemy()
{
	CheckCollisionWeapon(listEnemy); // enemy bt
	CheckCollisionRyuWithEnemy();
}

void SceneGame::CheckCollisionRyuWithEnemy()
{
	if (GetTickCount() - ryu->untouchable_start > Ryu_UNTOUCHABLE_TIME)
	{
		ryu->untouchable_start = 0;
		ryu->untouchable = false;
	}

	if (ryu->untouchable == false) // đã tắt chế độ ko cho chạm
	{
		for (UINT i = 0; i < listEnemy.size(); i++)
		{
			GameObject * gameobj = dynamic_cast<GameObject *> (listEnemy[i]);
			if (gameobj->GetHealth() > 0) // còn sống
			{
				LPCOLLISIONEVENT e = ryu->SweptAABBEx(gameobj);
				bool isCollision = false;
				if (e->t > 0 && e->t <= 1) // có va chạm
				{
					ryu->SetHurt(e);
					isCollision = true;
				}
				if (isCollision == false && ryu->checkAABB(gameobj) == true)
				{
					LPCOLLISIONEVENT e = new CollisionEvent(1.0f, (float)-ryu->GetDirection(), 0.0f, NULL);
					ryu->SetHurt(e);
					isCollision = true;
				}

				if (isCollision)
				{
					//if (gameobj->GetType() == eType::BAT)
					//{
					//	listEffect.push_back(new Fire(gameobj->GetX() - 5, gameobj->GetY() + 8)); // hiệu ứng lửa
					//	gameobj->SetHealth(0);
					//}
					return; // giảm chi phí duyệt, vì nếu có va chạm thì cũng đang untouchable
				}
			}
		}
	}

	if (ryu->untouchable == false)
	{
//#pragma region Collision With Weapon of Enemy
//		for (UINT i = 0; i < listWeaponOfEnemy.size(); i++)
//		{
//			if (listWeaponOfEnemy[i]->GetFinish() == false)
//			{
//				LPCOLLISIONEVENT e = ryu->SweptAABBEx(listWeaponOfEnemy[i]);
//				if (e->t > 0 && e->t <= 1) // có va chạm
//				{
//					ryu->SetHurt(e);
//					return; // giảm chi phí duyệt, vì nếu có va chạm thì cũng đang untouchable
//				}
//
//				if (ryu->checkAABB(listWeaponOfEnemy[i]) == true)
//				{
//					LPCOLLISIONEVENT e = new CollisionEvent(1.0f, (float)-ryu->GetDirection(), 0.0f, NULL);
//					ryu->SetHurt(e);
//					return;
//				}
//			}
//		}
//#pragma endregion
	}

}

void SceneGame::CheckCollisionWithBoss()
{
	//if (boss == NULL)
	//	return;

	//if (boss->GetHealth() <= 0)
	//	return;

	//vector<GameObject*> listObj{ boss };
	//CheckCollisionWeapon(listObj); // enemy bt

	//if (GetTickCount() - ryu->untouchable_start > Ryu_UNTOUCHABLE_TIME)
	//{
	//	ryu->untouchable_start = 0;
	//	ryu->untouchable = false;
	//}

	//if (ryu->untouchable == false) // đã tắt chế độ ko cho chạm
	//{
	//	if (boss->GetHealth() > 0) // còn sống
	//	{
	//		LPCOLLISIONEVENT e = ryu->SweptAABBEx(boss);
	//		if (e->t > 0 && e->t <= 1) // có va chạm
	//		{
	//			ryu->SetHurt(e);
	//			return; // giảm chi phí duyệt, vì nếu có va chạm thì cũng đang untouchable
	//		}
	//		if (ryu->checkAABB(boss) == true)
	//		{
	//			LPCOLLISIONEVENT e = new CollisionEvent(1.0f, (float)-ryu->GetDirection(), 0.0f, NULL);
	//			ryu->SetHurt(e);
	//			return;
	//		}
	//	}

	//}
}

//Item * SceneGame::GetNewItem(int Id, eType Type, float X, float Y)
//{
//	if (mapCurrent == eType::MAP1)
//	{
//		if (Type == eType::TORCH)
//		{
//			if (Id == 1 || Id == 4)
//				return new LargeMana(X, Y);
//
//			if (Id == 2 || Id == 3)
//				return new UpgradeMorningStar(X, Y);
//
//			if (Id == 5)
//				return new ItemDagger(X, Y);
//		}
//
//		if (Type == eType::OBJECT_HIDDEN)
//		{
//			if (Id == 8)
//				return new Bonus(1240, 305);
//		}
//	}
//
//	if (mapCurrent == eType::MAP2)
//	{
//		if (Type == eType::CANDLE)
//		{
//			switch (Id)
//			{
//			case 2:
//				return new MoneyBag(X, Y, eType::MONEY_BAG_WHITE);
//				break;
//
//			case 40: case 71:
//				return new ItemHolyWater(X, Y);
//				break;
//
//			case 76:
//				return new ItemStopWatch(X, Y);
//				break;
//
//			case 109:
//				return new InvisibilityPotion(X, Y);
//				break;
//
//			case 111:
//				return new ItemThrowingAxe(X, Y);
//				break;
//
//			case 23: case 98:
//				return new Cross(X, Y);
//				break;
//
//			default:
//			{
//				int random = rand() % 15;
//				switch (random)
//				{
//				case 0:
//					return new MoneyBag(X, Y, eType::MONEY_BAG_RED);
//					break;
//				case 1:
//					return new MoneyBag(X, Y, eType::MONEY_BAG_WHITE);
//					break;
//				case 2:
//					return new MoneyBag(X, Y, eType::MONEY_BAG_PURPLE);
//					break;
//
//				default:
//					return new SmallMana(X, Y);
//					break;
//				}
//				break;
//			}
//			}
//
//		}
//
//
//		if (Type == eType::SWORDMAN || Type == eType::PANTHER || Type == eType::BAT || Type == eType::FISHMEN)
//		{
//			int random = rand() % 15;
//
//			if (random == 4)
//			{
//				MorningStar * morningstar = dynamic_cast<MorningStar*>(ryu->mapWeapon[eType::MORNINGSTAR]);
//				while (morningstar->GetLevel() == 2 && random == 4)
//				{
//					random = rand() % 15;
//				}
//			}
//
//
//			switch (random)
//			{
//			case 0:
//				return new LargeMana(X, Y);
//				break;
//			case 1:
//				return new SmallMana(X, Y);
//				break;
//			case 2:
//				return new ItemDagger(X, Y);
//				break;
//			case 3:
//				return new Bonus(X, Y);
//				break;
//			case 4:
//				return new UpgradeMorningStar(X, Y);
//				break;
//			case 5:
//				return new ItemHolyWater(X, Y);
//				break;
//			case 6:
//				return new ItemStopWatch(X, Y);
//				break;
//			case 7:
//				return new ItemThrowingAxe(X, Y);
//				break;
//			case 8:
//				return new InvisibilityPotion(X, Y);
//				break;
//			case 9:
//				return new ItemBoomerang(X, Y);
//				break;
//			default: // còn lại là SmallMana
//				return new SmallMana(X, Y);
//				break;
//			}
//		}
//
//		if (Type == eType::BRICK)
//		{
//			switch (Id)
//			{
//			case 40:
//				return new PotRoast(X, Y);
//				break;
//			case 72:
//				return new Bonus(X, Y);
//				break;
//
//			case 104: // Double shot
//				return new ItemDoubleShot(X, Y);
//				break;
//
//
//			default:
//				return new SmallMana(X, Y);
//				break;
//			}
//
//		}
//
//
//		if (Type == eType::OBJECT_HIDDEN)
//		{
//			if (Id == 65)
//				return new Bonus(3763.0f, 587.0f);
//
//		}
//
//	}
//
//	return new LargeMana(X, Y);
//}

//void SceneGame::ProcessClearState3(DWORD dt)
//{
//	if (isAllowProcessClearState3)
//	{
//		switch (StatusProcessClearState3)
//		{
//		case CLEARSTATE3_PROCESS_HEALTH:
//		{
//			TimeWaited_ClearState3 += dt;
//			if (TimeWaited_ClearState3 >= CLEARSTATE3_LIMITTIMEWAIT_PROCESS_HEALTH)
//			{
//				TimeWaited_ClearState3 = 0;
//
//				if (ryu->GetHealth() < Ryu_DEFAULT_HEALTH)
//				{
//					ryu->SetHealth(ryu->GetHealth() + 1);
//				}
//				else
//				{
//					StatusProcessClearState3 = CLEARSTATE3_PROCESS_GETSCORE_TIME;
//				}
//			}
//			break;
//		}
//
//		case CLEARSTATE3_PROCESS_DONE:
//		{
//			TimeWaited_ClearState3 += dt;
//			if (TimeWaited_ClearState3 >= CLEARSTATE3_LIMITTIMEWAIT_PROCESS_OPENGAMEOVER)
//			{
//				isAllowProcessClearState3 = false; // tắt clear state
//				isGameOver = true; // bật bảng hiện gameover
//			}
//			break;
//		}
//
//		default:
//			break;
//		}
//	}
//}

void SceneGame::ReplayMusicGame()
{
	//sound->StopAll();// tắt hết nhạc
	//sound->Play(eSound::musicState1, true); // mở lại nhạc nền
}
