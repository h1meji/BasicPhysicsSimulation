#pragma once

#include <vector>

#include "Particle/Particle.h"

class Simulation
{
public:
	Simulation(sf::Vector2u windowSize, int particlesCount, bool randomSizes, bool randomPositions);

	void update(float deltaTime);
	void checkCollisions();

	const std::vector<Particle>& getParticles() const;

private:
	std::vector<Particle> m_particles;
	sf::Vector2u m_windowSize;

	void resolveCollision(Particle& p1, Particle& p2) const;
	void resolveCollisionWithWall(Particle& p, sf::Vector2u windowSize) const;
};