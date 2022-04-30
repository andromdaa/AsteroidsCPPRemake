//
// Created by Cole on 4/23/2022.
//

#include "EndState.h"

EndState *EndState::Instance(sf::RenderWindow& window, GameManager& gameManager) {
    static EndState* self;
    if(self == nullptr) {
        self = new EndState(window, gameManager);
    }
    return self;
}

EndState::EndState(sf::RenderWindow& window, GameManager& gameManager) :
    GameState(window, gameManager),
    gameOverText("Game Over!", resourceManager.font, 30),
    finalScoreText(std::to_string(GameState::score), resourceManager.font, 24)
{
    gameOverText.setOrigin(gameOverText.getLocalBounds().width / 2.f, gameOverText.getLocalBounds().height);
    gameOverText.setPosition(GameState::getWidth() / 2.f, GameState::getHeight() / 2.f);
    finalScoreText.setPosition(gameOverText.getPosition());
    finalScoreText.move(0, 20);
    resourceManager.playGameOver();
    clock.restart();
}

void EndState::tickState() {
    sf::Event event{};
    window.pollEvent(event);

    if (event.key.code == sf::Keyboard::Escape) {
        window.close();
    }

//    auto elapsedTime = -clock.getElapsedTime().asSeconds();
//    if(elapsedTime < sf::Time().Zero) resourceManager.startMusic();

    GameState::tickState();
}

void EndState::update(double dt) {

}

void EndState::renderState() {
    window.draw(gameOverText);
    window.draw(finalScoreText);
}