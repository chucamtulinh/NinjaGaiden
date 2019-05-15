#pragma once
#include "PlayerState.h"

class PlayerIdleState : public PlayerState
{
public:
    PlayerIdleState(PlayerData *playerData);
    ~PlayerIdleState();

    void Update(float dt);

    void HandleKeyboard(std::map<int, bool> keys);

    virtual StateName GetState();
};