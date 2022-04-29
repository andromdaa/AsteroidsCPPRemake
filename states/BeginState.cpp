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
    GameState::renderState();
    drawStars();
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

    if(event.key.code == sf::Keyboard::Escape && window.hasFocus()) {
        window.close();
    }

    if(event.type == sf::Event::KeyPressed) {
        transitionState(&gameManager);
    }
}

void BeginState::updateText() {
    for(int i = 0; i < beginText.size(); i++) {
        auto& text = beginText[i];
        text.move(0, sineValues[(i + iteration) % sineValues.size()]);
    }
    iteration++;
}

void BeginState::drawText() {
    for(auto& text : beginText) {
        window.draw(text);
    }
}

void BeginState::spawnText() {
    for(int i = 0; i < 20; i++) {
        sf::Text text;
        text.setFont(resourceManager.font);
        text.setString(chars[i]);
        text.setOrigin(static_cast<int>(text.getLocalBounds().width / 2.f), static_cast<int>(text.getLocalBounds().width / 2));
        int xSize = static_cast<int>(std::floor(100.f + (text.getCharacterSize() * i)));
        int ySize = static_cast<int>(std::floor(window.getSize().y / 2.f));
        text.setPosition(xSize, ySize);
        beginText.push_back(text);
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




