//
// Created by Cole on 4/25/2022.
//

#include <cmath>
#include <iostream>
#include "Util.h"
#include "../managers/ProjectileManager.h"
#include "../managers/AsteroidManager.h"

int Util::removeCollisions(ProjectileManager& projectileManagerL, AsteroidManager& asteroidManagerL) {
    int scoreInc = 0;
    auto pIt = projectileManagerL.projectiles.begin(); //transition into getter
    auto aIt = asteroidManagerL.asteroids.begin(); //transition into getter

    for(int i = 0; i < projectileManagerL.getProjectiles().size(); i++) {
        if(pIt == projectileManagerL.getProjectiles().end()) break;
        auto projectile = std::next(pIt, i);
        for(int j = 0; j < asteroidManagerL.asteroids.size(); j++) {
            if(aIt == asteroidManagerL.asteroids.end()) break;
            auto asteroid = std::next(aIt, j);
            float x[] {
                    asteroid->getTransform().transformPoint(asteroid->getPoint(0)).x,
                    asteroid->getTransform().transformPoint(asteroid->getPoint(1)).x,
                    asteroid->getTransform().transformPoint(asteroid->getPoint(2)).x,
                    asteroid->getTransform().transformPoint(asteroid->getPoint(3)).x,
                    asteroid->getTransform().transformPoint(asteroid->getPoint(4)).x,
                    asteroid->getTransform().transformPoint(asteroid->getPoint(5)).x,
            };
            float y[] = {
                    asteroid->getTransform().transformPoint(asteroid->getPoint(0)).y,
                    asteroid->getTransform().transformPoint(asteroid->getPoint(1)).y,
                    asteroid->getTransform().transformPoint(asteroid->getPoint(2)).y,
                    asteroid->getTransform().transformPoint(asteroid->getPoint(3)).y,
                    asteroid->getTransform().transformPoint(asteroid->getPoint(4)).y,
                    asteroid->getTransform().transformPoint(asteroid->getPoint(5)).y,
            };

            int intersect = checkIntersect(6, x, y,projectile->getPosition().x, projectile->getPosition().y);
            if(intersect == 1) {
                i++;
                j++;
                scoreInc += (int) (asteroid->getScale().x * 50);
                projectileManagerL.getProjectiles().erase(projectile++);
                asteroidManagerL.asteroids.erase(asteroid++);
            }
        }
    }
    return scoreInc;
}

int Util::checkIntersect(int nvert, const float *vertx, const float *verty, float testx, float testy) {
    int i, j, c = 0;
    for (i = 0, j = nvert-1; i < nvert; j = i++) {
        if ( ((verty[i]>testy) != (verty[j]>testy)) &&
             (testx < (vertx[j]-vertx[i]) * (testy-verty[i]) / (verty[j]-verty[i]) + vertx[i]) )
            c = !c;
    }
    return c;
}

bool Util::checkPlayerCollision(Player& player, AsteroidManager& asteroidManager) {
    auto aIt = asteroidManager.asteroids.begin(); //transition into getter

    for(int j = 0; j < asteroidManager.asteroids.size(); j++) {
        if(aIt == asteroidManager.asteroids.end()) break;
        auto asteroid = std::next(aIt, j);
        float x[] {
                asteroid->getTransform().transformPoint(asteroid->getPoint(0)).x,
                asteroid->getTransform().transformPoint(asteroid->getPoint(1)).x,
                asteroid->getTransform().transformPoint(asteroid->getPoint(2)).x,
                asteroid->getTransform().transformPoint(asteroid->getPoint(3)).x,
                asteroid->getTransform().transformPoint(asteroid->getPoint(4)).x,
                asteroid->getTransform().transformPoint(asteroid->getPoint(5)).x,
        };
        float y[] = {
                asteroid->getTransform().transformPoint(asteroid->getPoint(0)).y,
                asteroid->getTransform().transformPoint(asteroid->getPoint(1)).y,
                asteroid->getTransform().transformPoint(asteroid->getPoint(2)).y,
                asteroid->getTransform().transformPoint(asteroid->getPoint(3)).y,
                asteroid->getTransform().transformPoint(asteroid->getPoint(4)).y,
                asteroid->getTransform().transformPoint(asteroid->getPoint(5)).y,
        };

        int intersect1 = checkIntersect(6, x, y, player.getTransform().transformPoint(player.getPoint(0)).x,
                                        player.getTransform().transformPoint(player.getPoint(0)).y);
        int intersect2 = checkIntersect(6, x, y, player.getTransform().transformPoint(player.getPoint(1)).x,
                                        player.getTransform().transformPoint(player.getPoint(1)).y);
        int intersect3 = checkIntersect(6, x, y, player.getTransform().transformPoint(player.getPoint(2)).x,
                                        player.getTransform().transformPoint(player.getPoint(2)).y);

        bool intersect = (intersect1 || intersect2) || intersect3;
        if(intersect == 1) {
            j++;
            return true;
        }
    }
    return false;
}




