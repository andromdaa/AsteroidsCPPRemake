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
    virtual void update(double dt);
    virtual void renderState();
    static int getWidth();
    static int getHeight();
    ProjectileManager& getProjectileManager();
    AsteroidManager& getAsteroidManager();
    ResourceManager &getResourceManager();
    double getDelta() const;
protected:
    double dt = 0;
    GameManager& gameManager;
    sf::RenderWindow& window;
    Player player;
    ProjectileManager projectileManager;
    AsteroidManager asteroidManager;
    ResourceManager resourceManager;
    constexpr static float PI = 3.14159265f;
    GameState(sf::RenderWindow& window, GameManager& gameManager);
    void changeState(GameManager*, GameState*);
    std::list<sf::CircleShape> stars;
private:
};


#endif //ASTEROIDSSFML_GAMESTATE_H
