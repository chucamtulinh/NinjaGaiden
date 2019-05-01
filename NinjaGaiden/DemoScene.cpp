#include "DemoScene.h"

DemoScene::DemoScene()
{
	LoadContent();
}

void DemoScene::LoadContent()
{
	//set mau backcolor cho scene o day la mau xanh
	mBackColor = 0x54acd2;

	mMap = new GameMap("Resources/Maps/NinjaGaiden1.tmx");
}

void DemoScene::Update(float dt)
{
	
}

void DemoScene::Draw()
{
	mMap->Draw();
}