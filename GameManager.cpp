//
// Created by Cole on 4/22/2022.
//

#include "GameManager.h"
#include "states/PlayerState.h"
#include <cmath>

GameManager::GameManager()
        :
        window(sf::VideoMode(GameManager::WIDTH, GameManager::HEIGHT), "Asteroids",
               sf::Style::Default),
        player(),
        eventHandler(window) {}

void GameManager::tick() {
    GameManager::dt = GameManager::clock.restart().asSeconds();
}

bool GameManager::locationAllowed(float x, float y, sf::Vector2f movementInc, float radius) {
    if((x + movementInc.x) + radius > GameManager::WIDTH || (x + movementInc.x) < radius) return false;
    if((y + movementInc.y) + radius > GameManager::HEIGHT || (y + movementInc.y) < radius) return false;
    return true;
}

sf::Vector2f GameManager::getMovement(const sf::Shape& shape, float speed) {
    return sf::Vector2f(speed * sin(shape.getRotation()* PI / 180) * dt,
                        -speed * cos(shape.getRotation()* PI / 180) * dt);
}