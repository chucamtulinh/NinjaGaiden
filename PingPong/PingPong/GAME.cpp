#include "GAME.h"



GAME::GAME(HINSTANCE hIns, int w, int h, char * name)
{
	this->hInstance = hIns;
	this->Width = w;
	this->Height = h;
	this->hWnd = NULL;
	strcpy_s(this->windowName, name);
}

float SweptAABB(Box b1, Box b2, float& normalx, float& normaly) {
	float xInvEntry, yInvEntry, xInvExit, yInvExit;

	if (b1.vx > 0.0f) {
		xInvEntry = b2.x - (b1.x + b1.w);
		xInvExit = (b2.x + b2.w) - b1.x;
	}
	else {
		xInvEntry = (b2.x + b2.w) - b1.x;
		xInvExit = b2.x - (b1.x + b1.w);
	}

	if (b1.vy > 0.0f) {
		yInvEntry = b2.y - (b1.y + b1.h);
		yInvExit = (b2.y + b2.h) - b1.y;
	}
	else {
		yInvEntry = (b2.y + b2.h) - b1.y;
		yInvExit = b2.y - (b1.y + b1.h);
	}

	float xEntry, yEntry, xExit, yExit;

	if (b1.vx == 0.0f) {
		xEntry = -numeric_limits<float>::infinity();
		xExit = numeric_limits<float>::infinity();
	}
	else {
		xEntry = xInvEntry / b1.vx;
		xExit = xInvExit / b1.vx;
	}

	if (b1.vy == 0.0f) {
		yEntry = -numeric_limits<float>::infinity();
		yExit = numeric_limits<float>::infinity();
	}
	else {
		yEntry = yInvEntry / b1.vy;
		yExit = yInvExit / b1.vy;
	}

	float entryTime = max(xEntry, yEntry), exitTime = min(xExit, yExit);

	if (entryTime > exitTime || (xEntry < 0.0f && yEntry < 0.0f) || xEntry > 1.0f || yEntry > 1.0f) {
		normalx = 0.0f;
		normaly = 0.0f;
		return 1.0f;
	}
	else {
		if (xEntry > yEntry) {
			if (xInvEntry < 0.0f) {
				normalx = 1.0f;
				normaly = 0.0f;
			}
			else {
				normalx = -1.0f;
				normaly = 0.0f;
			}
		}
		else {
			if (yInvEntry < 0.0f) {
				normalx = 0.0f;
				normaly = 1.0f;
			}
			else {
				normalx = 0.0f;
				normaly = -1.0f;
			}
		}
	}
	return entryTime;
}

Box GetSweptBroadPhaseBox(Box b) {
	Box bb;
	bb.x = b.vx > 0 ? b.x : b.x + b.vx;
	bb.y = b.vy > 0 ? b.y : b.y + b.vy;
	bb.w = b.vx > 0 ? b.vx + b.w : b.w - b.vx;
	bb.h = b.vy > 0 ? b.vy + b.h : b.h - b.vy;
	return bb;
}

GAME::~GAME(void)
{
}

LRESULT CALLBACK GAME::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	if (message == WM_DESTROY) {
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

bool GAME::InitWindow() {
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIconSm = 0;
	wc.hIcon = 0;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = this->hInstance;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.lpszClassName = "GAME";
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) {
		return false;
	}
	this->hWnd = CreateWindow(
		"GAME",
		this->windowName,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		this->Width,
		this->Height,
		NULL,
		NULL,
		this->hInstance,
		NULL
	);
	if (!this->hWnd) return false;
	ShowWindow(this->hWnd, SW_NORMAL);
	UpdateWindow(this->hWnd);
	graphic = new MGraphic(this->hWnd, 600, 800);
	if (!graphic->InitD3d()) return false;
	content = new MContent(graphic->GetDevice());
	this->img = content->LoadTexture("background.png");
	this->position = D3DXVECTOR2(0, 0);
	return true;
}

void GAME::InitGame() {
	ball = new Ball();
	ball->Init(content);
	bat1 = new Bat();
	bat1->InitDown(content);
	keyboard = new MKeyboard(hInstance, hWnd);
	keyboard->Init();
	bat2 = new Bat();
	bat2->InitUp(content);
	mouse = new MMouse(hInstance, hWnd);
	mouse->Init();
}

bool GAME::Check(RECT r1, RECT r2) {
	return !(r1.left + r1.right < r2.left || r1.top + r1.bottom < r2.top || r2.left + r2.right < r1.left || r2.top + r2.bottom < r1.top);
}

bool GAME::AABBCheck(Box b1, Box b2) {
	return !(b1.x + b1.w < b2.x || b1.x > b2.x + b2.w || b1.y + b1.h < b2.y || b1.y > b2.y + b2.h);
}

void GAME::CheckAABB(Ball* ball, Bat* bat) {
	Box bb = GetSweptBroadPhaseBox(ball->bball);
	if (AABBCheck(bb, bat->bbat)) {
		float normalx, normaly;
		float collisiontime = SweptAABB(ball->bball, bat->bbat, OUT normalx, OUT normaly);
		ball->bball.x += ball->bball.vx * collisiontime;
		ball->bball.y += ball->bball.vy * collisiontime;
		float remainingtime = 1.0f - collisiontime;
		ball->bball.vx *= remainingtime;
		ball->bball.vy *= remainingtime;
		/*if (Check(ball->rect, bat->rect)) {
		ball->dx = -ball->dx;
		ball->bball.vx = -ball->bball.vx;
		ball->dy = -ball->dy;
		ball->bball.vy = -ball->bball.vy;
		return true;
		};*/
		if (abs(normalx) > 0.0001f) {
			ball->dx = -ball->dx;
			ball->bball.vx = -ball->bball.vx;
		};
		if (abs(normaly) > 0.0001f) {
			ball->dy = -ball->dy;
			ball->bball.vy = -ball->bball.vy;
		};
		//return false;
	}
}

void GAME::Update(float gameTime) {
	ball->Update(gameTime);
	keyboard->GetState();
	mouse->GetState();
	bat1->Update(gameTime, keyboard);
	//if (AABBCheck(ball->bball, bat1->bbat)) ball->dy = -ball->dy;
	CheckAABB(ball, bat1);
	bat2->Update(gameTime, mouse);
	//if (AABBCheck(ball->bball, bat2->bbat)) ball->dy = -ball->dy;
	CheckAABB(ball, bat2);
}

void GAME::Render() {
	graphic->Begin();
	graphic->DrawTexture(this->img, this->position, D3DCOLOR_XRGB(255, 255, 255));
	ball->Render(graphic);
	bat1->Render(graphic);
	bat2->Render(graphic);
	graphic->End();
}