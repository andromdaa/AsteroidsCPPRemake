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
    bool beginPlayingText(sf::RenderWindow &window, double dt, int iteration);
    ResourceManager();
private:
    friend class BeginState;
    friend class ActiveState;
    friend class EndState;
    std::vector<sf::Text> beginText;
    std::vector<sf::Text> testing;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    int scoreVal = 0;
    sf::Font font;
    sf::Text text;
    sf::Music music;
    void genText(float size);
private:
    const sf::String characters[23] = {
            "P",
            "r",
            "e",
            "s",
            "s",
            " ",
            "a",
            "n",
            "y",
            " ",
            "k",
            "e",
            "y",
            " ",
            "t",
            "o",
            " ",
            "b",
            "e",
            "g",
            "i",
            "n",
            "!",
    };

};


#endif //ASTEROIDSSFML_RESOURCEMANAGER_H
