#include "GameMap.h"



GameMap::GameMap()
{

}


GameMap::~GameMap()
{
	SAFE_DELETE(_sprite);
}

void GameMap::LoadMap(eType type)
{
	switch (type)
	{
	case eType::MAP1:
		ReadMapTXT("Resources/Maps/readfile_map_1.txt");
		break;
	case eType::MAP2:
		ReadMapTXT("Resources/Maps/readfile_map_2.txt");
		break;
	default:
		//DebugOut(L"[MAP] Load map that bai!");
		return;
		break;
	}

	_texture = TextureManager::GetInstance()->GetTexture(type);
	_sprite = new Sprite(_texture, 100);

}

void GameMap::ReadMapTXT(char * filename)
{
	ifstream inp(filename, ios::in);
	inp >> RowMap >> ColumnMap >> ColumnTile >> RowTile >> TotalTiles >> HeightBoard;
	for (int i = 0; i < RowMap; i++)
		for (int j = 0; j < ColumnMap; j++)
			inp >> TileMap[i][j];
	inp.close();
}

void GameMap::DrawMap(Camera *camera)
{
	int row = (int)(camera->GetYCam()) / _texture->GetFrameHeight();
	int column = (int)(camera->GetXCam()) / _texture->GetFrameHeight();

	float x = -(float)((int)(camera->GetXCam()) % _texture->GetFrameHeight());
	float y = -(float)((int)(camera->GetYCam()) % _texture->GetFrameHeight());

	for (int i = 0; i < SCREEN_HEIGHT / _texture->GetFrameHeight() + 1; i++)
		for (int j = 0; j < SCREEN_WIDTH / _texture->GetFrameWidth() + 1; j++)
		{
			if (!(row + i < 0 || row + i >= RowMap || j + column < 0 || j + column > ColumnMap))
				_sprite->DrawFrame(TileMap[row + i][column + j], x + _texture->GetFrameWidth()*j, y + _texture->GetFrameHeight()*i + HeightBoard);
		}
}

int GameMap::GetMapWidth()
{
	return ColumnMap * _texture->GetFrameWidth();
}

int GameMap::GetMapHeight()
{
	return RowMap * _texture->GetFrameHeight();
}
