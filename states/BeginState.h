//
// Created by Cole on 4/23/2022.
//

#ifndef ASTEROIDSSFML_BEGINSTATE_H
#define ASTEROIDSSFML_BEGINSTATE_H

#include "GameState.h"

class BeginState : public GameState {
public:
    static BeginState* Instance(sf::RenderWindow &window, GameManager& gameManager);
    void transitionState(GameManager* g) override;
    void tickState() override;
    void handleEvents();
private:
    BeginState(sf::RenderWindow &window, GameManager& gameManager);
};


#endif //ASTEROIDSSFML_BEGINSTATE_H
