//
// Created by Cole on 4/22/2022.
//

#ifndef ASTEROIDSSFML_RESOURCEMANAGER_H
#define ASTEROIDSSFML_RESOURCEMANAGER_H

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"

class ResourceManager {
public:
    static ResourceManager* Instance();
    void startMusic();
    void playFireSound();
    void updateScore(int scoreInc, sf::RenderWindow& window);

private:
    ResourceManager();
    sf::SoundBuffer buffer;
    sf::Sound sound;
    int scoreVal = 0;
    sf::Font font;
    sf::Text score;
    sf::Music music;

};


#endif //ASTEROIDSSFML_RESOURCEMANAGER_H
