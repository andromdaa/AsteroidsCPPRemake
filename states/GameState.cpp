
// Created by Cole on 4/21/2022.
//

#include "GameState.h"

#include <utility>
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
asteroidManager(*this),
particleSystem(500, *this)
{}

void GameState::handleWindowEvents() {}


void GameState::changeState(GameManager* m, std::shared_ptr<GameState> s) {
    m->changeState(std::move(s));
}

double GameState::getDelta() const {
    return dt;
}

int GameState::getWidth() {
    return GameManager::WIDTH;
}

int GameState::getHeight() {
    return GameManager::HEIGHT;
}

void GameState::transitionState(GameManager *g) {}

void GameState::tickState() {
    sf::Time elapsed = clock.restart();
    particleSystem.update(elapsed);
    handleWindowEvents();
}

void GameState::renderState() {
    window.draw(particleSystem);
}

ResourceManager& GameState::getResourceManager() {
    return GameState::resourceManager;
}

ProjectileManager& GameState::getProjectileManager() {
    return GameState::projectileManager;
}

AsteroidManager& GameState::getAsteroidManager() {
    return GameState::asteroidManager;
}

void GameState::update(double dt) {
    GameState::dt = dt;
}

