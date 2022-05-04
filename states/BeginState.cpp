//
// Created by Cole on 4/23/2022.
//

#include "BeginState.h"
#include "ActiveState.h"
#include "../GameManager.h"
#include <cmath>
#include <random>
#include <chrono>
#include "../util/Util.h"

BeginState::BeginState(sf::RenderWindow &window, GameManager &gameManager) : GameState(window, gameManager),
                                                                             window(window) {
    if (gameManager.getEnableAudio()) gameManager.getResourceManager().startMusic();
    spawnText();
}

std::shared_ptr<BeginState> BeginState::Instance(sf::RenderWindow &window, GameManager &gameManager) {
    static std::shared_ptr<BeginState> self;
    if (self == nullptr) {
        auto p = new BeginState(window, gameManager);
        self = std::shared_ptr<BeginState>(p);
    }
    return self;
}

void BeginState::transitionState(GameManager *g) {
    changeState(g, ActiveState::Instance(gameManager.getWindow(), gameManager));
}

void BeginState::renderState() {
    GameState::renderState();
    drawText();
}

void BeginState::tickState() {
    handleEvents();
    updateText();
    GameState::tickState();
}

void BeginState::handleEvents() {
    sf::Event event{};
    window.pollEvent(event);

    if (event.key.code == sf::Keyboard::Escape && window.hasFocus()) {
        window.close();
    }

    if (event.type == sf::Event::KeyPressed) {
        transitionState(&gameManager);
    }
}

void BeginState::updateText() {
    for (int i = 0; i < beginText.size(); i++) {
        auto &text = beginText[i];
        text.move(0, sineValues[(i + iteration) % sineValues.size()]);
    }
    iteration++;
}

void BeginState::drawText() {
    for (auto &text: beginText) {
        window.draw(text);
    }
}

void BeginState::spawnText() {
    for (int i = 0; i < 20; i++) {
        sf::Text text;
        text.setFont(gameManager.getResourceManager().font);
        text.setString(chars[i]);
        text.setOrigin(static_cast<int>(text.getLocalBounds().width / 2.f),
                       static_cast<int>(text.getLocalBounds().width / 2));
        int xSize = static_cast<int>(std::floor(100.f + (text.getCharacterSize() * i)));
        int ySize = static_cast<int>(std::floor(window.getSize().y / 2.f));
        text.setPosition(xSize, ySize);
        beginText.push_back(text);
    }
}






