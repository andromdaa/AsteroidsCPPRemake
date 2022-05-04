//
// Created by Cole on 4/25/2022.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Util.h"
#include "../states/ActiveState.h"


int Util::removeCollisions(ProjectileManager& projectileManagerL, AsteroidManager& asteroidManagerL) {
    int scoreInc = 0;
    auto pIt = projectileManagerL.projectiles.begin(); //transition into getter
    auto aIt = asteroidManagerL.asteroids.begin(); //transition into getter
    auto sIt = asteroidManagerL.seeds.begin();

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
                asteroidManagerL.seeds.erase(sIt++);
                asteroidManagerL.decreaseMaxAsteroids();
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

bool Util::intersectsPlayer(Player& player, int nvert, float* x, float* y) {
    int intersect1 = checkIntersect(nvert, x, y, player.getTransform().transformPoint(player.getPoint(0)).x,
                   player.getTransform().transformPoint(player.getPoint(0)).y);
    int intersect2 = checkIntersect(nvert, x, y, player.getTransform().transformPoint(player.getPoint(1)).x,
                                  player.getTransform().transformPoint(player.getPoint(1)).y);
    int intersect3 = checkIntersect(nvert, x, y, player.getTransform().transformPoint(player.getPoint(2)).x,
                                    player.getTransform().transformPoint(player.getPoint(2)).y);

    return (intersect1 || intersect2) || intersect3;

}

bool Util::checkPlayerCollision(Player& player, AsteroidManager& asteroidManager) {
    auto aIt = asteroidManager.asteroids.begin(); //transition into getter

    for(int j = 0; j < asteroidManager.asteroids.size(); j++) {
        if(aIt == asteroidManager.asteroids.end()) break;
        auto asteroid = std::next(aIt, j);

        std::unique_ptr<float[]> x = getTransformX(*asteroid);
        std::unique_ptr<float[]> y = getTransformY(*asteroid);

        bool intersect = intersectsPlayer(player, 6, x.get(), y.get());
        if(intersect) return true;
    }

    return false;
}

std::shared_ptr<GameManager> Util::createGameManager() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    auto p = new GameManager(settings, false);
    return std::unique_ptr<GameManager>(p);
}

std::unique_ptr<float[]> Util::getTransformY(sf::ConvexShape& asteroid) {
    std::unique_ptr<float[]> y(new float[6]);
    y[0] = asteroid.getTransform().transformPoint(asteroid.getPoint(0)).y;
    y[1] = asteroid.getTransform().transformPoint(asteroid.getPoint(1)).y;
    y[2] = asteroid.getTransform().transformPoint(asteroid.getPoint(2)).y;
    y[3] = asteroid.getTransform().transformPoint(asteroid.getPoint(3)).y;
    y[4] = asteroid.getTransform().transformPoint(asteroid.getPoint(4)).y;
    y[5] = asteroid.getTransform().transformPoint(asteroid.getPoint(5)).y;
    return y;
}

std::unique_ptr<float[]> Util::getTransformX(sf::ConvexShape& asteroid) {
    std::unique_ptr<float[]> x(new float[6]);
    x[0] = asteroid.getTransform().transformPoint(asteroid.getPoint(0)).x;
    x[1] = asteroid.getTransform().transformPoint(asteroid.getPoint(1)).x;
    x[2] = asteroid.getTransform().transformPoint(asteroid.getPoint(2)).x;
    x[3] = asteroid.getTransform().transformPoint(asteroid.getPoint(3)).x;
    x[4] = asteroid.getTransform().transformPoint(asteroid.getPoint(4)).x;
    x[5] = asteroid.getTransform().transformPoint(asteroid.getPoint(5)).x;
    return x;
}


//std::shared_ptr<GameManager> Util::createGameManager(const std::shared_ptr<sf::RenderWindow>& window) {
//    sf::ContextSettings settings;
//    settings.antialiasingLevel = 8;
//    auto p = new GameManager(settings, false, window.get());
//    return std::unique_ptr<GameManager>(p);
//}

void Util::resetGame() {
    std::shared_ptr<GameManager> instance = gameInstance();
    ActiveState::Instance(instance->getWindow(), *instance)->reset();
    instance->state = ActiveState::Instance(instance->getWindow(), *instance);
}

std::shared_ptr<GameManager> Util::gameInstance() {
    static std::shared_ptr<GameManager> self = nullptr;
    if(self  == nullptr) {
        auto p = createGameManager();
        self  = std::shared_ptr<GameManager>(p);
    }
    return self ;
}




