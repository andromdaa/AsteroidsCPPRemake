//
// Created by Cole on 4/21/2022.
//

#ifndef ASTEROIDSSFML_PLAYER_H
#define ASTEROIDSSFML_PLAYER_H

#include "SFML/Graphics.hpp"

class PlayerState;
enum class Keys;

class Player : public sf::CircleShape {
public:
    Player();
    void processInput(Player*);
private:
    void updatePlayerPos();
    friend class PlayerState;
    friend class PlayingState;
    friend class GameManager;
    PlayerState* state;
    float rotationSpeed = 0;
    const float UPPER_ROTATION_BOUND = .1f;
    const float LOWER_ROTATION_BOUND = -.1f;
    const float ROTATION_INC = 0.005f;
    const float PROJECTILE_SPEED = 600.f;
    const double PI = 3.14159265f;
    const float LOWER_SPEED_BOUND = -100.f;
    const float UPPER_SPEED_BOUND = 1000.f;
    const float SPEED_INC = .25f;
    float speed = 0.f;
    void changeState(PlayerState* s) {
        state = s;
    }
};

#endif //ASTEROIDSSFML_PLAYER_H
