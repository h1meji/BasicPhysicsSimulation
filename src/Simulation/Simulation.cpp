#include "Simulation.h"

static sf::Vector2f normalize(sf::Vector2f vec)
{
	float magnitude = sqrtf(powf(vec.x, 2) + powf(vec.y, 2));
	return sf::Vector2f(vec.x / magnitude, vec.y / magnitude);
}

static float dot(sf::Vector2f vec1, sf::Vector2f vec2)
{
	return (vec1.x * vec2.x) + (vec1.y * vec2.y);
}

Simulation::Simulation(sf::Vector2u windowSize, int particlesCount, bool randomSizes, bool randomPositions): m_windowSize(windowSize)
{
	// create particles
	for (size_t i = 0; i < particlesCount; i++)
	{
		float size = randomSizes ? static_cast<float>(rand() % 10) + 10 : 10;
		float x = randomPositions ? static_cast<float>(rand() % m_windowSize.x - 100) + 50 : 50;
		float y = randomPositions ? static_cast<float>(rand() % m_windowSize.y - 100) + 50 : 50;

		m_particles.push_back(Particle(size, x, y));
	}
}

void Simulation::update(float deltaTime)
{
	for (size_t i = 0; i < m_particles.size(); i++)
	{
		m_particles[i].update(deltaTime);
	}

	checkCollisions();
}

void Simulation::checkCollisions()
{
	for (size_t i = 0; i < m_particles.size(); ++i) {
		for (size_t j = i + 1; j < m_particles.size(); ++j) {
			if (m_particles[i].isCollidingWithParticle(m_particles[j]))
				resolveCollision(m_particles[i], m_particles[j]);
		}

		if (m_particles[i].isCollidingWithWall(m_windowSize))
			resolveCollisionWithWall(m_particles[i], m_windowSize);
	}
}

const std::vector<Particle>& Simulation::getParticles() const
{
	return m_particles;
}

void Simulation::resolveCollision(Particle& p1, Particle& p2) const
{
	// Basic elastic collision resolution
	sf::Vector2f normal = normalize(p2.getPosition() - p1.getPosition());
	float relativeVelocity = dot((p2.getVelocity() - p1.getVelocity()), normal);

	float impulse = 2 * relativeVelocity / (p1.getMass() + p2.getMass());

	p1.setVelocity(p1.getVelocity() - impulse * p2.getMass() * normal);
	p2.setVelocity(p2.getVelocity() + impulse * p1.getMass() * normal);
}

void Simulation::resolveCollisionWithWall(Particle& p, sf::Vector2u windowSize) const
{
	sf::Vector2f v = p.getVelocity();
	if (p.getPosition().x + p.getRadius() <= 0 || p.getPosition().x + p.getRadius() >= windowSize.x)
	{
		v.x *= -1;
		p.setVelocity(v);
	}

	if (p.getPosition().y + p.getRadius() <= 0 || p.getPosition().y + p.getRadius() >= windowSize.y)
	{
		v.y *= -1;
		p.setVelocity(v);
	}

}
