//
// Created by Cole on 4/21/2022.
//

#include "Player.h"
#include "states/StationaryState.h"
#include "Keys.h"

Player::Player(sf::RenderWindow* window) : sf::CircleShape(15.f, 3) {
    state = StationaryState::Instance();
    Player::window = window;

    setPosition(window->getView().getCenter());
    setOrigin(getRadius(), getRadius());
}

void Player::processInput(Player* player, Keys key) {
        state->processInput(player, key);
}