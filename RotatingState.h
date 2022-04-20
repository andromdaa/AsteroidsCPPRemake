//
// Created by Cole on 4/20/2022.
//

#ifndef ASTEROIDSSFML_ROTATINGSTATE_H
#define ASTEROIDSSFML_ROTATINGSTATE_H


#include "PlayerState.h"

class RotatingState : public PlayerState {
public:
    RotatingState():
            rotationAngle(0),
            rotationDiff(0.005f),
            curRotationSpeed(0)
    {}

    void handleInput(sf::CircleShape& player, sf::Keyboard::Key input) override;

private:
    float curRotationSpeed;
    const float rotationDiff;
    float rotationAngle;
};


#endif //ASTEROIDSSFML_ROTATINGSTATE_H
