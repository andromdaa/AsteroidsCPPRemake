//
// Created by Cole on 4/23/2022.
//

#include "EndState.h"

EndState *EndState::Instance(sf::RenderWindow& window, GameManager& gameManager) {
    static EndState* self;
    if(self == nullptr) {
        self = new EndState(window, gameManager);
    }
    return self;
}

EndState::EndState(sf::RenderWindow& window, GameManager& gameManager) : GameState(window, gameManager) {}
