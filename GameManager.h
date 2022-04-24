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
    explicit GameManager(sf::ContextSettings& settings);
    void tick();
    sf::RenderWindow window;
    Player player;
    EventHandler eventHandler;
    inline static AsteroidManager* asteroidHandler = AsteroidManager::Instance();
    inline static ProjectileManager* projectileHandler = ProjectileManager::Instance();
    inline static ResourceManager* resourceManager = ResourceManager::Instance();
    static sf::Vector2f getMovement(const sf::Shape& shape, float speed);
    static int removeCollisions();
private:
    inline static float dt = 0;
    static bool locationAllowed(float x, float y, sf::Vector2f movementInc, float radius);
    sf::Clock clock;
    const static int WIDTH = 800;
    const static int HEIGHT = 600;
    constexpr static float PI = 3.14159265f;
    friend class PlayingState;
    friend class ResourceManager;
    friend class ProjectileManager;
    friend class Player;
    friend class EventHandler;
    friend class AsteroidManager;
};


#endif //ASTEROIDSSFML_GAMEMANAGER_H
