//
// Created by Cole on 4/22/2022.
//

#include "../GameManager.h"
#include <iostream>

ProjectileManager::ProjectileManager() = default;;

ProjectileManager *ProjectileManager::Instance() {
    static ProjectileManager* self;
    if(self == nullptr) {
        self = new ProjectileManager();
    }
    return self;
}

void ProjectileManager::draw(sf::RenderWindow& window, sf::CircleShape& projectile) {
    sf::Vector2f speed = GameManager::getMovement(projectile, PROJECTILE_SPEED);
    if(GameManager::locationAllowed(projectile.getPosition().x, projectile.getPosition().y, speed, projectile.getRadius())) {
        projectile.move(speed.x, speed.y);
        window.draw(projectile);
    }
}

void ProjectileManager::spawnProjectile(Player* player) {
    sf::CircleShape projectile(2.5f);
    projectile.setPosition(player->getTransform().transformPoint(player->getPoint(0)));
    projectile.setRotation(player->getRotation());
    projectiles.push_back(projectile);
}

void ProjectileManager::drawAll(sf::RenderWindow& window) {
    for(sf::CircleShape& projectile : projectiles) {
        draw(window, projectile);
    }
}




