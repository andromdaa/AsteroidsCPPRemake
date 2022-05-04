//
// Created by Cole on 4/22/2022.
//

#include <random>
#include <chrono>
#include <iostream>
#include "AsteroidManager.h"
#include "../states/ActiveState.h"
#include "../GameManager.h"
#include "../util/Util.h"

AsteroidManager::AsteroidManager(GameManager& gameManager) : gameManager(gameManager), perlinNoise(std::chrono::system_clock::now().time_since_epoch().count()) {
}

void AsteroidManager::createAsteroids() {
    if(asteroids.size() >= 10) return;
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<float> xDistribution(10, GameManager::getWidth() - 9);
    std::uniform_real_distribution<float> yDistribution(10, GameManager::getHeight() - 9);
    std::uniform_real_distribution<float> angleDistribution(0, 360);

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1,50000); // distribution in range [1, 6]


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
        if(!Util::intersectsPlayer(gameManager.getPlayer(), 6, Util::getTransformX(shape).get(), Util::getTransformY(shape).get())) {
            asteroids.push_back(shape);
            seeds.push_back(dist(rng));
        }
    }
}

void AsteroidManager::tick() {
    createAsteroids();
}

void AsteroidManager::drawAll(sf::RenderWindow &window) {
    auto aIt = asteroids.begin(); //transition into getter
    int i = 0;

    for(auto& asteroid : asteroids) {
        perlinNoise.reseed(seeds[i++]);

        auto view = window.getViewport(window.getView());
        view.width += 25;
        view.height += 25;
        if(!view.contains(static_cast<const sf::Vector2<int>>(asteroid.getPosition()))) {
            asteroids.erase(aIt++);
            continue;
        }


        auto delta = gameManager.getDelta();
        auto xOffset = perlinNoise.noise1D(tx / 2);
        auto yOffset = perlinNoise.noise1D(ty / 2);

        asteroid.move(xOffset * delta, yOffset * delta);
        window.draw(asteroid);

        aIt++;
    }
    tx += 0.00001;
    ty += 0.00001;
}

void AsteroidManager::reset() {
    asteroids.clear();
    createAsteroids();
}

void AsteroidManager::decreaseMaxAsteroids() {
    MAX_ASTEROIDS--;
}

bool AsteroidManager::asteroidsRemaining() {
    return !asteroids.empty();
}

