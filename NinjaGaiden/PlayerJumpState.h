#pragma once
#include "PlayerState.h"

class PlayerJumpState : public PlayerState
{
public:
	PlayerJumpState(PlayerData *playerData);
	~PlayerJumpState();

	void Update(float dt);

    void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState();
protected:
	float acceleratorY;
	float acceleratorX;
	bool noPressed;
	bool allowMoveRight, allowMoveLeft;
};

