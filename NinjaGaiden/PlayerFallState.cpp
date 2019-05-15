#include "PlayerFallState.h"
#include "Player.h"
#include "GameDefine.h"
#include "PlayerIdleState.h"
#include "PlayerRunningState.h"
#include "PlayerJumpState.h"



PlayerFallState::PlayerFallState(PlayerData *playerData)
{
	this->mPlayerData = playerData;
	acceleratorY = 10.0f;
	acceleratorX = 3.0f;

	if (this->mPlayerData->player->GetVx() == 0) allowMoveX = false;
	else allowMoveX = true;
}


PlayerFallState::~PlayerFallState()
{
}

void PlayerFallState::Update(float dt)
{
	this->mPlayerData->player->AddVy(acceleratorY);

	if (mPlayerData->player->GetVy() > Define::PLAYER_MAX_JUMP_VELOCITY) {
		mPlayerData->player->SetVy(Define::PLAYER_MAX_JUMP_VELOCITY);
	}
}

void PlayerFallState::HandleKeyboard(std::map<int, bool> keys)
{
	if (keys[VK_RIGHT]) {
		mPlayerData->player->SetReverse(false);

		isLeftOrRightKeyPressed = true;
		//di chuyen sang phai
		if (this->mPlayerData->player->GetVx() < Define::PLAYER_MAX_RUNNING_SPEED) {
			this->mPlayerData->player->AddVx(acceleratorX);

			if (this->mPlayerData->player->GetVx() >= Define::PLAYER_MAX_RUNNING_SPEED) {
				this->mPlayerData->player->SetVx(Define::PLAYER_MAX_RUNNING_SPEED);
			}
		}
	}
	else if (keys[VK_LEFT]) {
		mPlayerData->player->SetReverse(true);

		isLeftOrRightKeyPressed = true;
		//di chuyen sang trai
		if (this->mPlayerData->player->GetVx() > -Define::PLAYER_MAX_RUNNING_SPEED) {
			this->mPlayerData->player->AddVx(-acceleratorX);

			if (this->mPlayerData->player->GetVx() <= -Define::PLAYER_MAX_RUNNING_SPEED) {
				this->mPlayerData->player->SetVx(-Define::PLAYER_MAX_RUNNING_SPEED);
			}
		}
	}
	else isLeftOrRightKeyPressed = false;
	if (keys['C']) {
		this->mPlayerData->player->SetState(new PlayerIdleState(this->mPlayerData));
		return;
	}
}

PlayerState::StateName PlayerFallState::GetState()
{
	return PlayerState::Fall;
}