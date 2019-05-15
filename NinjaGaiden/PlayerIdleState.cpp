#include "PlayerIdleState.h"
#include "Player.h"
#include "GameDefine.h"
#include "PlayerRunningState.h"
#include "PlayerCrouchIdleState.h"
#include "PlayerSwordSlashState.h"
#include "PlayerJumpState.h"



PlayerIdleState::PlayerIdleState(PlayerData *playerData)
{
	this->mPlayerData = playerData;
	this->mPlayerData->player->SetVx(0);
	this->mPlayerData->player->SetVy(0);
}


PlayerIdleState::~PlayerIdleState()
{
}

void PlayerIdleState::Update(float dt) {

}

void PlayerIdleState::HandleKeyboard(std::map<int, bool> keys) {
	if (keys[VK_LEFT] || keys[VK_RIGHT]) {
		this->mPlayerData->player->SetState(new PlayerRunningState(this->mPlayerData));
		return;
	}
	if (keys[VK_DOWN]) {
		this->mPlayerData->player->SetState(new PlayerCrouchIdleState(this->mPlayerData));
		return;
	}
	if (keys['X']) {
		this->mPlayerData->player->SetState(new PlayerSwordSlashState(this->mPlayerData));
		return;
	}
	if (keys['Z']) {
		this->mPlayerData->player->SetState(new PlayerJumpState(this->mPlayerData));
		return;
	}
}

PlayerState::StateName PlayerIdleState::GetState() {
	return PlayerState::Idle;
}