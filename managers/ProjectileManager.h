//
// Created by Cole on 4/22/2022.
//

#ifndef ASTEROIDSSFML_PROJECTILEMANAGER_H
#define ASTEROIDSSFML_PROJECTILEMANAGER_H

#include <list>
#include <SFML/Graphics.hpp>

class Player;
class GameState;
class ProjectileManager {
public:
    explicit ProjectileManager(GameState& gameState);
    void drawAll(sf::RenderWindow& window);
    void draw(sf::RenderWindow&, sf::CircleShape& projectile);
    void spawnProjectile(Player& player);
    std::list<sf::CircleShape>& getProjectiles();
private:
    friend class Util;
    GameState& gameState;
    constexpr static float PROJECTILE_SPEED = 40.f;
    std::list<sf::CircleShape> projectiles;
};

#endif //ASTEROIDSSFML_PROJECTILEMANAGER_H
