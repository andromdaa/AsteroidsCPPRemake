//
// Created by Cole on 4/20/2022.
//

#include "RotatingState.h"

void RotatingState::handleInput(sf::CircleShape &player, sf::Keyboard::Key input) {
    if(sf::Keyboard::isKeyPressed(input)) {
        switch(input) {
            case sf::Keyboard::Left:
                curRotationSpeed -= rotationDiff;
                player.rotate(curRotationSpeed);
                break;
            case sf::Keyboard::Right:
                curRotationSpeed += rotationDiff;
                player.rotate(curRotationSpeed);
                break;
            default:
                break;
        }
    }
}
