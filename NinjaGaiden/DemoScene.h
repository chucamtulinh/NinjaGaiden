#pragma once
#include <math.h>
#include <vector>
#include <d3dx9.h>
#include <d3d9.h>

#include "Scene.h"
#include "Sprite.h"
#include "Animation.h"
#include "GameMap.h"
#include "Camera.h"
#include "Player.h"

class DemoScene : public Scene
{
public:
	DemoScene();

	void Update(float dt);
	void LoadContent();
	void Draw();

	void OnKeyDown(int keyCode);
	void OnKeyUp(int keyCode);
	void OnMouseDown(float x, float y);

protected:
	GameMap * mMap;
	Camera * mCamera;
	Player * mPlayer;

	float mTimeCounter;

	std::map<int, bool> keys;
};

