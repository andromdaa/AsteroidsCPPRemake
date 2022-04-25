//
// Created by Cole on 4/23/2022.
//

#ifndef ASTEROIDSSFML_ENDSTATE_H
#define ASTEROIDSSFML_ENDSTATE_H

#include "GameState.h"

class EndState : public GameState {
public:
    explicit EndState(sf::RenderWindow& window, GameManager& gameManager);
    static EndState* Instance(sf::RenderWindow& window, GameManager& gameManager);
};

#endif //ASTEROIDSSFML_ENDSTATE_H
