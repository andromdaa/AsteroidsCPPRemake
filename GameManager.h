//
// Created by Cole on 4/22/2022.
//

#ifndef ASTEROIDSSFML_GAMEMANAGER_H
#define ASTEROIDSSFML_GAMEMANAGER_H

#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"


class GameState;
class GameManager {
public:
    explicit GameManager(sf::ContextSettings& settings);

    GameManager(sf::ContextSettings &settings, bool enableAudio);

//    void handleInput();
    void update(double dt);
    void transitionState();
    void tickState();
    void renderState();
    sf::RenderWindow window;
    bool enableAudio;
    const double dt = 0.01;
private:
    GameState* state;
    friend class GameState;
    void changeState(GameState*);
    const static int WIDTH = 800;
    const static int HEIGHT = 600;
};




#endif //ASTEROIDSSFML_GAMEMANAGER_H
