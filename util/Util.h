//
// Created by Cole on 4/25/2022.
//

#ifndef ASTEROIDSSFML_UTIL_H
#define ASTEROIDSSFML_UTIL_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "../GameManager.h"
#include "../managers/ProjectileManager.h"
#include "../managers/AsteroidManager.h"


class Util {
public:
    static std::shared_ptr<GameManager> gameInstance();
    static std::shared_ptr<GameManager> createGameManager();
    static void resetGame();
    static int removeCollisions(ProjectileManager &projectileManagerL, AsteroidManager &asteroidManagerL);
    static int checkIntersect(int nvert, const float *vertx, const float *verty, float testx, float testy);
    static bool checkPlayerCollision(Player &player, AsteroidManager &asteroidManager);
    static std::unique_ptr<float[]> getTransformY(sf::ConvexShape& asteroid);
    static std::unique_ptr<float[]> getTransformX(sf::ConvexShape &asteroid);

    static bool intersectsPlayer(Player &player, int nvert, float *x, float *y);
};

#endif //ASTEROIDSSFML_UTIL_H
