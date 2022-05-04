//
// Created by Cole on 4/22/2022.
//

#ifndef ASTEROIDSSFML_ASTEROIDMANAGER_H
#define ASTEROIDSSFML_ASTEROIDMANAGER_H

#include <SFML/Graphics.hpp>
#include <list>
#include "../util/PerlinNoise.h"

class GameManager;
class AsteroidManager {
public:
    explicit AsteroidManager(GameManager& gameState);
    void drawAll(sf::RenderWindow& window);
    void createAsteroids();
    void reset();
    void tick();
    void decreaseMaxAsteroids();
    bool asteroidsRemaining();
private:
    friend class Util;
    siv::PerlinNoise perlinNoise;
    GameManager& gameManager;
    enum Sizes { SM, MED, LRG };
    int MAX_ASTEROIDS = 10;
    std::list<sf::ConvexShape> asteroids;
    std::vector<unsigned int> seeds;
    float tx = 0.f;
    float ty = 10000.f;
};




#endif //ASTEROIDSSFML_ASTEROIDMANAGER_H
