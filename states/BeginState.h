//
// Created by Cole on 4/23/2022.
//

#ifndef ASTEROIDSSFML_BEGINSTATE_H
#define ASTEROIDSSFML_BEGINSTATE_H

#include "GameState.h"

class BeginState : public GameState {
public:
    static BeginState* Instance(sf::RenderWindow &window, GameManager& gameManager);
    void transitionState(GameManager* g) override;
    void tickState() override;
    void renderState() override;
private:
    std::vector<sf::Text> beginText;
    void drawStars();
    void generateStars();
    void handleEvents();
    BeginState(sf::RenderWindow &window, GameManager& gameManager);
    const int MAX_STARS = 100;
    void drawText(sf::Text& text, float offset);
    void updateText();
    void spawnText();


private:
    sf::String chars[20] = {
            "P",
            "r",
            "e",
            "s",
            "a",
            " ",
            "a",
            " ",
            "k",
            "e",
            "y",
            " ",
            "t",
            "o",
            "",
            "p",
            "l",
            "a",
            "y",
            "!",
    };
};


#endif //ASTEROIDSSFML_BEGINSTATE_H
