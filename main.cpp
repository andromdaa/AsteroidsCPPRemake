#include <iostream>
#include <SFML/System/Clock.hpp>
#include "util/Util.h"
#include "GameManager.h"

int main() {
    sf::Clock clock;
    double t = 0.0;
    const double dt = 0.01;

    double currentTime = clock.getElapsedTime().asSeconds();
    double accumulator = 0.0;

    while (Util::gameInstance()->window->isOpen()) {
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
        Util::gameInstance()->window->clear();

        Util::gameInstance()->renderState();

        Util::gameInstance()->window->display();
    }
        return 0;
}
/*
 * TODO:
 * Should be able to access window from GameState in all state classes
 * Start screen - log player positions and asteroid positions to file and have BeginState emulate that
 * Smooth asteroid movement/rotation (perlin noise?)
 * Break larger asteroids into smaller when destroyed
 * Progressive rotation speed
 */