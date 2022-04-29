#include "GameManager.h"

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    GameManager gameManger(settings, false);

    sf::Clock clock;
    double t = 0.0;
    const double dt = 0.01;

    double currentTime = clock.getElapsedTime().asSeconds();
    double accumulator = 0.0;

    while (gameManger.window.isOpen()) {
        double newTime = clock.getElapsedTime().asSeconds();
        double frameTime = newTime - currentTime;
        if(frameTime > 0.25) {
            frameTime = 0.25;
        }
        currentTime = newTime;

        accumulator += frameTime;

        while (accumulator >= dt) {
            //game loop
            gameManger.update(dt);
            gameManger.tickState();

            t += dt;
            accumulator -= dt;
        }

        //handle all events / state triggers
        gameManger.window.clear();

        gameManger.renderState();

        gameManger.window.display();
//    }
    }
        return 0;
}
//    std::ofstream sinValues;
//    sinValues.open("sinValues.txt");
//    for(int i = 0; i < 201; i++) {
//        float rads = M_PI/180;
//        double valOne = (100 * sin(1.8 * i * rads) + 300);
//        double valTwo = (100 * sin(1.8 * (i + 1) * rads) + 300);
//        double val = valOne - valTwo;
//        sinValues << val << std::endl;
//    }
//    sinValues.close();

/*
 * TODO:
 * Start screen - log player positions and asteroid positions to file and have BeginState emulate that
 * Health System
 * Smooth asteroid movement/rotation (perlin noise?)
 * Break larger asteroids into smaller when destroyed
 * Progressive rotation speed
 */