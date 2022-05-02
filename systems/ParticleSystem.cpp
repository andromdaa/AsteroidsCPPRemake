//
// Created by Cole on 5/2/2022.
//

#include <iostream>
#include "ParticleSystem.h"
#include "../states/ActiveState.h"
#include "../Player.h"
#include "../GameManager.h"

ParticleSystem::ParticleSystem(int count, GameManager& gameManager) :
gameManager(gameManager),
particles(count),
allowedLifetime(sf::seconds(1.f))
{
    spawnParticles();
}

void ParticleSystem::spawnParticles() {
    for(int i = 0; i < particles.size(); i++) {
        particles[i].shape = sf::CircleShape(rand() % 4);
        particles[i].shape.setOrigin(particles[i].shape.getRadius(), particles[i].shape.getRadius());
        particles[i].shape.setPosition(gameManager.getPlayer().getTransform().transformPoint(gameManager.getPlayer().getPoint(2)));
        particles[i].lifetime = sf::seconds(1.f);
    }
}

void ParticleSystem::update(sf::Time elapsed) {
    //check elasped time to see if particles' lifetime is over
    for(int i = 0; i < particles.size(); i++) {
        auto& particle = particles[i];
        particle.lifetime -= elapsed;

        if(particle.lifetime <= sf::Time::Zero) {
            resetParticle();
        }


        float ratio = particle.lifetime.asSeconds() / allowedLifetime.asSeconds();
        sf::Color color(255, 255, 0, static_cast<sf::Uint8>(ratio * 255));
        particle.shape.setFillColor(color);
    }
}

void ParticleSystem::drawAll() {
    for(auto& particle : particles) {
        gameManager.getWindow().draw(particle.shape);
    }
}

void ParticleSystem::resetParticle() {
//    std::cout << "Reset!" << std::endl;
}
