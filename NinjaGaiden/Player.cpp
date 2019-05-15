#include "Player.h"
#include "PlayerIdleState.h"
#include "PlayerRunningState.h"

Player::Player() 
{
	mAnimationIdle = new Animation("Resources/Sprites/Ryu/Idle.png", 1, 1, 1, 0);
	mAnimationRunning = new Animation("Resources/Sprites/Ryu/Running.png", 3, 1, 3, 0.15f);
	
	this->mPlayerData = new PlayerData();
	this->mPlayerData->player = this;
	this->vx = 0;
	this->vy = 0;
	this->SetState(new PlayerIdleState(this->mPlayerData));

	allowJump = true;
}

Player::~Player()
{
}

void Player::Update(float dt) {
	mCurrentAnimation->Update(dt);

	if (this->mPlayerData->state) this->mPlayerData->state->Update(dt);

	Entity::Update(dt);
}

void Player::HandleKeyboard(std::map<int, bool> keys) {
	if (this->mPlayerData->state) this->mPlayerData->state->HandleKeyboard(keys);
}

void Player::OnKeyPressed(int key) {
	
}

void Player::OnKeyUp(int key) {

}

void Player::SetReverse(bool flag) {
	mCurrentReverse = flag;
}

void Player::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey) {
	mCurrentAnimation->FlipVertical(mCurrentReverse);
	mCurrentAnimation->SetPosition(this->GetPosition());

	mCurrentAnimation->Draw(D3DXVECTOR3(posX, posY, 0));
}

void Player::SetState(PlayerState *newState) {
	delete this->mPlayerData->state;

	this->mPlayerData->state = newState;

	this->changeAnimation(newState->GetState());

	mCurrentState = newState->GetState();
}

RECT Player::GetBound() {
	RECT rect;
	rect.left = this->posX - mCurrentAnimation->GetWidth() / 2;
	rect.right = rect.left + mCurrentAnimation->GetWidth();
	rect.top = this->posY - mCurrentAnimation->GetHeight() / 2;
	rect.bottom = rect.top + mCurrentAnimation->GetHeight();

	return rect;
}

void Player::changeAnimation(PlayerState::StateName state) {
	switch (state) {
	case PlayerState::Running:
		mCurrentAnimation = mAnimationRunning;
		break;

	case PlayerState::Idle:
		mCurrentAnimation = mAnimationIdle;
		break;
	}

	this->width = mCurrentAnimation->GetWidth();
	this->height = mCurrentAnimation->GetHeight();
}

Player::MoveDirection Player::getMoveDirection() {
	if (this->vx > 0) return MoveDirection::MoveToRight;
	else if (this->vx < 0) return MoveDirection::MoveToLeft;

	return MoveDirection::None;
}

PlayerState::StateName Player::getState() {
	return mCurrentState;
}