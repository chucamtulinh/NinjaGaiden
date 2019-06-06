#include "Game.h"
#include "GameGlobal.h"
#include "SceneManager.h"
#include "DemoScene.h"

Game * Game::__instance = NULL;

Game::Game(int fps)
{
	mFPS = fps;
	SceneManager::GetInstance()->ReplaceScene(new DemoScene());
	InitLoop();
}

Game::~Game()
{
}

void Game::Update(float dt) {
	SceneManager::GetInstance()->GetCurrentScene()->Update(dt);
	Render();
}

void Game::Render() {
	auto device = GameGlobal::GetCurrentDevice();
	auto scene = SceneManager::GetInstance()->GetCurrentScene();
	device->Clear(0, NULL, D3DCLEAR_TARGET, scene->GetBackcolor(), 0.0f, 0);

	if (device->BeginScene()) {
		//bat dau ve
		GameGlobal::GetCurrentSpriteHandler()->Begin(D3DXSPRITE_ALPHABLEND);

		//draw here
		scene->Draw();

		//ket thuc ve
		GameGlobal::GetCurrentSpriteHandler()->End();


		device->EndScene();
	}

	device->Present(0, 0, 0, 0);
}

void Game::InitLoop() {
	MSG msg;

	float tickPerFrame = 1.0f / mFPS, delta = 0;

	while (GameGlobal::isGameRunning) {
		GameTime::GetInstance()->StartCounter();

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		delta += GameTime::GetInstance()->GetCouter();

		if (delta >= tickPerFrame) {
			Update((delta));
			delta = 0;
		}
		else {
			Sleep(tickPerFrame - delta);
			delta = tickPerFrame;
		}
	}
}

void Game::SweptAABB(
	float ml, float mt, float mr, float mb,
	float dx, float dy,
	float sl, float st, float sr, float sb,
	float &t, float &nx, float &ny)
{

	float dx_entry, dx_exit, tx_entry, tx_exit;
	float dy_entry, dy_exit, ty_entry, ty_exit;

	float t_entry;
	float t_exit;

	t = -1.0f;			// no collision
	nx = ny = 0.0f;

	//
	// Broad-phase test 
	//

	float bl = dx > 0.0f ? ml : ml + dx;
	float bt = dy > 0.0f ? mt : mt + dy;
	float br = dx > 0.0f ? mr + dx : mr;
	float bb = dy > 0.0f ? mb + dy : mb;

	if (br < sl || bl > sr || bb < st || bt > sb) return;

	if (dx == 0.0f && dy == 0.0f) return;		// moving object is not moving > obvious no collision

	if (dx > 0.0f)
	{
		dx_entry = sl - mr;
		dx_exit = sr - ml;
	}
	else
		if (dx < 0.0f)
		{
			dx_entry = sr - ml;
			dx_exit = sl - mr;
		}


	if (dy > 0.0f)
	{
		dy_entry = st - mb;
		dy_exit = sb - mt;
	}
	else if (dy < 0.0f)
	{
		dy_entry = sb - mt;
		dy_exit = st - mb;
	}

	if (dx == 0.0f)
	{
		tx_entry = -99999999999.0f;
		tx_exit = 99999999999.0f;
	}
	else
	{
		tx_entry = dx_entry / dx;
		tx_exit = dx_exit / dx;
	}

	if (dy == 0.0f)
	{
		ty_entry = -99999999999.0f;
		ty_exit = 99999999999.0f;
	}
	else
	{
		ty_entry = dy_entry / dy;
		ty_exit = dy_exit / dy;
	}


	if ((tx_entry < 0.0f && ty_entry < 0.0f) || tx_entry > 1.0f || ty_entry > 1.0f) return;

	t_entry = max(tx_entry, ty_entry);
	t_exit = min(tx_exit, ty_exit);

	if (t_entry > t_exit) return;

	t = t_entry;

	if (tx_entry > ty_entry)
	{
		ny = 0.0f;
		dx > 0.0f ? nx = -1.0f : nx = 1.0f;
	}
	else
	{
		nx = 0.0f;
		dy > 0.0f ? ny = -1.0f : ny = 1.0f;
	}

}

bool Game::checkAABB(float b1left, float b1top, float b1right, float b1bottom, float b2left, float b2top, float b2right, float b2bottom)
{
	return !(b1right < b2left || b1left > b2right || b1top > b2bottom || b1bottom < b2top);
}

Game *Game::GetInstance()
{
	if (__instance == NULL) __instance = new Game();
	return __instance;
}

void Game::Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom, int alpha)
{
	D3DXVECTOR3 p(x, y, 0);
	RECT r;
	r.left = left;
	r.top = top;
	r.right = right;
	r.bottom = bottom;
	spriteHandler->Draw(texture, &r, NULL, &p, D3DCOLOR_ARGB(alpha, 255, 255, 255));
}

void Game::Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, RECT r, int alpha)
{
	D3DXVECTOR3 p(x, y, 0);
	spriteHandler->Draw(
		texture,
		&r,
		NULL,
		&p,
		D3DCOLOR_ARGB(alpha, 255, 255, 255)
	);
}