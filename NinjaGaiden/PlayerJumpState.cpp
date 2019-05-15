#include "PlayerJumpState.h"
#include "Player.h"
#include "GameDefine.h"
#include "PlayerIdleState.h"
#include "PlayerRunningState.h"
#include "PlayerFallState.h"



PlayerJumpState::PlayerJumpState(PlayerData *playerData)
{
	this->mPlayerData = playerData;
	this->mPlayerData->player->SetVy(Define::PLAYER_MIN_JUMP_VELOCITY);

	acceleratorY = 5.0f;
	acceleratorX = 6.0f;

	noPressed = false;
}


PlayerJumpState::~PlayerJumpState()
{
}

void PlayerJumpState::Update(float dt)
{
	this->mPlayerData->player->AddVy(acceleratorY);

	if (mPlayerData->player->GetVy() >= 0) {
		mPlayerData->player->SetState(new PlayerFallState(this->mPlayerData));
		return;
	}

	if (noPressed) {
		if (mPlayerData->player->getMoveDirection() == Player::MoveToLeft) {
			//player dang di chuyen sang ben trai      
			if (mPlayerData->player->GetVx() < 0) {
				this->mPlayerData->player->AddVx(acceleratorX);

				if (mPlayerData->player->GetVx() > 0) this->mPlayerData->player->SetVx(0);
			}
		}
		else if (mPlayerData->player->getMoveDirection() == Player::MoveToRight) {
			//player dang di chuyen sang phai   
			if (mPlayerData->player->GetVx() > 0) {
				this->mPlayerData->player->AddVx(-acceleratorX);

				if (mPlayerData->player->GetVx() < 0) this->mPlayerData->player->SetVx(0);
			}
		}
	}
}

void PlayerJumpState::HandleKeyboard(std::map<int, bool> keys)
{
	if (keys[VK_RIGHT]) {
		mPlayerData->player->SetReverse(false);

		//di chuyen sang phai
		if (this->mPlayerData->player->GetVx() < Define::PLAYER_MAX_RUNNING_SPEED) {
			this->mPlayerData->player->AddVx(acceleratorX);

			if (this->mPlayerData->player->GetVx() >= Define::PLAYER_MAX_RUNNING_SPEED)	{
				this->mPlayerData->player->SetVx(Define::PLAYER_MAX_RUNNING_SPEED);
			}
		}

		noPressed = false;
	}
	else if (keys[VK_LEFT]) {
		mPlayerData->player->SetReverse(true);

		//di chuyen sang trai
		if (this->mPlayerData->player->GetVx() > -Define::PLAYER_MAX_RUNNING_SPEED) {
			this->mPlayerData->player->AddVx(-acceleratorX);

			if (this->mPlayerData->player->GetVx() < -Define::PLAYER_MAX_RUNNING_SPEED)	{
				this->mPlayerData->player->SetVx(-Define::PLAYER_MAX_RUNNING_SPEED);
			}
		}

		noPressed = false;
	}
	else noPressed = true;
}

PlayerState::StateName PlayerJumpState::GetState() {
	return PlayerState::Jump;
}