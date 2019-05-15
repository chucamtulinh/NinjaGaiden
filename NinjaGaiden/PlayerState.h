#pragma once
#include "PlayerData.h"
#include "Entity.h"
#include <map>

class PlayerState
{
public:
	enum StateName {
		Climp,
		CrouchIdle,
		CrouchSlash,
		Idle,
		ItemUse,
		Jump,
		Fall,
		OnWall,
		Running,
		SpinSlash,
		SwordSlash
	};

	~PlayerState();

	virtual void Update(float dt);

	virtual void HandleKeyboard(std::map<int, bool> keys);

	//ham thuan ao bat buoc phai ke thua
	virtual StateName GetState() = 0;

protected:
	PlayerState(PlayerData *playerData);
	PlayerState();

	PlayerData *mPlayerData;
};

