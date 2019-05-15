#include "PlayerIdleState.h"
#include "Player.h"
#include "GameDefine.h"
#include "PlayerRunningState.h"



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
	}
}

PlayerState::StateName PlayerIdleState::GetState() {
	return PlayerState::Idle;
}