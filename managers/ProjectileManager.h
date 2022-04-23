//
// Created by Cole on 4/22/2022.
//

#ifndef ASTEROIDSSFML_PROJECTILEMANAGER_H
#define ASTEROIDSSFML_PROJECTILEMANAGER_H

#include <list>
#include <SFML/Graphics.hpp>

class Player;
class ProjectileManager {
public:
    static ProjectileManager* Instance();
    void update();
    ProjectileManager();
private:
    friend class PlayingState;
    std::list<sf::CircleShape> projectiles;
    void spawnProjectile(Player* player);
};

#endif //ASTEROIDSSFML_PROJECTILEMANAGER_H
