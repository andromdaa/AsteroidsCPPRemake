
// Created by Cole on 4/21/2022.
//

#include "GameState.h"

#include <utility>
#include "../GameManager.h"
#include "BeginState.h"
#include "ActiveState.h"
#include "EndState.h"

GameState::GameState(sf::RenderWindow& window, GameManager& gameManager) :
gameManager(gameManager)
{}


void GameState::changeState(GameManager* m, std::shared_ptr<GameState> s) {
    m->changeState(std::move(s));
}

void GameState::transitionState(GameManager *g) {}

void GameState::tickState() {}

void GameState::renderState() {
    gameManager.drawStars();
}

void GameState::update(double t) {}

