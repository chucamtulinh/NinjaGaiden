#ifndef __GAMEMAP_H__
#define __GAMEMAP_H__

#include "TextureManager.h"
#include "Sprite.h"
#include "GameDefine.h"
#include "Camera.h"

class GameMap
{
private:
	Texture * _texture;
	Sprite *_sprite;

	int ColumnTile, RowTile, TotalTiles;

	int ColumnMap, RowMap;

	int HeightBoard; // chiều cao board

	int TileMap[500][500];

public:
	GameMap();
	~GameMap();
	void LoadMap(eType type);
	void ReadMapTXT(char * filename);
	void DrawMap(Camera * camera);

	int GetMapWidth();
	int GetMapHeight();
};


#endif