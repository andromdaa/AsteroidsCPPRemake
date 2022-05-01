//
// Created by Cole on 4/23/2022.
//

#ifndef ASTEROIDSSFML_ENDSTATE_H
#define ASTEROIDSSFML_ENDSTATE_H

#include "GameState.h"

class EndState : public GameState {
public:
    explicit EndState(sf::RenderWindow& window, GameManager& gameManager);
    static std::shared_ptr<EndState> Instance(sf::RenderWindow& window, GameManager& gameManager);
private:
    sf::Text gameOverText;
    sf::Text finalScoreText;

    void tickState();

    void update(double dt);

    void renderState();
};

#endif //ASTEROIDSSFML_ENDSTATE_H
