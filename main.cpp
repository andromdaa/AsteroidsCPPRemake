#include <iostream>
#include <valarray>
#include "GameManager.h"

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    GameManager gameManger(settings, false);

    sf::Clock clock;
    double t = 0.0;
    const double dt = 0.01;

    double currentTime = clock.getElapsedTime().asSeconds();
    double accumulator = 0.0;

    while (gameManger.window.isOpen()) {
        double newTime = clock.getElapsedTime().asSeconds();
        double frameTime = newTime - currentTime;
        currentTime = newTime;

        accumulator += frameTime;

        while (accumulator >= dt) {
            //game loop
            gameManger.update(dt);
            gameManger.tickState();

            accumulator -= dt;
            t += dt;
        }



        //handle all events / state triggers
        gameManger.window.clear();

        gameManger.renderState();

        gameManger.window.display();
//    }
    }
        return 0;
}

/*
 * TODO:
 * Fix rotation speed and movement speed due to fixed game loop implementation
 * In order to fix sine wave jumpiness - use fixed game loop
 * Starry Background
 * Start screen - log player positions and asteroid positions to file and have BeginState emulate that
 * Add rocket tail when activated
 * Health System
 * Smooth asteroid movement/rotation (perlin noise?)
 * Break larger asteroids into smaller when destroyed
 * Progressive rotation speed
 * Fix when player presses space it sends a projectile and transitions state. Only transition state.
 */