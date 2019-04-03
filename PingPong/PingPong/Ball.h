#pragma once
#include <d3dx9.h>
#include "MContent.h"
#include "MGraphic.h"

struct Box {
	float x, y, w, h, vx, vy;
};

class Ball
{
private:
	LPDIRECT3DTEXTURE9 img;
public:
	D3DXVECTOR2 position;
	float speed;
	int dx, dy;
	RECT rect;
	Box bball;
	Ball(void);
	~Ball(void);
	void Init(MContent* content);
	void Update(float gameTime);
	void Render(MGraphic* graphic);
};