//
// Created by Cole on 4/22/2022.
//

#ifndef ASTEROIDSSFML_GAMEMANAGER_H
#define ASTEROIDSSFML_GAMEMANAGER_H

#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Graphics.hpp>

class GameState;
class GameManager {
public:
    explicit GameManager(sf::ContextSettings& settings);

    GameManager(sf::ContextSettings &settings, bool enableAudio);

//    void handleInput();
    void transitionState();
    void tickState();
    void tick();
    sf::RenderWindow window;
    bool enableAudio;
private:
    GameState* state;
    sf::Clock clock;
    friend class GameState;
    void changeState(GameState*);
    const static int WIDTH = 800;
    const static int HEIGHT = 600;
    inline static float dt = 0;
};




#endif //ASTEROIDSSFML_GAMEMANAGER_H
