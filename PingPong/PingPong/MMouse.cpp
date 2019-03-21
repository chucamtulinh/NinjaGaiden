#include "MMouse.h"



MMouse::MMouse(HINSTANCE hIns, HWND hwnd)
{
	this->di8 = 0;
	this->did8 = 0;
	this->hInstance = hIns;
	this->hWnd = hwnd;
}

bool MMouse::Init() {
	HRESULT hr = DirectInput8Create(
		this->hInstance,
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&this->di8,
		NULL
	);
	if (FAILED(hr)) return false;
	hr = this->di8->CreateDevice(GUID_SysMouse, &this->did8, NULL);
	if (FAILED(hr)) return false;
	hr = this->did8->SetDataFormat(&c_dfDIMouse);
	if (FAILED(hr)) return false;
	hr = this->did8->SetCooperativeLevel(this->hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if (FAILED(hr)) return false;
	hr = this->did8->Acquire();
	if (FAILED(hr)) return false;
}

void MMouse::GetState(long &x) {
	DIMOUSESTATE mouseState;
	long currentXpos = 320, currentYpos = 240, currentZpos;
	while (1) {
		HRESULT hr = this->did8->GetDeviceState(sizeof(mouseState), (LPVOID)&mouseState);

		currentXpos += mouseState.lx;
		x = currentXpos;
		currentYpos += mouseState.ly;
	}
}

MMouse::~MMouse(void)
{
}
