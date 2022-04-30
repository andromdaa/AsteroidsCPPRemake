//
// Created by Cole on 4/25/2022.
//

#ifndef ASTEROIDSSFML_UTIL_H
#define ASTEROIDSSFML_UTIL_H

#include <iostream>
#include "../Player.h"

class ProjectileManager;
class AsteroidManager;
class Util {
public:
    static int removeCollisions(ProjectileManager &projectileManagerL, AsteroidManager &asteroidManagerL);
    static int checkIntersect(int nvert, const float *vertx, const float *verty, float testx, float testy);

    static bool checkPlayerCollision(Player &player, AsteroidManager &asteroidManager);
};

#endif //ASTEROIDSSFML_UTIL_H
