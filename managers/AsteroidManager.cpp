//
// Created by Cole on 4/22/2022.
//

#include <random>
#include <chrono>
#include "AsteroidManager.h"
#include "../states/ActiveState.h"


AsteroidManager::AsteroidManager(GameState& gameState) : gameState(gameState) {}

void AsteroidManager::createAsteroids() {
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<float> xDistribution(10, GameState::getWidth() - 9);
    std::uniform_real_distribution<float> yDistribution(10, GameState::getHeight() - 9);
    std::uniform_real_distribution<float> angleDistribution(0, 360);

    sf::ConvexShape shape;
    shape.setOutlineThickness(1.5);
    shape.setOutlineColor(sf::Color::White);
    shape.setFillColor(sf::Color::Transparent);
    shape.setPointCount(6);
    shape.setPoint(0, sf::Vector2f(10, 0));
    shape.setPoint(1, sf::Vector2f(40, 10));
    shape.setPoint(2, sf::Vector2f(45, 50));
    shape.setPoint(3, sf::Vector2f(7, 53));
    shape.setPoint(4, sf::Vector2f(0, 40));
    shape.setPoint(5, sf::Vector2f(4, 10));

    for(int i = (int) asteroids.size(); i < MAX_ASTEROIDS; i++) {
        auto size = Sizes(rand() % 3);
        float x = xDistribution(generator);
        float y = yDistribution(generator);
        if (size == Sizes::SM) shape.setScale(0.5f, 0.5f);
        else if (size == Sizes::MED) shape.setScale(0.75f, 0.75f);
        else if (size == Sizes::LRG) shape.setScale(1.f, 1.f);
        if(ActiveState::locationAllowed(x, y, sf::Vector2f(), 0)) shape.setPosition(x, y);
        shape.setRotation(angleDistribution(generator));
        auto bounds = shape.getLocalBounds();
        shape.setOrigin(bounds.width / 2, bounds.height / 2);
        asteroids.push_back(shape);
    }
}

void AsteroidManager::drawAll(sf::RenderWindow &window) {
    for(const auto& asteroid : asteroids) {
        window.draw(asteroid);
    }
}

//std::list<sf::ConvexShape> &AsteroidManager::getAsteroids() {
//    return asteroids;
//}
