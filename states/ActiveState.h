//
// Created by Cole on 4/21/2022.
//

#ifndef ASTEROIDSSFML_ACTIVESTATE_H
#define ASTEROIDSSFML_ACTIVESTATE_H

#include "GameState.h"

class ActiveState : public GameState {
public:
    static ActiveState* Instance(sf::RenderWindow& window, GameManager& gameManager);
    void transitionState(GameManager* g) override;
    void handleInput();
    void tickState() override;
    void handleEvents();
    static sf::Vector2f getMovement(const sf::Shape& shape, float speed);
    static bool locationAllowed(float x, float y, sf::Vector2f movementInc, float radius);
    static int removeCollisions(ProjectileManager& projectileManagerL, AsteroidManager& asteroidManagerL);
private:
    Player player;
    explicit ActiveState(sf::RenderWindow &window, GameManager& gameManager);
    constexpr static float PI = 3.14159265f;
    static int checkIntersect(int nvert, const float *vertx, const float *verty, float testx, float testy);
};


#endif //ASTEROIDSSFML_ACTIVESTATE_H
