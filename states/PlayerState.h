//
// Created by Cole on 4/21/2022.
//

#ifndef ASTEROIDSSFML_PLAYERSTATE_H
#define ASTEROIDSSFML_PLAYERSTATE_H

class Player;
class StationaryState;
enum class Keys;

class PlayerState {
public:
    static StationaryState* stationary;
//    static StationaryState stationary;
//    static StationaryState stationary;
//    static StationaryState stationary;
    virtual void processInput(Player*, Keys);
protected:
    void changeState(Player*, PlayerState*);
};


#endif //ASTEROIDSSFML_PLAYERSTATE_H
