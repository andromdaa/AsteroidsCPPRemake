//
// Created by Cole on 4/21/2022.
//

#include "states/GameState.h"
#include "states/ActiveState.h"
#include "Player.h"


Player::Player() :
    sf::CircleShape(15.f, 3),
    healthSystem()
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

float Player::getSpeed() const {
    return speed;
}

void Player::drawPlayerElements(sf::RenderWindow& window) {
    window.draw(*this);
    for(auto& live : healthSystem.lives) {
        window.draw(live);
    }
}

HealthSystem::HealthSystem() {
    for(int i = 0; i < livesCtr; i++) {
        auto& live = lives[i];
        live = sf::CircleShape(15.f, 3);
        live.setFillColor(sf::Color::Transparent);
        live.setOutlineColor(sf::Color::White);
        live.setOutlineThickness(1.f);
        live.setOrigin(lives->getRadius(), lives->getRadius());
        live.setPosition((lives->getRadius() + (lives->getRadius() * (2 * i))), 50);
    }
}

int HealthSystem::decreaseLives() {
    return --livesCtr;
}


