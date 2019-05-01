#pragma once
#include <math.h>
#include <vector>
#include <d3dx9.h>
#include <d3d9.h>

#include "Scene.h"
#include "Sprite.h"
#include "Animation.h"
#include "GameMap.h"

class DemoScene : public Scene
{
public:
	DemoScene();

	void Update(float dt);
	void LoadContent();
	void Draw();

protected:
	GameMap * mMap;

	float mTimeCounter;
};

