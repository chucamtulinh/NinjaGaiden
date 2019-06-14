﻿#ifndef __SCENEGAME_H__
#define __SCENEGAME_H__

#include "Scene.h"
#include "Camera.h"
#include "Sprite.h"
#include "GameMap.h"
#include "Camera.h"
#include "Grid.h"
#include "Ryu.h"
//#include "Font.h"
//#include "Board.h"
#include "TextureManager.h"
#include "GameTime.h"
#include "SceneManager.h"
//#include "Sound.h"

#define GAME_TIME_MAX 300

#define CROSS_LIMITTIME 1000 // thời gian tối đa khi dùng Cross

#pragma region define ClearState3

#define CLEARSTATE3_PROCESS_HEALTH 0 // xử lí làm đầy máu
#define CLEARSTATE3_PROCESS_GETSCORE_TIME 1 // xử lí quy đổi thời gian dư ra điểm
#define CLEARSTATE3_PROCESS_GETSCORE_HEART 2 // xử lí quy đổi thời gian dư ra điểm
#define CLEARSTATE3_PROCESS_DONE 3 // xử lí xong

#define CLEARSTATE3_LIMITTIMEWAIT_PROCESS_HEALTH 200 // thời gian chờ tăng mỗi đơn vị máu
#define CLEARSTATE3_LIMITTIMEWAIT_PROCESS_GETSCORE_TIME 10 // thời gian chờ mỗi lượt update time
#define CLEARSTATE3_LIMITTIMEWAIT_PROCESS_GETSCORE_HEART 50 // thời gian chờ mỗi lượt update tim
#define CLEARSTATE3_LIMITTIMEWAIT_PROCESS_OPENGAMEOVER 2000 // thời gian chờ mở gameover sau khi clearstate xong

#pragma endregion


class SceneGame : public Scene
{
private:
	///*Xử lí liên quan tạo Fishmen*/
	//bool isAllowCreateFishmen;
	//int CountEnemyFishmen;
	//DWORD TimeCreateFishmen; // thời điểm đã tạo fishmen
	//DWORD TimeWaitCreateFishmen; // thời gian cần chờ để tạo fishmen

	/* Xử lí liên quan Clear State 3 */
	bool isAllowProcessClearState3;
	int StatusProcessClearState3;
	DWORD TimeWaited_ClearState3;
	DWORD LimitTimeWait_ClearState3;

	/*Xử lí liên quan tạo Panther*/
	bool isAllowRenewPanther;
	int CountEnemyPanther;

	Ryu * ryu;
	GameMap * TileMap;
	Camera *camera;
	Grid * gridGame;
	/*Board * board;
	Sound * sound;*/

	vector<GameObject*> listObj;
	vector <Item*> listItem;
	vector <GameObject*> listEnemy;

	GameTime * gameTime;
	int StateCurrent;

	/* xử lí chờ vẽ màn đen khi bắt đầu lại game*/
	bool isWaitResetGame;
	DWORD TimeWaitedResetGame;

	/* Xử lí gameover*/
	bool isGameOver;
	//Font Text;

	Sprite * _spriteLagerHeart;
	int GameOverSelect;

	eType mapCurrent;

public:
	SceneGame();
	~SceneGame();


	void KeyState(BYTE *state);
	void OnKeyDown(int KeyCode);
	void OnKeyUp(int KeyCode);
	void LoadResources();

	void InitGame(); // khởi tạo lại như chơi từ đầu
	void ResetResource(); // reset lai resource khi simon mất 1 mạng



	void Update(DWORD dt);
	void Render();


	void LoadMap(eType);



	void CheckCollision();
	void CheckCollisionWeapon(vector<GameObject*> listObj);
	void CheckCollisionRyuWithItem();
	void CheckCollisionWithEnemy();
	void CheckCollisionRyuWithEnemy();
	void CheckCollisionWithBoss();
	Item * GetNewItem(int Id, eType Type, float X, float Y);


	//void ProcessClearState3(DWORD dt);

	void ReplayMusicGame();
};
#endif