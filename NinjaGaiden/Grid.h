#ifndef __GRID_H__
#define	__GRID_H__

#include "Game.h" 
#include "Sprite.h"
#include "Camera.h"
#include "GameObject.h"
#include "Ground.h"

using namespace std;

#define GRID_CELL_WIDTH (SCREEN_WIDTH/4.0f)
#define GRID_CELL_HEIGHT (SCREEN_HEIGHT/4.0f)

#define GRID_CELL_MAX_ROW 20 
#define GRID_CELL_MAX_COLUMN 100 


class Grid
{
private:
	vector<GameObject*> cells[GRID_CELL_MAX_ROW][GRID_CELL_MAX_COLUMN];
	char * filepath;

public:
	Grid();
	~Grid();

	void SetFile(char * str); 
	void ReloadGrid();


	GameObject * GetNewObject(int type, float x, float y, int w, int h, int Model);
	void Insert(int id, int type, int direction, float x, float y, int w, int h, int Model); 
	void GetListObject(vector<GameObject*>& ListObj, Camera * camera);

};

#endif

