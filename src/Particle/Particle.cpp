#include "Particle.h"

Particle::Particle(float radius, float x, float y) : m_radius(radius), m_position(x, y), m_acceleration(0, 0), m_velocity(0, 0), m_mass(calculateMass())
{ }

float Particle::calculateMass() const
{
	return m_radius;
}

sf::Vector2f Particle::getPosition() const
{
	return m_position;
}

sf::Vector2f Particle::getVelocity() const
{
	return m_velocity;
}

sf::Vector2f Particle::getAcceleration() const
{
	return m_acceleration;
}

float Particle::getMass() const
{
	return m_mass;
}

void Particle::update(float deltaTime)
{
	m_velocity += m_acceleration * deltaTime;
	m_position += m_velocity * deltaTime;
	m_acceleration = sf::Vector2f(0, 0);
}

void Particle::applyForce(const sf::Vector2f& force)
{
	m_acceleration += force / m_mass;
}