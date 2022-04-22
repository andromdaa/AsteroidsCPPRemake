//
// Created by Cole on 4/21/2022.
//

#ifndef ASTEROIDSSFML_PLAYER_H
#define ASTEROIDSSFML_PLAYER_H

#include <SFML/Graphics.hpp>

class PlayerState;
enum class Keys;

class Player : public sf::CircleShape {
public:
    Player(sf::RenderWindow* window);
    void processInput(Player*, Keys);
private:
    sf::RenderWindow* window;
    PlayerState* state;
    friend class PlayerState;
    friend class StationaryState;
    const float ROTATION_INC = 0.005f;
    const float PROJECTILE_SPEED = 600.f;
    const double PI = 3.14159265f;
    const float UPPER_ROTATION_BOUND = .1f;
    const float LOWER_ROTATION_BOUND = -.1f;
    const float LOWER_SPEED_BOUND = -100.f;
    const unsigned short UPPER_SPEED_BOUND = 500;
    float speed = 0; //reference due to continuous value
    float rotationSpeed = 0; //reference due to continuous value
    void changeState(PlayerState* s) {
        state = s;
    }
};

#endif //ASTEROIDSSFML_PLAYER_H
