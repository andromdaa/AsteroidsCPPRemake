//
// Created by Cole on 4/23/2022.
//

#include "BeginState.h"
#include "ActiveState.h"
#include "../GameManager.h"
#include <cmath>
#include <random>
#include <chrono>

BeginState::BeginState(sf::RenderWindow &window, GameManager& gameManager) : GameState(window, gameManager) {
    resourceManager.text.setString("Press any key to begin!");
    resourceManager.text.setCharacterSize(24);
    resourceManager.text.setOrigin(resourceManager.text.getLocalBounds().width / 2, resourceManager.text.getLocalBounds().height / 2 );
    resourceManager.text.setPosition((uint16_t) (window.getSize().x / 2), (uint16_t) (window.getSize().y / 2));
    if(gameManager.enableAudio) resourceManager.startMusic();
    generateStars();
    spawnText();
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

void BeginState::renderState() {
    drawStars();
    spawnText();
//    updateText();
}

void BeginState::tickState() {
    handleEvents();
}

void BeginState::handleEvents() {
    sf::Event event{};
    window.pollEvent(event);

    if(event.key.code == sf::Keyboard::Escape && window.hasFocus()) {
        window.close();
    }

    if(event.type == sf::Event::KeyPressed) {
        transitionState(&gameManager);
    }
}

void BeginState::updateText() {
    for(int i = 0; i <= beginText.size(); i++) {
        auto offset = beginText[i % beginText.size()].getPosition().y - beginText[(i + 1) % beginText.size()].getPosition().y;
        drawText(beginText[i % beginText.size()], offset);
    }
}

void BeginState::drawText(sf::Text& text, float offset) {
    text.move(0, offset * dt);
    window.draw(text);
}

void BeginState::spawnText() {
    for(auto & i : chars) {
        sf::Text text;
        text.setString(i);
        text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().width / 2);
        text.setPosition(window.getSize().x / 2, window.getSize().y / 2);
//        beginText.push_back(text);
        window.draw(text);
    }
}

void BeginState::generateStars() {
    //(move)? stars based on what direction that player is facing
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<float> xDistribution(10, (float) getWidth() - 10);
    std::uniform_real_distribution<float> yDistribution(10, (float) getHeight() - 10);
    std::uniform_real_distribution<float> sizeDistribution(1, 3);


    for(int i = 0; i < MAX_STARS; i++) {
        sf::CircleShape star(sizeDistribution(generator));
        star.setOrigin(star.getRadius(), star.getRadius());
        star.setPosition(xDistribution(generator), yDistribution(generator));
        stars.push_back(star);
    }
}

void BeginState::drawStars() {
    auto sIt = stars.begin();
    while(sIt != stars.end()) {
        window.draw(*sIt);
        sIt++;
    }
}




