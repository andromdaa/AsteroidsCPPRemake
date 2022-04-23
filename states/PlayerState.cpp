
// Created by Cole on 4/21/2022.
//
#include "PlayerState.h"
#include "../Player.h"
#include "PlayingState.h"
#include "SFML/Graphics.hpp"

void PlayerState::processInput(Player* player) {}

void PlayerState::changeState(Player* p, PlayerState* s) {
    p->changeState(s);
}

