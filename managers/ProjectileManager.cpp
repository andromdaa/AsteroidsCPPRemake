//
// Created by Cole on 4/22/2022.
//

#include "ProjectileManager.h"
#include "../states/ActiveState.h"
#include "../util/Util.h"

ProjectileManager::ProjectileManager(GameState& gameState) : gameState(gameState){}

void ProjectileManager::draw(sf::RenderWindow& window, sf::CircleShape& projectile) {
    sf::Vector2f speed = ActiveState::getMovement(projectile, PROJECTILE_SPEED, gameState.getDelta());
    if(ActiveState::locationAllowed(projectile.getPosition().x, projectile.getPosition().y, speed, projectile.getRadius())) {
        projectile.move(speed.x, speed.y);
        window.draw(projectile);
    }
}

void ProjectileManager::spawnProjectile(Player& player) {
    sf::CircleShape projectile(2.5f);
    projectile.setPosition(player.getTransform().transformPoint(player.getPoint(0)));
    projectile.setRotation(player.getRotation());
    projectiles.push_back(projectile);
}

void ProjectileManager::drawAll(sf::RenderWindow& window) {
    int scoreInc = Util::removeCollisions(gameState.getProjectileManager(), gameState.getAsteroidManager());
    gameState.getResourceManager().updateScore(scoreInc, window);
    for(sf::CircleShape& projectile : projectiles) {
        draw(window, projectile);
    }
}

std::list<sf::CircleShape>& ProjectileManager::getProjectiles() {
    return projectiles;
}

