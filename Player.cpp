//
// Created by Cole on 4/20/2022.
//

#include "PlayerState.h"


class Player : public sf::CircleShape {
public:
    virtual void handleInput(sf::Keyboard::Key input) {
        state->handleInput(*this, input);
    }
    virtual void update() {
        state->update(*this);
    }
private:
    PlayerState* state;
};