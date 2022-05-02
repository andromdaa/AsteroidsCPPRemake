//
// Created by Cole on 4/21/2022.
//

#ifndef ASTEROIDSSFML_GAMESTATE_H
#define ASTEROIDSSFML_GAMESTATE_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <list>

class GameManager;
class GameState {
public:
    virtual void transitionState(GameManager* g);
    virtual void tickState();
    virtual void update(double dt);
    virtual void renderState();
protected:
    GameManager& gameManager;
    GameState(sf::RenderWindow& window, GameManager& gameManager);
    void changeState(GameManager*, std::shared_ptr<GameState>);
private:
    friend class Util;
};


#endif //ASTEROIDSSFML_GAMESTATE_H
