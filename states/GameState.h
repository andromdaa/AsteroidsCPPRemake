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
    Player player;
    ProjectileManager projectileManager;
    AsteroidManager asteroidManager;
    ResourceManager resourceManager;
    constexpr static float PI = 3.14159265f;
    GameState(sf::RenderWindow& window, GameManager& gameManager);
    void changeState(GameManager*, GameState*);
    static float getDelta();
    std::list<sf::CircleShape> stars;
    void drawStars();
private:
    const int MAX_STARS = 100;
    void generateStars();
};


#endif //ASTEROIDSSFML_GAMESTATE_H
