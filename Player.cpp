//
// Created by Cole on 4/21/2022.
//

#include "states/GameState.h"
#include "states/ActiveState.h"

Player::Player() :
    sf::CircleShape(15.f, 3)
    {
    setOrigin(getRadius(), getRadius());
    setPosition(ActiveState::getWidth() / 2.f, ActiveState::getHeight() / 2.f);
}
void Player::updatePlayerPos(double dt) {
    sf::Vector2f movement = ActiveState::getMovement(*this, speed, dt);
    if(ActiveState::locationAllowed(getPosition().x, getPosition().y, movement, getRadius())) {
        move(movement.x, movement.y);
    } else speed = -speed;
}

float Player::getSpeed() {
    return speed;
}
