//
// Created by Cole on 4/23/2022.
//

#include "EndState.h"
#include "../util/Util.h"

std::shared_ptr<EndState> EndState::Instance(sf::RenderWindow& window, GameManager& gameManager) {
    static std::shared_ptr<EndState> self;
    if(self == nullptr) {
        auto p = new EndState(window, gameManager);
        self = std::shared_ptr<EndState>(p);
    }
    return self;
}

EndState::EndState(sf::RenderWindow& window, GameManager& gameManager) :
    GameState(window, gameManager),
    gameOverText("Game Over!", gameManager.getResourceManager().font, 30),
    finalScoreText(std::to_string(GameManager::score), gameManager.getResourceManager().font, 24)
{
    gameOverText.setOrigin(gameOverText.getLocalBounds().width / 2.f, gameOverText.getLocalBounds().height);
    gameOverText.setPosition(GameManager::getWidth() / 2.f, GameManager::getHeight() / 2.f);
    finalScoreText.setPosition(gameOverText.getPosition());
    finalScoreText.move(0, 20);
    gameManager.getResourceManager().playGameOver();
    gameManager.getClock().restart(); //why are we doing this
}

void EndState::tickState() {
    sf::Event event{};
    gameManager.getWindow().pollEvent(event);

    if (event.key.code == sf::Keyboard::Escape) {
        gameManager.getWindow().close();
    }

    if(event.key.code == sf::Keyboard::Space) {
        Util::resetGame();
    }

//    auto elapsedTime = -clock.getElapsedTime().asSeconds();
//    if(elapsedTime < sf::Time().Zero) resourceManager.startMusic();

    GameState::tickState();
}

void EndState::update(double dt) {

}

void EndState::renderState() {
    gameManager.getWindow().draw(gameOverText);
    gameManager.getWindow().draw(finalScoreText);
}