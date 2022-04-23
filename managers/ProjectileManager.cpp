//
// Created by Cole on 4/22/2022.
//

#include "../Player.h"
#include "ProjectileManager.h"
#include "ResourceManager.h"

ProjectileManager::ProjectileManager() = default;

ProjectileManager *ProjectileManager::Instance() {
    static ProjectileManager* self;
    if(self == nullptr) {
        self = new ProjectileManager;
    }
    return self;
}

void ProjectileManager::spawnProjectile(Player* player) {
    sf::CircleShape projectile(2.5f);
    projectile.setPosition(player->getTransform().transformPoint(player->getPoint(0)));
    projectile.setRotation(player->getRotation());
    projectiles.push_back(projectile);
}




