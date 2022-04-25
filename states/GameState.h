//
// Created by Cole on 4/21/2022.
//

#ifndef ASTEROIDSSFML_GAMESTATE_H
#define ASTEROIDSSFML_GAMESTATE_H

#include "../Player.h"
#include "../managers/AsteroidManager.h"
#include "../managers/ProjectileManager.h"
#include "../managers/ResourceManager.h"

class ActiveState;
class BeginState;
class EndState;
class GameManager;

class GameState {
public:
    virtual void transitionState(GameManager* g);
    virtual void tickState();
    static int getWidth();
    static int getHeight();
    ProjectileManager& getProjectileManager();
    AsteroidManager& getAsteroidManager();
    ResourceManager &getResourceManager();
protected:
    GameManager& gameManager;
    sf::RenderWindow& window;
    ProjectileManager projectileManager;
    AsteroidManager asteroidManager;
    ResourceManager resourceManager;
    GameState(sf::RenderWindow& window, GameManager& gameManager);
    void changeState(GameManager*, GameState*);
    static float getDelta();
};


#endif //ASTEROIDSSFML_GAMESTATE_H
