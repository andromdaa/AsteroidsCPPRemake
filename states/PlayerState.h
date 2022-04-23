//
// Created by Cole on 4/21/2022.
//

#ifndef ASTEROIDSSFML_PLAYERSTATE_H
#define ASTEROIDSSFML_PLAYERSTATE_H

class Player;
class PlayingState;
#include "../managers/ProjectileManager.h"
enum class Keys;

class PlayerState {
public:
    static PlayingState* stationary;
//    static PlayingState stationary;
//    static PlayingState stationary;
//    static PlayingState stationary;
    virtual void processInput(Player*);
protected:
    void changeState(Player*, PlayerState*);
};


#endif //ASTEROIDSSFML_PLAYERSTATE_H
