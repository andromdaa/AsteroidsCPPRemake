
// Created by Cole on 4/21/2022.
//
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
{}

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

ProjectileManager &GameState::getProjectileManager() {
    return GameState::projectileManager;
}

AsteroidManager &GameState::getAsteroidManager() {
    return GameState::asteroidManager;
}


