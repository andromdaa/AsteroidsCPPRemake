//
// Created by Cole on 4/22/2022.
//

#include "ResourceManager.h"
#include <iostream>
#include <cmath>

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
    scoreVal += scoreInc;
    text.setString("Score " + std::to_string(scoreVal));
    window.draw(text);
}

void ResourceManager::beginPlayingText(sf::RenderWindow& window) {
//    int i = 0;
    for(auto& textItem : beginText) {
        window.draw(textItem);
//        textItem.setPosition(textItem.getPosition().x, textItem.getPosition().y + sinf(((360 / 23) * i) * (M_PI / 180) ));
//        i++;
    }
}

void ResourceManager::bounceText(sf::RenderWindow& window) {
    sf::Text positionModel;
    positionModel.setString("Press any key to begin!");
    positionModel.setCharacterSize(24);
    positionModel.setOrigin(positionModel.getLocalBounds().width / 2, positionModel.getLocalBounds().height / 2 );
    positionModel.setPosition((uint16_t) (window.getSize().x / 2), (uint16_t) (window.getSize().y / 2));

    for (int i = 0; i < 23; i++) {
        float y = (uint16_t) (window.getSize().y / 2);
        text.setString(characters[i]);
        text.setCharacterSize(24);
        text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2 );
        auto x = (float) (i * text.getCharacterSize());
        x += 100.f + text.getCharacterSize();
        text.setPosition(x, (text.getPosition().y + sinf(((360 / 23) * i) * (M_PI / 180) ) * -20));
//        text.setPosition(x, y);
        beginText.push_back(text);
    }
}

void ResourceManager::startMusic() {
    ResourceManager::music.play();
}

void ResourceManager::playFireSound() {
    sound.play();
}

//ResourceManager *ResourceManager::Instance() {
//    static ResourceManager* self;
//    if(self == nullptr) {
//        self = new ResourceManager();
//    }
//    return self;
//}




