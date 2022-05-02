//
// Created by Cole on 5/2/2022.
//

#ifndef ASTEROIDSSFML_PARTICLESYSTEM_H
#define ASTEROIDSSFML_PARTICLESYSTEM_H

#include <vector>
#include <SFML/Graphics.hpp>

class GameManager;
class ParticleSystem {
public:
    ParticleSystem(int count, GameManager& gameManager);
    GameManager& gameManager;
    void spawnParticles();

    void update(sf::Time elapsed);

    void drawAll();

private:
    struct Particle {
        sf::CircleShape shape;
        sf::Time lifetime;
    };
    std::vector<Particle> particles;
    sf::Time allowedLifetime;

    void resetParticle();

};


#endif //ASTEROIDSSFML_PARTICLESYSTEM_H
