//
// Created by Cole on 4/22/2022.
//

#include "GameManager.h"
#include "states/PlayerState.h"
#include <cmath>

GameManager::GameManager(sf::ContextSettings& settings)
        :
        window(sf::VideoMode(GameManager::WIDTH, GameManager::HEIGHT), "Asteroids",
               sf::Style::Default, settings),
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

int GameManager::removeCollisions() {
    int scoreInc = 0;
    auto pIt = projectileHandler->projectiles.begin();
    auto aIt = asteroidHandler->asteroids.begin();

    for(int i = 0; i < projectileHandler->projectiles.size(); i++) {
        auto projectile = std::next(pIt, i);
        for(int j = 0; j < asteroidHandler->asteroids.size(); j++) {
            auto asteroid = std::next(aIt, j);
            float x[] {
                asteroid->getTransform().transformPoint(asteroid->getPoint(0)).x,
                asteroid->getTransform().transformPoint(asteroid->getPoint(1)).x,
                asteroid->getTransform().transformPoint(asteroid->getPoint(2)).x,
                asteroid->getTransform().transformPoint(asteroid->getPoint(3)).x,
                asteroid->getTransform().transformPoint(asteroid->getPoint(4)).x,
                asteroid->getTransform().transformPoint(asteroid->getPoint(5)).x,
            };
            float y[] = {
                    asteroid->getTransform().transformPoint(asteroid->getPoint(0)).y,
                    asteroid->getTransform().transformPoint(asteroid->getPoint(1)).y,
                    asteroid->getTransform().transformPoint(asteroid->getPoint(2)).y,
                    asteroid->getTransform().transformPoint(asteroid->getPoint(3)).y,
                    asteroid->getTransform().transformPoint(asteroid->getPoint(4)).y,
                    asteroid->getTransform().transformPoint(asteroid->getPoint(5)).y,
            };

            int intersect = AsteroidManager::checkIntersect(6, x, y,projectile->getPosition().x, projectile->getPosition().y);
            if(intersect == 1) {
                i++;
                j++;
                scoreInc += (int) (asteroid->getScale().x * 50);
                projectileHandler->projectiles.erase(projectile++);
                asteroidHandler->asteroids.erase(asteroid++);
            }
        }
    }
    return scoreInc;
}
