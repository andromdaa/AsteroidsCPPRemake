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
    static ProjectileManager* Instance();
    void drawAll(sf::RenderWindow& window);
    void draw(sf::RenderWindow&, sf::CircleShape& projectile);
private:
    explicit ProjectileManager();
    constexpr static float PROJECTILE_SPEED = 600.f;
    friend class PlayingState;
    friend class EventHandler;
    friend class GameManager;
    std::list<sf::CircleShape> projectiles;
    void spawnProjectile(Player* player);
};

#endif //ASTEROIDSSFML_PROJECTILEMANAGER_H
