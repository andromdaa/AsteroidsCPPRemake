//
// Created by Cole on 4/22/2022.
//

#include "ResourceManager.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <fstream>
#include "../util/Util.h"
#include "../states/GameState.h"

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



bool ResourceManager::beginPlayingText(sf::RenderWindow& window, double dt, int iteration) {
    for(auto& render : beginText) {
        render.move(0, (float) (iteration * dt));
        window.draw(render);
        if(render.getPosition().y <= 200) return true;
        if(render.getPosition().y >= 400) return true;
    }
    return false;
}

void ResourceManager::genText(float size) {
    for(int i = 0; i < 23; i++) {
        text.setString(characters[i]);
        text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
        auto x = (float) (i * text.getCharacterSize());
        x += 100.f + (float) text.getCharacterSize();
        text.setPosition(x, size);
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




