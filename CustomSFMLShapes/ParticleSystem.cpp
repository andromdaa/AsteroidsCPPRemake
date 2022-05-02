//
// Created by Cole on 4/29/2022.
//

#include "ParticleSystem.h"
#include "../states/ActiveState.h"

ParticleSystem::ParticleSystem(unsigned int count, GameState& gameState) :
        gameState(gameState),
        m_particles(count),
        m_vertices(sf::Points, count),
        m_lifetime(sf::seconds(3.f)),
        m_emitter(0.f, 0.f)
        {}

void ParticleSystem::setEmitter(sf::Vector2f position) {
    m_emitter = position;
}

void ParticleSystem::update(sf::Time elapsed) {
    for(std::size_t i = 0; i < m_particles.size(); ++i) {
        Particle& p = m_particles[i];
        p.lifetime -= elapsed;

        if(p.lifetime <= sf::Time::Zero) {
            resetParticle(i);
        }

        m_vertices[i].position += p.velocity * elapsed.asSeconds();

        float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
        m_vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);
        m_vertices[i].color = sf::Color::Yellow;
    }
}

void ParticleSystem::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();

    states.texture = nullptr;

    target.draw(m_vertices, states);
}

void ParticleSystem::resetParticle(std::size_t index) {
    // give a random velocity and lifetime to the particle
    float angle = gameState.player.getRotation();
    float speed = gameState.player.getSpeed();
    m_particles[index].velocity = ActiveState::getMovement(gameState.player, speed, gameState.dt);

//    m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);

    m_particles[index].lifetime = sf::milliseconds((std::rand() % 2000));

    // reset the position of the corresponding vertex
    m_vertices[index].position = m_emitter;
}

void ParticleSystem::reset() {
    for(int i = 0; i < m_particles.size(); i++) {
        resetParticle(i);
    }
}
