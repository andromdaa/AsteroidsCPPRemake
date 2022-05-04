//
// Created by Cole on 4/22/2022.
//

#include "GameManager.h"
#include <utility>
#include <chrono>
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
            generateStars();
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
//    particleSystem.update(elapsed);
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

bool GameManager::getEnableAudio() {
    return enableAudio;
}

sf::Clock GameManager::getClock() {
    return clock;
}

void GameManager::generateStars() {
    //(move)? stars based on what direction that player is facing
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<float> xDistribution(10, (float) GameManager::getWidth() - 10);
    std::uniform_real_distribution<float> yDistribution(10, (float) GameManager::getHeight() - 10);
    std::uniform_real_distribution<float> sizeDistribution(1, 3);


    for (int i = 0; i < MAX_STARS; i++) {
        sf::CircleShape star(sizeDistribution(generator));
        star.setOrigin(star.getRadius(), star.getRadius());
        star.setPosition(xDistribution(generator), yDistribution(generator));
        stars.push_back(star);
    }
}

void GameManager::drawStars() {
    auto sIt = stars.begin();
    while (sIt != stars.end()) {
        window->draw(*sIt);
        sIt++;
    }
}
