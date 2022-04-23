//
// Created by Cole on 4/22/2022.
//

#ifndef ASTEROIDSSFML_GAMEMANAGER_H
#define ASTEROIDSSFML_GAMEMANAGER_H


#include "Player.h"
#include "managers/EventHandler.h"
#include "managers/ResourceManager.h"
#include "managers/AsteroidManager.h"
#include "managers/ProjectileManager.h"

class GameManager {
public:
    GameManager();
    void tick();
    inline static float dt = 0;
    sf::RenderWindow window;
    Player player;
    EventHandler eventHandler;
    inline static ProjectileManager* projectileHandler = ProjectileManager::Instance();
    inline static AsteroidManager* asteroidHandler = AsteroidManager::Instance();
    inline static ResourceManager* resourceManager = ResourceManager::Instance();
private:
    static sf::Vector2f getMovement(const sf::Shape& shape, float speed);
    static bool locationAllowed(float x, float y, sf::Vector2f movementInc, float radius);
    sf::Clock clock;
    const static int WIDTH = 800;
    const static int HEIGHT = 600;
    constexpr static float ROTATION_SPEED = 0.005f;
    constexpr static float PROJECTILE_SPEED = 600.f;
    constexpr static float PI = 3.14159265f;
    constexpr static float UPPER_ROTATION_BOUND = .1f;
    constexpr static float LOWER_ROTATION_BOUND = -.1f;
    constexpr static float LOWER_SPEED_BOUND = -100.f;
    const static unsigned short UPPER_SPEED_BOUND = 500;
    const static char MAX_ALLOWED_COLLIDABLES = 10;
    friend class PlayingState;
    friend class ResourceManager;
    friend class ProjectileManager;
    friend class Player;
    friend class EventHandler;
    friend class AsteroidManager;
};


#endif //ASTEROIDSSFML_GAMEMANAGER_H
