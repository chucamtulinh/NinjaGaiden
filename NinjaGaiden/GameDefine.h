#ifndef _DEFINE_H__
#define _DEFINE_H__


#include <fstream> 
#include <string>
#include <stdio.h>
#include <Windows.h>  
#include <iostream>
#include <map>
#include "debug.h" 
#include <algorithm>
#include <d3dx9.h>
#include <stdlib.h>
#include <iomanip>
#include <d3d9.h>
#include <vector>
#include <iostream>



using namespace std;


#define COLOR_BLACK D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f)  
#define COLOR_KEY D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f) 


#define SCREEN_WIDTH 528
#define SCREEN_HEIGHT 480 


#define IS_DEBUG_RENDER_BBOX isDebug_RenderBBox

#define MAX_FRAME_RATE 90

#define COLOR_BACKGROUND_DEFAULT D3DCOLOR_XRGB(0, 0, 0) // Màu đen

#define TIME_LIMIT_WAIT_RESET_GAME 300 // Thời gian chờ vẽ màn màu đen khi reset game

extern D3DCOLOR D3DCOLOR_BACKGROUND; // màu nền game

//Phím game
#define UP_btn DIK_UP
#define DOWN_btn DIK_DOWN
#define LEFT_btn DIK_LEFT
#define RIGHT_btn DIK_RIGHT
#define ATK_btn DIK_A
#define JUMP_btn DIK_S
#define ITEM_btn DIK_D



extern int isDebug_Untouchable;
extern int isDebug_RenderBBox;


// ID của Sprite, object
enum eType
{
	RYU = 01,
	RYU_TRANS = 02,
	RYU_DEATH = 03,

	// object nền
	GROUND = 20,
	TEX_GROUND3101 = 21,
	TEX_GROUND3102 = 22,
	TEX_GROUND3103 = 23,
	TEX_GROUND3104 = 24,
	TEX_GROUND3105 = 25,
	TEX_GROUND3106 = 26,
	TEX_GROUND3107 = 27,
	TEX_GROUND3108 = 28,

	// object
	



	// weapon
	


	// item
	COURIER = 81,
	

	// other
	FONT = 101,
	BOARD = 102,
	BOARDHEALTH = 103,
	MAP1 = 104,
	RENDERBBOX = 105,
	MAP2 = 106,
	BOARD_TRANS = 107,

	// Effect
	

	// Enemy
	

	//BOSS
	
	// Intro
	

};





typedef D3DXVECTOR3 GVector3;
typedef D3DXVECTOR2 GVector2;
#define VECTOR2ZERO GVector2(0.0f, 0.0f)





#define GAMEOVER_SELECT_CONTINUE 0
#define GAMEOVER_SELECT_END 1




#ifndef CHECK_OBJECT_IN_CAMERA // Kiểm tra GameObject có nằm trong camera ko?
#define CHECK_OBJECT_IN_CAMERA(obj) \
checkObjectInCamera(obj->GetX(), obj->GetY(), (float)obj->GetWidth(),  (float)obj->GetHeight())
#endif


#ifndef SAFE_DELETE
#define SAFE_DELETE(ptr) \
if(ptr) \
{\
	delete (ptr); \
	ptr = nullptr; \
} \

#endif

#endif 