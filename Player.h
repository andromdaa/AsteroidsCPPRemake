//
// Created by Cole on 4/21/2022.
//

#ifndef ASTEROIDSSFML_PLAYER_H
#define ASTEROIDSSFML_PLAYER_H

#include "SFML/Graphics.hpp"

class ActiveState;
class Player : public sf::CircleShape {
public:
    explicit Player(ActiveState&);
private:
    ActiveState& activeState;
    void updatePlayerPos();
    friend class GameManager;
    friend class ActiveState;
    float rotationSpeed = 0;
    const float UPPER_ROTATION_BOUND = .1f;
    const float LOWER_ROTATION_BOUND = -.1f;
    const float ROTATION_INC = 0.005f;
    const float LOWER_SPEED_BOUND = -100.f;
    const float UPPER_SPEED_BOUND = 1000.f;
    const float SPEED_INC = .25f;
    float speed = 0.f;
};

#endif //ASTEROIDSSFML_PLAYER_H
