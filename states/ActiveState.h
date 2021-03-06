//
// Created by Cole on 4/21/2022.
//

#ifndef ASTEROIDSSFML_ACTIVESTATE_H
#define ASTEROIDSSFML_ACTIVESTATE_H

#include "GameState.h"


class Player;
class AsteroidManager;
class ProjectileManager;
class ResourceManager;

class ActiveState : public GameState {
public:
    static std::shared_ptr<ActiveState> Instance(sf::RenderWindow& window, GameManager& gameManager);
    void transitionState(GameManager* g) override;
    void handleInput();
    void tickState() override;
    void renderState() override;
    void handleEvents();
    static sf::Vector2f getMovement(const sf::Shape& shape, float speed, double dt);
    static bool locationAllowed(float x, float y, sf::Vector2f movementInc, float radius);
    void reset();
private:
    Player& player;
    AsteroidManager& asteroidManager;
    ProjectileManager& projectileManager;
    ResourceManager& resourceManager;
    sf::RenderWindow& window;
    inline static bool isActive = false;
    explicit ActiveState(sf::RenderWindow &window, GameManager& gameManager);

    bool locationAllowed(sf::ConvexShape &shape);
};


#endif //ASTEROIDSSFML_ACTIVESTATE_H
