//
// Created by Cole on 4/22/2022.
//

#include "GameManager.h"
#include "states/PlayerState.h"
#include <cmath>
#include <iostream>

GameManager::GameManager()
        :
        window(sf::VideoMode(GameManager::WIDTH, GameManager::HEIGHT), "Asteroids",
               sf::Style::Default),
        player(),
        eventHandler(window, *this) {
}

void GameManager::tick() {
    GameManager::dt = GameManager::clock.restart().asSeconds();
}

bool GameManager::locationAllowed(float x, float y, sf::Vector2f movementInc, float radius) {
    if((x + movementInc.x) + radius > GameManager::WIDTH || (x + movementInc.x) < radius) return false;
    if((y + movementInc.y) + radius > GameManager::HEIGHT || (y + movementInc.y) < radius) return false;
    return true;
}

sf::Vector2f GameManager::getMovement(const sf::Shape& shape, float speed) {
    float x = (speed * sin(shape.getRotation() * (float) PI / 180) *
               dt);
    float y = (-speed * cos(shape.getRotation() * (float) PI / 180) *
               dt);

    return {x, y};
}


