#include "GAME.h"



GAME::GAME(HINSTANCE hIns, int w, int h, char * name)
{
	this->hInstance = hIns;
	this->Width = w;
	this->Height = h;
	this->hWnd = NULL;
	strcpy_s(this->windowName, name);
}

bool GAME::Check(RECT r1, RECT r2) {
	return !(r1.left + r1.right < r2.left || r1.top + r1.bottom < r2.top || r2.left + r2.right < r1.left || r2.top + r2.bottom < r1.top);
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
	graphic = new MGraphic(this->hWnd, 300, 600);
	if (!graphic->InitD3d()) return false;
	content = new MContent(graphic->GetDevice());
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

void GAME::Update(float gameTime) {
	ball->Update(gameTime);
	keyboard->GetState();
	bat1->Update(gameTime, keyboard);
	if (Check(bat1->rect, ball->rect)) {
		ball->dy = -ball->dy;
	}
	long x;
	//mouse->GetState(x);
	bat2->Update2(gameTime, keyboard); 
	if (Check(bat2->rect, ball->rect)) {
		ball->dy = -ball->dy;
	}
}

void GAME::Render() {
	graphic->Begin();
	ball->Render(graphic);
	bat1->Render(graphic);
	bat2->Render(graphic);
	graphic->End();
}