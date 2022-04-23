#include "GameManager.h"

int main() {
    GameManager gameManger;
    GameManager::resourceManager->startMusic();
    GameManager::asteroidHandler->createAsteroids();

    while(gameManger.window.isOpen()) {
        //handle all events / state triggers
        gameManger.tick();
        gameManger.eventHandler.handle();
        gameManger.player.processInput(&gameManger.player);

        //draw stuff
//        gameManger.removeCollisions();

        gameManger.window.clear();

        gameManger.window.draw(gameManger.player);


        GameManager::projectileHandler->drawAll(gameManger.window);
        GameManager::asteroidHandler->drawAll(gameManger.window);


        gameManger.window.display();
    }


    return 0;
}

//    spawnCollide(window.getSize().x, window.getSize().y);
//    while (window.isOpen()) {
//        time = deltaClock.restart();
//        args.dt = time.asSeconds();
//
//        //event polling, to update what is to be rendered next
//        pollEvents(args, player, sound);
//
//        //render things
//        window.clear();
//        window.draw(score);
//        window.draw(player);
//

//
//        window.display();
//    }

