//
// Created by Cole on 4/22/2022.
//

#include "GameManager.h"
#include <utility>
#include "states/BeginState.h"
#include "states/ActiveState.h"
#include "states/EndState.h"

GameManager::GameManager(sf::ContextSettings &settings, bool enableAudio)
        :
        window(new sf::RenderWindow(sf::VideoMode(GameManager::WIDTH, GameManager::HEIGHT), "Asteroids",
                                    sf::Style::Default,
                                    settings)),
        enableAudio(enableAudio),
        particleSystem(1000, *this),
        asteroidManager(*this),
        projectileManager(*this),
        resourceManager(),
        player()
        {
    state = BeginState::Instance(*window, *this);
}


ResourceManager &GameManager::getResourceManager() {
    return GameManager::resourceManager;
}

ProjectileManager &GameManager::getProjectileManager() {
    return GameManager::projectileManager;
}

AsteroidManager &GameManager::getAsteroidManager() {
    return GameManager::asteroidManager;
}


void GameManager::changeState(std::shared_ptr<GameState> s) {
    state = std::move(s);
}

void GameManager::tickState() {
    auto elapsed = clock.restart();
    particleSystem.update(elapsed);
    state->tickState();
}

void GameManager::renderState() {
    state->renderState();
}

void GameManager::update(double dt2) {
}

double GameManager::getDelta() const {
    return dt;
}

int GameManager::getWidth() {
    return GameManager::WIDTH;
}

int GameManager::getHeight() {
    return GameManager::HEIGHT;
}

Player &GameManager::getPlayer() {
    return player;
}

ParticleSystem &GameManager::getParticleSystem() {
    return particleSystem;
}

sf::RenderWindow &GameManager::getWindow() {
    return *window;
}

