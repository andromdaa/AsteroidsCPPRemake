#include <SFML/System/Clock.hpp>
#include <iostream>
#include <chrono>
#include "util/Util.h"

int main() {
//    siv::PerlinNoise noise(std::chrono::system_clock::now().time_since_epoch().count());
//
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Walker");
//
//    sf::CircleShape circle(2.5);
//    circle.setPosition(window.getSize().x / 2, window.getSize().y / 2);
//
//    while(window.isOpen()) {
//        sf::Event event{};
//        window.pollEvent(event);
//
//        if(event.key.code == sf::Keyboard::Escape) window.close();
////        auto yOff = noise.noise2D(x / 10, y / 10);
//
//
//
//        window.display();
//
//    }




    sf::Clock clock;
    double t = 0.0;
    const double dt = 0.01;

    double currentTime = clock.getElapsedTime().asSeconds();
    double accumulator = 0.0;

    while (Util::gameInstance()->getWindow().isOpen()) {
        double newTime = clock.getElapsedTime().asSeconds();
        double frameTime = newTime - currentTime;
        if(frameTime > 0.25) {
            frameTime = 0.25;
        }
        currentTime = newTime;

        accumulator += frameTime;

        while (accumulator >= dt) {
            //game loop
            Util::gameInstance()->update(dt);
            Util::gameInstance()->tickState();

            t += dt;
            accumulator -= dt;
        }

        //handle all events / state triggers
        Util::gameInstance()->getWindow().clear();

        Util::gameInstance()->renderState();

        Util::gameInstance()->getWindow().display();
    }
        return 0;
}

/*
 * TODO:
 * Smooth asteroid movement/rotation (perlin noise?)
 * Break larger asteroids into smaller when destroyed
 */