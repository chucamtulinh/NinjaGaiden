#ifndef __GAME__
#define __GAME__
#include <d3dx9.h>
#include <d3d9.h>
#include <Windows.h>
#include <dinput.h>

#include "GameTime.h"

#define KEYBOARD_BUFFERD_SIZE 1024

class Game
{
public:
	Game(int fps = 60);
	~Game();

	static Game * GetInstance();

	static void SweptAABB(
		float ml,			// move left 
		float mt,			// move top
		float mr,			// move right 
		float mb,			// move bottom
		float dx,			// 
		float dy,			// 
		float sl,			// static left
		float st,
		float sr,
		float sb,
		float &t,
		float &nx,
		float &ny);
	bool checkAABB(float b1left, float b1top, float b1right, float b1bottom, float b2left, float b2top, float b2right, float b2bottom);

	LPDIRECT3DDEVICE9 GetDirect3DDevice() { return this->d3ddv; }
	LPD3DXSPRITE GetSpriteHandler() { return this->spriteHandler; }

	void Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom, int alpha = 255);
	void Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, RECT r, int alpha = 255);

protected:

	PDIRECT3DSURFACE9       mBackground,
							mBackBuffer;

	int                     mWidth,
							mHeight;
	static int              mIsDone;
	static					Game * __instance;
	float                   mFPS;
	LPDIRECT3DDEVICE9		d3ddv = NULL;
	LPD3DXSPRITE			spriteHandler = NULL;

	//khoi tao vong lap cho game
	void InitLoop();

	//ham dung de ve sau khi update
	void Render();

	//ham update cua game
	void Update(float dt);
};

#endif