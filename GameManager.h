//
// Created by Cole on 4/22/2022.
//

#ifndef ASTEROIDSSFML_GAMEMANAGER_H
#define ASTEROIDSSFML_GAMEMANAGER_H

#include <SFML/Window/ContextSettings.hpp>
#include <memory>
#include "Player.h"
#include "managers/AsteroidManager.h"
#include "managers/ProjectileManager.h"
#include "managers/ResourceManager.h"

class ProjectileManager;
class AsteroidManager;
class ResourceManager;
class GameState;
class GameManager {
public:
    explicit GameManager(sf::ContextSettings &settings, bool enableAudio = false);
    ProjectileManager& getProjectileManager();
    AsteroidManager& getAsteroidManager();
    ResourceManager& getResourceManager();
    ParticleSystem& getParticleSystem();
    Player& getPlayer();
    void update(double dt);
    void tickState();
    void renderState();
    static int getWidth();
    static int getHeight();
    double getDelta() const;
    inline static int score = 0;
    std::shared_ptr<sf::RenderWindow> window;
    bool enableAudio = false;
    const double dt = 0.01;
    sf::Clock clock;
    void changeState(std::shared_ptr<GameState> s);
    std::shared_ptr<GameState> state;
    Player player;
    ProjectileManager projectileManager;
    AsteroidManager asteroidManager;
    ResourceManager resourceManager;
    ParticleSystem particleSystem;
    const static int WIDTH = 800;
    const static int HEIGHT = 600;

    sf::RenderWindow &getWindow();
};



#endif //ASTEROIDSSFML_GAMEMANAGER_H
