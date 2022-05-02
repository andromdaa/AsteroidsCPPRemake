//
// Created by Cole on 4/22/2022.
//

#ifndef ASTEROIDSSFML_ASTEROIDMANAGER_H
#define ASTEROIDSSFML_ASTEROIDMANAGER_H

#include <SFML/Graphics.hpp>
#include <list>

class GameManager;
class AsteroidManager {
public:
    explicit AsteroidManager(GameManager& gameState);
    void drawAll(sf::RenderWindow& window);
    void createAsteroids();
    void reset();
private:
    friend class Util;
    GameManager& gameManager;
    enum Sizes { SM, MED, LRG };
    const int MAX_ASTEROIDS = 10;
    std::list<sf::ConvexShape> asteroids;
};




#endif //ASTEROIDSSFML_ASTEROIDMANAGER_H
