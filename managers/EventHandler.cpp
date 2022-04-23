//
// Created by Cole on 4/21/2022.
//

#include "EventHandler.h"


EventHandler::EventHandler(sf::RenderWindow &window) : window(window) {}


void EventHandler::handle() {
    sf::Event event{};
    window.pollEvent(event);

    if(event.key.code == sf::Keyboard::Escape) {
        window.close();
    }

}

//EventHandler *EventHandler::Instance(sf::RenderWindow &window) {
//    static EventHandler* self;
//    if(self == nullptr) {
//        self = new EventHandler(window);
//    }
//    return self;
//}
