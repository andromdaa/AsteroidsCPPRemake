//
// Created by Cole on 4/21/2022.
//

#ifndef ASTEROIDSSFML_EVENTHANDLER_H
#define ASTEROIDSSFML_EVENTHANDLER_H

#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/RenderWindow.hpp"


class EventHandler {
public:
//    static EventHandler* Instance(sf::RenderWindow &window);
    explicit EventHandler(sf::RenderWindow &window);
    void handle();
private:
    sf::RenderWindow& window;
};

#endif //ASTEROIDSSFML_EVENTHANDLER_H
