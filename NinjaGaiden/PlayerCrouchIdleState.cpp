#include "PlayerCrouchIdleState.h"
#include "Player.h"
#include "GameDefine.h"
#include "PlayerIdleState.h"
#include "PlayerRunningState.h"



PlayerCrouchIdleState::PlayerCrouchIdleState(PlayerData *playerData)
{
	this->mPlayerData = playerData;
	this->mPlayerData->player->SetVx(0);
	this->mPlayerData->player->SetVy(0);
}


PlayerCrouchIdleState::~PlayerCrouchIdleState()
{
}

void PlayerCrouchIdleState::Update(float dt) {

}

void PlayerCrouchIdleState::HandleKeyboard(std::map<int, bool> keys) {
	if (keys[VK_DOWN] == false) {
		this->mPlayerData->player->SetState(new PlayerIdleState(this->mPlayerData));
		return;
	}
}

PlayerState::StateName PlayerCrouchIdleState::GetState() {
	return PlayerState::CrouchIdle;
}
