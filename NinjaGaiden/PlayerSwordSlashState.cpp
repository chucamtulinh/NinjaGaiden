#include "PlayerSwordSlashState.h"
#include "Player.h"
#include "GameDefine.h"
#include "PlayerIdleState.h"



PlayerSwordSlashState::PlayerSwordSlashState(PlayerData *playerData)
{
	this->mPlayerData = playerData;	
}


PlayerSwordSlashState::~PlayerSwordSlashState()
{
}

void PlayerSwordSlashState::Update(float dt)
{
}

void PlayerSwordSlashState::HandleKeyboard(std::map<int, bool> keys)
{
	if (keys['X'] == false) {
		this->mPlayerData->player->SetState(new PlayerIdleState(this->mPlayerData));
		return;
	}
}

PlayerState::StateName PlayerSwordSlashState::GetState() {
	return PlayerState::SwordSlash;
}