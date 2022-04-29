//
// Created by Cole on 4/21/2022.
//

#ifndef ASTEROIDSSFML_PLAYER_H
#define ASTEROIDSSFML_PLAYER_H

#include "SFML/Graphics.hpp"

class ActiveState;
class Player : public sf::CircleShape {
public:
    explicit Player();
private:
    void updatePlayerPos(double dt);
    friend class GameManager;
    friend class ActiveState;
    float leftRotationSpeed = 0;
    float rightRotationSpeed = 0;
    const float UPPER_ROTATION_BOUND = 5.f;
    const float LOWER_ROTATION_BOUND = -5.f;
    const float ROTATION_INC = .15f;
    const float LOWER_SPEED_BOUND = -100.f;
    const float UPPER_SPEED_BOUND = 250.f;
    const float SPEED_INC = 5.f;
    float speed = 0.f;
};

#endif //ASTEROIDSSFML_PLAYER_H
