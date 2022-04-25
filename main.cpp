#include "GameManager.h"
int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    GameManager gameManger(settings, false);

    gameManger.tick();

    while(gameManger.window.isOpen()) {
        //handle all events / state triggers
        gameManger.tick();

        gameManger.window.clear();

        gameManger.tickState();

        gameManger.window.display();
    }

    return 0;
}

/*
 * TODO:
 * Starry Background
 * Start screen - log player positions and asteroid positions to file and have BeginState emulate that
 * Add rocket tail when activated
 * Health System
 * Smooth asteroid movement/rotation (perlin noise?)
 * Break larger asteroids into smaller when destroyed
 * Progressive rotation speed
 * Fix when player presses space it sends a projectile and transitions state. Only transition state.
 */