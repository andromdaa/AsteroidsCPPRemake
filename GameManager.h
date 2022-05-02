//
// Created by Cole on 4/22/2022.
//

#ifndef ASTEROIDSSFML_GAMEMANAGER_H
#define ASTEROIDSSFML_GAMEMANAGER_H

#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include "Player.h"


class GameState;
class GameManager {
public:
    explicit GameManager(sf::ContextSettings& settings);
    GameManager(sf::ContextSettings &settings, bool enableAudio);
    GameManager(sf::ContextSettings &settings, bool enableAudio, sf::RenderWindow* window);
    void update(double dt);
    void tickState();
    void renderState();
    std::shared_ptr<sf::RenderWindow> window;
    bool enableAudio{};
    const double dt = 0.01;
private:
    std::shared_ptr<GameState> state;
    friend class GameState;
    friend class Util;
    void changeState(std::shared_ptr<GameState> s);
    const static int WIDTH = 800;
    const static int HEIGHT = 600;
};



#endif //ASTEROIDSSFML_GAMEMANAGER_H
