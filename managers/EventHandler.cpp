//
// Created by Cole on 4/21/2022.
//

#include "EventHandler.h"
#include "../GameManager.h"


EventHandler::EventHandler(sf::RenderWindow &window, GameManager& gameManager)
: window(window),
gameManager(gameManager) {}


void EventHandler::handle() {
    sf::Event event{};
    window.pollEvent(event);

    if(event.key.code == sf::Keyboard::Escape) {
        window.close();
    }

    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
        GameManager::projectileHandler->spawnProjectile(&gameManager.player);
//        GameManager::resourceManager->playFireSound();
    }

}

//EventHandler *EventHandler::Instance(sf::RenderWindow &window) {
//    static EventHandler* self;
//    if(self == nullptr) {
//        self = new EventHandler(window);
//    }
//    return self;
//}
