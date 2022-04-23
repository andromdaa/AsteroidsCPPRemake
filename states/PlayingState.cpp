//
// Created by Cole on 4/21/2022.
//
#include "PlayingState.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "../GameManager.h"

using namespace sf;

PlayerState *PlayingState::Instance() {
    static PlayingState* self;
    if(self == nullptr) {
        self = new PlayingState();
    }
    return self;
}

void PlayingState::processInput(Player* player) {

    if(player->rotationSpeed >= player->UPPER_ROTATION_BOUND) player->rotationSpeed = player->UPPER_ROTATION_BOUND;
    if(player->rotationSpeed <= player->LOWER_ROTATION_BOUND) player->rotationSpeed = player->LOWER_ROTATION_BOUND;

    if (player->speed >= player->UPPER_SPEED_BOUND) player->speed = player->UPPER_SPEED_BOUND;
    if (player->speed <= player->LOWER_SPEED_BOUND) player->speed = player->LOWER_SPEED_BOUND;

    if(Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        player->rotationSpeed -= player->ROTATION_INC;
        player->rotate(player->rotationSpeed);
    }

    if(Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        player->rotationSpeed += player->ROTATION_INC;
        player->rotate(player->rotationSpeed);
    }

    if(Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        player->speed += player->SPEED_INC;
        player->updatePlayerPos();
    }

    if(!Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if(player->speed > 0) player->speed -= .1f; //passively slow down the player, approach 0
        if(player->speed < 0) player->speed += 0.035; //if player is bounced off wall, passively approach 0 speed
        player->updatePlayerPos();
    } else {
        player->speed -= 0.03f; //actively slow player
        player->updatePlayerPos();
    }


    if(Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        GameManager::projectileHandler->spawnProjectile(player);
//        GameManager::resourceManager->playFireSound();
    }
}
