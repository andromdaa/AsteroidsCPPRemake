//
// Created by Cole on 4/22/2022.
//

#ifndef ASTEROIDSSFML_ASTEROIDMANAGER_H
#define ASTEROIDSSFML_ASTEROIDMANAGER_H

#include <SFML/Graphics.hpp>
#include <list>


class AsteroidManager {
public:
    AsteroidManager();
    static AsteroidManager* Instance();
    void drawAll(sf::RenderWindow& window);
    void createAsteroids();
private:
    friend class GameManager;
    friend class ProjectileManager;
    enum Sizes { SM, MED, LRG };
    const int MAX_ASTEROIDS = 10;
    std::list<sf::ConvexShape> asteroids;
    static int checkIntersect(int nvert, const float *vertx, const float *verty, float testx, float testy);
};



#endif //ASTEROIDSSFML_ASTEROIDMANAGER_H
