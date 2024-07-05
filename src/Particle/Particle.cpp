#include "Particle.h"

#include <cmath>

Particle::Particle(float radius, float x, float y) : m_radius(radius), m_position(x, y), m_acceleration(0, 0), m_velocity(0, 0), m_mass(calculateMass()), m_color(rand() % 256, rand() % 256, rand() % 256)
{ }

float Particle::calculateMass() const
{
	return m_radius;
}

void Particle::update(float deltaTime)
{
	// gravity
	applyForce(sf::Vector2f(0, 98.1f));

	// drag
	sf::Vector2f dragForce = -0.2f * m_velocity;
	applyForce(dragForce);

	m_velocity += m_acceleration * deltaTime;
	m_position += m_velocity * deltaTime;
	m_acceleration = sf::Vector2f(0, 0);
}

void Particle::applyForce(const sf::Vector2f& force)
{
	m_acceleration += force / m_mass;
}

bool Particle::isCollidingWithParticle(const Particle& p) const
{
	sf::Vector2f distanceVector = m_position - p.getPosition();
	float distance = sqrtf(powf(fabsf(distanceVector.x), 2) + powf(fabsf(distanceVector.y), 2)); // a^2 + b^2 = c^2

	return distance < (m_radius + p.getRadius());
}

bool Particle::isCollidingWithWall(sf::Vector2u windowSize) const
{
	bool outsideN = m_position.y - m_radius < 0;
	bool outsideE = m_position.x + m_radius > windowSize.x;
	bool outsideS = m_position.y + m_radius > windowSize.y;
	bool outsideW = m_position.x - m_radius < 0;

	return outsideN || outsideE || outsideS || outsideW;
}

// get func s
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

float Particle::getRadius() const
{
	return m_radius;
}

sf::CircleShape Particle::getDrawable() const
{
	sf::CircleShape shape(m_radius);

	shape.setPosition(m_position.x, m_position.y);
	shape.setFillColor(m_color);

	return shape;
}

void Particle::setVelocity(sf::Vector2f velocity)
{
	m_velocity = velocity;
}
