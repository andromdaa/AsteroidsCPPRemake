#include <SFML/System/Clock.hpp>
#include <iostream>
#include "util/Util.h"

int main() {
    sf::Clock clock;
    double t = 0.0;
    const double dt = 0.01;

    double currentTime = clock.getElapsedTime().asSeconds();
    double accumulator = 0.0;

    while (Util::gameInstance()->getWindow().isOpen()) {
        double newTime = clock.getElapsedTime().asSeconds();
        double frameTime = newTime - currentTime;
        if(frameTime > 0.25) {
            frameTime = 0.25;
        }
        currentTime = newTime;

        accumulator += frameTime;

        while (accumulator >= dt) {
            //game loop
            Util::gameInstance()->update(dt);
            Util::gameInstance()->tickState();

            t += dt;
            accumulator -= dt;
        }

        //handle all events / state triggers
        Util::gameInstance()->getWindow().clear();

        Util::gameInstance()->renderState();

        Util::gameInstance()->getWindow().display();
    }
        return 0;
}