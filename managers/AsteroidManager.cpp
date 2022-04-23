//
// Created by Cole on 4/22/2022.
//

#include "AsteroidManager.h"

AsteroidManager *AsteroidManager::Instance() {
    static AsteroidManager* self;
    if(self == nullptr) {
        self = new AsteroidManager;
    }

    return self;
}
