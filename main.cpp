#include "GameManager.h"
int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    GameManager gameManger(settings);
    gameManger.transitionState();

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
 * Start screen - log player positions and asteroid positions to file and have BeginState emulate that
 * Health System
 * Starry Background
 * Smooth asteroid movement/rotation (perlin noise?)
 * Break larger asteroids into smaller when destroyed
 * Progressive rotation speed
 */