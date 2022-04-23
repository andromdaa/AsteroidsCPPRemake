//
// Created by Cole on 4/21/2022.
//

#include "Player.h"
#include "states/PlayingState.h"
#include "GameManager.h"

Player::Player() : sf::CircleShape(15.f, 3) {
    state = PlayingState::Instance();
    setOrigin(getRadius(), getRadius());
    setPosition(GameManager::WIDTH / 2.f, GameManager::HEIGHT / 2.f);
}
void Player::updatePlayerPos() {
    sf::Vector2f movement = GameManager::getMovement(*this, speed);
    if(GameManager::locationAllowed(getPosition().x, getPosition().y, movement, getRadius())) {
        move(movement.x, movement.y);
    } else speed = -speed;
}

void Player::processInput(Player* player) {
        state->processInput(player);
}