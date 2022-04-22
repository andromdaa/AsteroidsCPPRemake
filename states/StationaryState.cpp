//
// Created by Cole on 4/21/2022.
//
#include "StationaryState.h"
#include "SFML/Graphics.hpp"
#include "../Player.h"
#include "SFML/Window/Keyboard.hpp"
#include "../Keys.h"

using namespace sf;

PlayerState *StationaryState::Instance() {
    static StationaryState* self;
    if(self == nullptr) {
        self = new StationaryState();
    }
    return self;
}

void StationaryState::processInput(Player* player, Keys key) {
    auto sKey = static_cast<sf::Keyboard::Key>(key);

    if(player->rotationSpeed >= player->UPPER_ROTATION_BOUND) player->rotationSpeed = player->UPPER_ROTATION_BOUND;
    if(player->rotationSpeed <= player->LOWER_ROTATION_BOUND) player->rotationSpeed = player->LOWER_ROTATION_BOUND;

    switch(sKey) {
        case Keyboard::Left:
            player->rotationSpeed -= player->ROTATION_INC;
            player->rotate(player->rotationSpeed);
            break;
        case Keyboard::Right:
            player->rotationSpeed += player->ROTATION_INC;
            player->rotate(player->rotationSpeed);
            break;
        default:
            break;
    }
}
