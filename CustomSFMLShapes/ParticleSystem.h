//
// Created by Cole on 4/29/2022.
//

#ifndef ASTEROIDSSFML_PARTICLESYSTEM_H
#define ASTEROIDSSFML_PARTICLESYSTEM_H

#include <SFML/Graphics.hpp>
#include <cmath>
class GameState;

class ParticleSystem : public sf::Drawable, public sf::Transformable {
public:
    ParticleSystem(unsigned int count, GameState& gameState);

    void setEmitter(sf::Vector2f position);
    void update(sf::Time elapsed);
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    struct Particle {
        sf::Vector2f velocity;
        sf::Time lifetime;
    };

    void resetParticle(std::size_t index);

    GameState& gameState;
    std::vector<Particle> m_particles;
    sf::VertexArray m_vertices;
    sf::Time m_lifetime;
    sf::Vector2f m_emitter;
};


#endif //ASTEROIDSSFML_PARTICLESYSTEM_H
