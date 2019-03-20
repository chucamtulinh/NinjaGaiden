#include <Windows.h>
#include "GAME.h"

int WINAPI WinMain(HINSTANCE h, HINSTANCE p, LPTSTR a, int c) {
	
	MSG msg;
	GAME game(h, 300, 600, (char *) "PingPong");
	if (!game.InitWindow()) {
		MessageBox(NULL, "Can't init game", "Error", MB_OK);
		return 0;
	}

	game.InitGame();

	LARGE_INTEGER startTime;
	LARGE_INTEGER frequence;
	float cntps = 0;
	float gameTime = 0;
	LARGE_INTEGER endTime;
	float delay = 0;
	ZeroMemory(&msg, sizeof(msg));
	QueryPerformanceFrequency(&frequence);
	cntps = 1000.0f / (float)frequence.QuadPart;
	QueryPerformanceCounter(&endTime);

	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {

			QueryPerformanceCounter(&startTime);
			game.Update(gameTime);
			game.Render();
			QueryPerformanceCounter(&endTime);
			gameTime = ((float)endTime.QuadPart - (float)startTime.QuadPart) * cntps;
		}
	}
	return 0;
}