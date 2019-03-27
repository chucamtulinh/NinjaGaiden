#pragma once
#include <dinput.h>

class MMouse
{
	LPDIRECTINPUT8 di8;
	LPDIRECTINPUTDEVICE8 did8;
	HINSTANCE hInstance;
	HWND hWnd;
public:
	typedef struct DIMOUSESTATE {
		long lx, ly, lz;
		byte rgbButtons[4];
	}DIMOUSESTATE, *LPDIMOUSESTATE;
	DIMOUSESTATE mouseState;
	long curx, cury;
	bool Init();
	MMouse(HINSTANCE hIns, HWND hwnd);
	~MMouse(void);
	void GetState();
};

