#ifndef __WEAPON_H__
#define	__WEAPON_H__

#include "GameDefine.h"
#include "Camera.h"
#include "Texture.h"
#include "Sprite.h" 
#include "GameObject.h"
#include "Item.h"


class Weapon : public GameObject
{
protected:
	bool isFinish;
	DWORD LastTimeAttack; // Thời điểm tấn công cuối cùng

public:
	Weapon();
	~Weapon();

	int GetDirection();
	void SetDirection(int Direction);

	virtual void Attack(float X, float Y, int Direction);


	virtual void Render(Camera *camera);
//<<<<<<< HEAD
	virtual void UpdatePositionFitSimon();
//=======
	virtual void UpdatePositionFitRyu();
//>>>>>>> 714df99a00490830f08e6caa737ad9114a8cb939
	virtual bool isCollision(GameObject* obj); // kiểm tra vũ khí này có va chạm với object kia hay không?
	virtual void RenderIcon(float X, float Y) = 0;
	bool GetFinish();

	void SetFinish(bool b);

	DWORD GetLastTimeAttack();
};



#endif