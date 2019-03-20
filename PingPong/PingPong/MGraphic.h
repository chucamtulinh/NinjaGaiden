#pragma once
#include <d3d9.h>
#include <d3dx9.h>

class MGraphic
{
private:
	LPDIRECT3D9 d3d;
	LPDIRECT3DDEVICE9 d3ddev;
	LPD3DXSPRITE d3dxSprite;
	HWND hWnd;
	int Width;
	int Height;
public:
	bool InitD3d();
	MGraphic(HWND, int, int);
	~MGraphic(void);
	void Begin();
	void End();
	void DrawTexture(LPDIRECT3DTEXTURE9 texture, D3DXVECTOR2 position, D3DCOLOR color);
	void DrawTexture(LPDIRECT3DTEXTURE9 texture, RECT source, D3DXVECTOR2 position, D3DCOLOR color);
	void DrawSurface();
	LPDIRECT3DDEVICE9 GetDevice();
};

