//
// Created by Cole on 4/22/2022.
//

#include "ResourceManager.h"
#include <iostream>

ResourceManager::ResourceManager() {
    if (!music.openFromFile("assets/sounds/music.wav")) std::cout << "Music Error" << std::endl;
    music.setVolume(25.f);

    if (!buffer.loadFromFile("assets/sounds/fire.ogg")) std::cout << "Sound Error" << std::endl;
    sound.setBuffer(buffer);
    sound.setVolume(50.f);

    if(!font.loadFromFile("assets/fonts/ARCADECLASSIC.TTF")) std::cout << "Font Error" << std::endl;
    text.setFont(font);
    text.setFillColor(sf::Color::White);
}

void ResourceManager::updateScore(int scoreInc, sf::RenderWindow& window) {
    text.setCharacterSize(24);
    scoreVal += scoreInc;
    text.setString("Score " + std::to_string(scoreVal));
    window.draw(text);
}

void ResourceManager::beginPlayingText(sf::RenderWindow& window) {
    text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2 );
    text.setPosition((uint16_t) (window.getSize().x / 2), (uint16_t) (window.getSize().y / 2));
    text.setString("Press any key to begin!");
    text.setCharacterSize(24);
    window.draw(text);
}

void ResourceManager::startMusic() {
    ResourceManager::music.play();
}

void ResourceManager::playFireSound() {
    sound.play();
}

ResourceManager *ResourceManager::Instance() {
    static ResourceManager* self;
    if(self == nullptr) {
        self = new ResourceManager();
    }
    return self;
}




