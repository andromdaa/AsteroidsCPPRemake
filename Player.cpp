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
    healthSystem.drawElements(window);
}

HealthSystem::HealthSystem() :
life(sf::CircleShape(15.f, 3))
{
    life.setFillColor(sf::Color::Transparent);
    life.setFillColor(sf::Color::Transparent);
    life.setOutlineColor(sf::Color::White);
    life.setOutlineThickness(1.f);
    life.setOrigin(life.getRadius(), life.getRadius());
}

void HealthSystem::drawElements(sf::RenderWindow& window) {
    for(int i = 0; i < livesCtr; i++) {
        life.setPosition((life.getRadius() + (life.getRadius() * (2 * i))), 50);
        window.draw(life);
    }
}

int HealthSystem::decreaseLives() {
    livesCtr--;
    return livesCtr;
}

void HealthSystem::reset() {
    livesCtr = 3;
}

void Player::reset() {
    setRotation(0);
    setPosition(ActiveState::getWidth() / 2.f, ActiveState::getHeight() / 2.f);
    isColliding = false;
    healthSystem.reset();
    leftRotationSpeed = 0;
    rightRotationSpeed = 0;
    speed = 0.f;
}

