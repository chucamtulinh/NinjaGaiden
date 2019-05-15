#pragma once
#include "PlayerState.h"

class PlayerFallState : public PlayerState
{
public:
	PlayerFallState(PlayerData *playerData);
	~PlayerFallState();

	void Update(float dt);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();

protected:
	//do bien tien van toc sau moi frame tinh bang pixel / s
	float acceleratorY;
	float acceleratorX;

	//neu nhu van toc ban dau = khong thi se khong cho giam toc do
	bool allowMoveX;

	bool isLeftOrRightKeyPressed;
};