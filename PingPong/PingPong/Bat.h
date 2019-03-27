#pragma once
#include <d3dx9.h>
#include "MContent.h"
#include "MGraphic.h"
#include "MKeyboard.h"
#include "MMouse.h"

class Bat
{
	LPDIRECT3DTEXTURE9 img;
public:
	Bat(void);
	D3DXVECTOR2 position;
	float speed;
	RECT rect;
	~Bat(void);
	void InitUp(MContent* content);
	void InitDown(MContent* content);
	void Update(float gameTime, MKeyboard* key);// <-- and -->
	void Update2(float gameTime, MKeyboard* key);// A and D
	void Update(float gameTime, MMouse* mouse);
	void Render(MGraphic* graphic);
};

