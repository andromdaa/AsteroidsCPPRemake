//
// Created by Cole on 4/22/2022.
//

#include "GameManager.h"
#include "states/BeginState.h"
#include "states/ActiveState.h"
#include "states/EndState.h"

GameManager::GameManager(sf::ContextSettings& settings)
        :
        window(sf::VideoMode(GameManager::WIDTH, GameManager::HEIGHT), "Asteroids",
               sf::Style::Default, settings)
        {
    state = BeginState::Instance(window, *this);
}

void GameManager::tick() {
    GameManager::dt = GameManager::clock.restart().asSeconds();
}

void GameManager::changeState(GameState* s) {
    state = s;
}

//void GameManager::handleInput() {
//    state->tickState();
//}

void GameManager::transitionState() {
    state->transitionState(this);
}

void GameManager::tickState() {
    state->tickState();
}
