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
    score.setFont(font);
    score.setString("Score  " + std::to_string(scoreVal));
    score.setCharacterSize(24);
    score.setFillColor(sf::Color::White);
}

void ResourceManager::updateScore(int scoreInc, sf::RenderWindow& window) {
    scoreVal += scoreInc;
    score.setString("Score " + std::to_string(scoreVal));
    window.draw(score);
;}

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




