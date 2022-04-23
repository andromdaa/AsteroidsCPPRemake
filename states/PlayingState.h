//
// Created by Cole on 4/21/2022.
//

#ifndef ASTEROIDSSFML_PLAYINGSTATE_H
#define ASTEROIDSSFML_PLAYINGSTATE_H

#include "PlayerState.h"
#include "../Player.h"



enum class Keys;
class PlayingState : public PlayerState {
public:
    static PlayerState* Instance();
    void processInput(Player*) override;
private:
};


#endif //ASTEROIDSSFML_PLAYINGSTATE_H
