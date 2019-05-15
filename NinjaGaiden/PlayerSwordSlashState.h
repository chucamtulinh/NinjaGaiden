#pragma once
#include "PlayerState.h"

class PlayerSwordSlashState : public PlayerState
{
public:
	PlayerSwordSlashState(PlayerData *playerData);
	~PlayerSwordSlashState();

	void Update(float dt);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();
};

