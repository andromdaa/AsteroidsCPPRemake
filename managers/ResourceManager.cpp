//
// Created by Cole on 4/22/2022.
//

#include "ResourceManager.h"
#include "../GameManager.h"
#include <iostream>

ResourceManager::ResourceManager() {
    if (!music.openFromFile("assets/sounds/music.wav")) std::cout << "Music Error" << std::endl;
    music.setVolume(50.f);

    if (!buffer.loadFromFile("assets/sounds/lazer_hit.wav")) std::cout << "Sound Error" << std::endl;
    sound.setBuffer(buffer);
    sound.setVolume(50.f);

    if(!font.loadFromFile("assets/fonts/ARCADECLASSIC.TTF")) std::cout << "Font Error" << std::endl;
    text.setFont(font);
    text.setFillColor(sf::Color::White);

//    if(!gameOverBuffer.loadFromFile("assets/sounds/gameover.ogg")) std::cout << "Game Over Sound Error" << std::endl;
//    gameOver.setBuffer(gameOverBuffer);
//    gameOver.setVolume(50.f);

}

void ResourceManager::updateScore(int scoreInc, sf::RenderWindow& window) {
    GameManager::score += scoreInc;
    text.setString("Score " + std::to_string(GameManager::score));
    window.draw(text);
}

void ResourceManager::startMusic() {
    ResourceManager::music.play();
}

void ResourceManager::playFireSound() {
    sound.play();
}

void ResourceManager::playGameOver() {
    gameOver.play();
}



//ResourceManager *ResourceManager::Instance() {
//    static ResourceManager* self;
//    if(self == nullptr) {
//        self = new ResourceManager();
//    }
//    return self;
//}




