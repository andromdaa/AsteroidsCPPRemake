
// Created by Cole on 4/21/2022.
//
#include <random>
#include <chrono>
#include "GameState.h"
#include "../GameManager.h"
#include "BeginState.h"
#include "ActiveState.h"
#include "EndState.h"

GameState::GameState(sf::RenderWindow& window, GameManager& gameManager) :
gameManager(gameManager),
window(window),
player(),
resourceManager(),
projectileManager(*this),
asteroidManager(*this)
{
    generateStars();
}

void GameState::changeState(GameManager* m, GameState* s) {
    m->changeState(s);
}

float GameState::getDelta() {
    return GameManager::dt;
}

int GameState::getWidth() {
    return GameManager::WIDTH;
}

int GameState::getHeight() {
    return GameManager::HEIGHT;
}

void GameState::transitionState(GameManager *g) {}

void GameState::tickState() {}

ResourceManager& GameState::getResourceManager() {
    return GameState::resourceManager;
}

ProjectileManager& GameState::getProjectileManager() {
    return GameState::projectileManager;
}

AsteroidManager& GameState::getAsteroidManager() {
    return GameState::asteroidManager;
}

void GameState::generateStars() {
    //(move)? stars based on what direction that player is facing
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<float> xDistribution(10, (float) getWidth() - 10);
    std::uniform_real_distribution<float> yDistribution(10, (float) getHeight() - 10);
    std::uniform_real_distribution<float> sizeDistribution(1, 3);


    for(int i = 0; i < MAX_STARS; i++) {
        sf::CircleShape star(sizeDistribution(generator));
        star.setOrigin(star.getRadius(), star.getRadius());
        star.setPosition(xDistribution(generator), yDistribution(generator));
        stars.push_back(star);
    }
}

void GameState::drawStars() {
    auto sIt = stars.begin();
    while(sIt != stars.end()) {
        window.draw(*sIt);
        sIt++;
    }
}
