#include "GameManager.h"
int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    GameManager gameManger(settings);
    GameManager::resourceManager->startMusic();
    GameManager::asteroidHandler->createAsteroids();

    while(gameManger.window.isOpen()) {
        //handle all events / state triggers
        gameManger.tick();
        gameManger.eventHandler.handle();
        gameManger.player.processInput(&gameManger.player);

        gameManger.window.clear();
        gameManger.window.draw(gameManger.player);

        GameManager::projectileHandler->drawAll(gameManger.window);
        GameManager::asteroidHandler->drawAll(gameManger.window);

        gameManger.window.display();
    }

    return 0;
}

/*
 * TODO:
 * Health System
 * Starry Background
 * Smooth asteroid movement/rotation (perlin noise?)
 * Break larger asteroids into smaller when destroyed
 */