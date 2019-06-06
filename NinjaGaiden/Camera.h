#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <d3dx9.h>
#include <d3d9.h>
#include "GameDefine.h"

class Camera
{
protected:

	float _xCam;
	float _yCam;

	float _xCamBackup;
	float _yCamBackup;
	float _boundaryLeftBackup;
	float _boundaryRightBackup;

	int _width;
	int _height;

	float _boundaryLeft; // bien trai 
	float _boundaryRight; // bien phai

	float vx;
	DWORD dt;

	bool isAutoGoX; // auto mode
	float AutoGoX_Distance; 
	float AutoGoX_Backup_X; // vi tri truoc che do auto

	bool isAllowFollowRYU;

public:

	Camera(int width, int height);

	//center of camera
	void SetPosition(float x, float y);
	void SetPosition(D3DXVECTOR3 pos);

	D3DXVECTOR3 GetPosition();
	RECT GetBound();

	~Camera();

	void Update(DWORD dt);

	D3DXVECTOR2 Transform(float, float);

	void SetPosition(float x, float y);

	float GetXCam();
	float GetYCam();
	int GetWidth();
	int GetHeight();

	bool checkObjectInCamera(float x, float y, float w, float h);

	bool AllowFollowSimon();
	void SetAllowFollowSimon(bool b);


	void SetAutoGoX(float Distance, float Speed); // set thong so auto
	void StopAutoGoX();
	bool GetIsAutoGoX();

	void SetBoundary(float left, float right); // set bien camera
	float GetBoundaryRight();
	float GetBoundaryLeft();

	void SetPositionBackup(float X, float Y);
	void RestorePosition();

	void SetBoundaryBackup(float l, float r);
	void RestoreBoundary();
};

#endif