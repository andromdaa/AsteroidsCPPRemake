//
// Created by Cole on 4/21/2022.
//

#include "states/GameState.h"
#include "states/ActiveState.h"

Player::Player(ActiveState& activeState) :
    sf::CircleShape(15.f, 3),
    activeState(activeState)
    {
    setOrigin(getRadius(), getRadius());
    setPosition(activeState.getWidth() / 2.f, activeState.getHeight() / 2.f);
}
void Player::updatePlayerPos() {
    sf::Vector2f movement = activeState.getMovement(*this, speed);
    if(activeState.locationAllowed(getPosition().x, getPosition().y, movement, getRadius())) {
        move(movement.x, movement.y);
    } else speed = -speed;
}

