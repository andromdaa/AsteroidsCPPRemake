//
// Created by Cole on 4/21/2022.
//

#include "EventHandler.h"

void EventHandler::handle(sf::RenderWindow& window) {
    sf::Event event{};
    window.pollEvent(event);

    if(event.key.code == sf::Keyboard::Escape) {
        window.close();
    }
}
