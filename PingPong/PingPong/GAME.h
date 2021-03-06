#pragma once
#include <Windows.h>
#include "MGraphic.h"
#include "MContent.h"
#include "MKeyboard.h"
#include "MMouse.h"
#include "Ball.h"
#include "Bat.h"

class GAME
{
	LPDIRECT3DTEXTURE9 img;
private:
		HINSTANCE hInstance;
		HWND hWnd;
		int Width;
		int Height;
		char windowName[256];
		static HRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
		MGraphic* graphic;
		MContent* content;
		MKeyboard* keyboard;
		MMouse* mouse;
		Ball* ball;
		Bat* bat1;
		Bat* bat2;
		bool Check(RECT r1, RECT r2);
		bool AABBCheck(Box b1, Box b2);
		void CheckAABB(Ball* ball, Bat* bat);
public:
	D3DXVECTOR2 position;
	bool InitWindow();
	void InitGame();
	void Update(float gameTime);
	void Render();
	GAME(HINSTANCE hIns, int w, int h, char* name);
	~GAME(void);
};

