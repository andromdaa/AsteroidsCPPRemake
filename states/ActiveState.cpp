//
// Created by Cole on 4/21/2022.
//
#include "ActiveState.h"
#include "EndState.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "../GameManager.h"
#include <cmath>

using namespace sf;

ActiveState::ActiveState(sf::RenderWindow &window, GameManager& gameManager) :
        GameState(window, gameManager)
{
    resourceManager.text.setCharacterSize(24);
    asteroidManager.createAsteroids();
}

ActiveState *ActiveState::Instance(sf::RenderWindow& window, GameManager& gameManager) {
    static ActiveState* self;
    if(self == nullptr) {
        self = new ActiveState(window, gameManager);
    }
    return self;
}

void ActiveState::handleInput() {

    if(player.leftRotationSpeed <= player.LOWER_ROTATION_BOUND) player.leftRotationSpeed = player.LOWER_ROTATION_BOUND;
    else if(player.rightRotationSpeed >= player.UPPER_ROTATION_BOUND) player.rightRotationSpeed = player.UPPER_ROTATION_BOUND;

    if (player.speed >= player.UPPER_SPEED_BOUND) player.speed = player.UPPER_SPEED_BOUND;
    if (player.speed <= player.LOWER_SPEED_BOUND) player.speed = player.LOWER_SPEED_BOUND;

    if(Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        player.leftRotationSpeed -= player.ROTATION_INC;
        player.rotate(player.leftRotationSpeed);
    } else if(player.leftRotationSpeed < 0) {
        player.leftRotationSpeed += .25f;
        player.rotate(player.leftRotationSpeed);
    }

    if(Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        player.rightRotationSpeed += player.ROTATION_INC;
        player.rotate(player.rightRotationSpeed);
    } else if(player.rightRotationSpeed > 0) {
        player.rightRotationSpeed -= .25f;
        player.rotate(player.rightRotationSpeed);
    }

    if(Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        player.speed += player.SPEED_INC;
        player.updatePlayerPos(dt);
    }

    if(!Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if(player.speed > 0) player.speed -= 2.5f; //passively slow down the player, approach 0
        if(player.speed < 0) player.speed += 1.f; //if player is bounced off wall, passively approach 0 speed
        player.updatePlayerPos(dt);
    } else {
        player.speed -= 0.50f; //actively slow player
        player.updatePlayerPos(dt);
    }
}

sf::Vector2f ActiveState::getMovement(const sf::Shape &shape, float speed, double dt) {
    float x = (float) (speed * sin(shape.getRotation() * (float) PI / 180) *
            dt);
    float y = (float) (-speed * cos(shape.getRotation() * (float) PI / 180) *
            dt);

    return {x, y};
}

int ActiveState::removeCollisions(ProjectileManager& projectileManagerL, AsteroidManager& asteroidManagerL) {
    int scoreInc = 0;
    auto pIt = projectileManagerL.projectiles.begin(); //transition into getter
    auto aIt = asteroidManagerL.asteroids.begin(); //transition into getter

    for(int i = 0; i < projectileManagerL.getProjectiles().size(); i++) {
        if(pIt == projectileManagerL.getProjectiles().end()) break;
        auto projectile = std::next(pIt, i);
        for(int j = 0; j < asteroidManagerL.asteroids.size(); j++) {
            if(aIt == asteroidManagerL.asteroids.end()) break;
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

            int intersect = checkIntersect(6, x, y,projectile->getPosition().x, projectile->getPosition().y);
            if(intersect == 1) {
                i++;
                j++;
                scoreInc += (int) (asteroid->getScale().x * 50);
                projectileManagerL.getProjectiles().erase(projectile++);
                asteroidManagerL.asteroids.erase(asteroid++);
            }
        }
    }
    return scoreInc;
}

bool ActiveState::locationAllowed(float x, float y, sf::Vector2f movementInc, float radius) {
    if((x + movementInc.x) + radius > GameState::getWidth() || (x + movementInc.x) < radius) return false;
    if((y + movementInc.y) + radius > GameState::getHeight() || (y + movementInc.y) < radius) return false;
    return true;
}

void ActiveState::handleEvents() {
        sf::Event event{};
        window.pollEvent(event);

        if(event.key.code == sf::Keyboard::Escape) {
            window.close();
        }

        if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
            projectileManager.spawnProjectile(player);
            if(gameManager.enableAudio) resourceManager.playFireSound();
        }
}

int ActiveState::checkIntersect(int nvert, const float *vertx, const float *verty, float testx, float testy) {
    int i, j, c = 0;
    for (i = 0, j = nvert-1; i < nvert; j = i++) {
        if ( ((verty[i]>testy) != (verty[j]>testy)) &&
             (testx < (vertx[j]-vertx[i]) * (testy-verty[i]) / (verty[j]-verty[i]) + vertx[i]) )
            c = !c;
    }
    return c;
}

void ActiveState::tickState() {
    handleEvents();
    handleInput();
}

void ActiveState::renderState() {
    window.draw(player);
    projectileManager.drawAll(window);
    asteroidManager.drawAll(window);
}

void ActiveState::transitionState(GameManager *g) {
    changeState(g, EndState::Instance(window, gameManager));
}






