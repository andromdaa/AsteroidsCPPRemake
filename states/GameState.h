//
// Created by Cole on 4/21/2022.
//

#ifndef ASTEROIDSSFML_GAMESTATE_H
#define ASTEROIDSSFML_GAMESTATE_H

#include "../Player.h"
#include "../managers/AsteroidManager.h"
#include "../managers/ProjectileManager.h"
#include "../managers/ResourceManager.h"
#include "../CustomSFMLShapes/ParticleSystem.h"

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
    inline static int score = 0;
protected:
    double dt = 0;
    GameManager& gameManager;
    sf::RenderWindow& window;
    Player player;
    ProjectileManager projectileManager;
    AsteroidManager asteroidManager;
    ResourceManager resourceManager;
    ParticleSystem particleSystem;
    std::list<sf::CircleShape> stars;
    sf::Clock clock;
    constexpr static float PI = 3.14159265f;
    GameState(sf::RenderWindow& window, GameManager& gameManager);
    void changeState(GameManager*, std::shared_ptr<GameState>);
    void handleWindowEvents();
private:
    friend class ParticleSystem;

};


#endif //ASTEROIDSSFML_GAMESTATE_H
