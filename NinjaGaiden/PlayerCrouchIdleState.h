#pragma once
#include "PlayerState.h"

class PlayerCrouchIdleState : public PlayerState
{
public:
	PlayerCrouchIdleState(PlayerData *playerData);
	~PlayerCrouchIdleState();

	void Update(float dt);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();
};