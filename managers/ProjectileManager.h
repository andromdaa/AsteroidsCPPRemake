//
// Created by Cole on 4/22/2022.
//

#ifndef ASTEROIDSSFML_PROJECTILEMANAGER_H
#define ASTEROIDSSFML_PROJECTILEMANAGER_H

#include <list>
#include <SFML/Graphics.hpp>

class Player;
class GameManager;
class ProjectileManager {
public:
    explicit ProjectileManager(GameManager& gameState);
    void drawAll(sf::RenderWindow& window);
    void draw(sf::RenderWindow&, sf::CircleShape& projectile);
    void spawnProjectile(Player& player);
    std::list<sf::CircleShape>& getProjectiles();
    void reset();
private:
    friend class Util;
    GameManager& gameManager;
    constexpr static float PROJECTILE_SPEED = 40.f;
    std::list<sf::CircleShape> projectiles;
};

#endif //ASTEROIDSSFML_PROJECTILEMANAGER_H
