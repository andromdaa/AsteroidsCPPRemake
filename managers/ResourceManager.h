//
// Created by Cole on 4/22/2022.
//

#ifndef ASTEROIDSSFML_RESOURCEMANAGER_H
#define ASTEROIDSSFML_RESOURCEMANAGER_H

#include <list>
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"

class ResourceManager {
public:
//    static ResourceManager* Instance();
    void startMusic();
    void playFireSound();
    void updateScore(int scoreInc, sf::RenderWindow& window);
    void playGameOver();
    ResourceManager();
private:
    friend class BeginState;
    friend class ActiveState;
    friend class EndState;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    sf::Font font;
    sf::Text text;
    sf::Music music;
    sf::SoundBuffer gameOverBuffer;
    sf::Sound gameOver;

    void stopMusic();
};


#endif //ASTEROIDSSFML_RESOURCEMANAGER_H
