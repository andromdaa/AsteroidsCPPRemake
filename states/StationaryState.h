//
// Created by Cole on 4/21/2022.
//

#ifndef ASTEROIDSSFML_STATIONARYSTATE_H
#define ASTEROIDSSFML_STATIONARYSTATE_H

#include "PlayerState.h"

enum class Keys;
class StationaryState : public PlayerState {
public:
    static PlayerState* Instance();
    void processInput(Player*, Keys) override;
};

#endif //ASTEROIDSSFML_STATIONARYSTATE_H
