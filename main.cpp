#include "GameManager.h"
#include <SFML/System.hpp>
int main() {
    GameManager gameManger;
//    GameManager::resourceManager->startMusic();
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

