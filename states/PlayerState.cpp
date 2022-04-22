
// Created by Cole on 4/21/2022.
//
#include "PlayerState.h"
#include "../Player.h"
#include "StationaryState.h"
#include "SFML/Graphics.hpp"
#include "../Keys.h"

void PlayerState::processInput(Player* player, Keys key) {}

void PlayerState::changeState(Player* p, PlayerState* s) {
    p->changeState(s);
}

