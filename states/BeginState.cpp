//
// Created by Cole on 4/23/2022.
//

#include "BeginState.h"
#include "ActiveState.h"
#include "../GameManager.h"

BeginState::BeginState(sf::RenderWindow &window, GameManager& gameManager) : GameState(window, gameManager) {
//    resourceManager.startMusic();
}

BeginState *BeginState::Instance(sf::RenderWindow &window, GameManager& gameManager) {
    static BeginState* self;
    if(self == nullptr) {
        self = new BeginState(window, gameManager);
    }
    return self;
}

void BeginState::transitionState(GameManager *g) {
    changeState(g, ActiveState::Instance(window, gameManager));
}

void BeginState::tickState() {
    handleEvents();
//    resourceManager.beginPlayingText();
}

void BeginState::handleEvents() {
    sf::Event event{};
//    window.pollEvent(event);

    if(event.key.code == sf::Keyboard::Escape) {
//        window.close();
    }

    if(event.type == sf::Event::KeyPressed) {
//        transitionState(gameManager);
    }
}



/* Undirected graph, the value function is the movement required
 *
 */



