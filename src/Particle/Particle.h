#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Particle
{
public:
	Particle(float radius, float x, float y);

	void update(float deltaTime);
	void applyForce(const sf::Vector2f& force);

	bool isCollidingWithParticle(const Particle& p) const;
	bool isCollidingWithWall(sf::Vector2u windowSize) const;

	// get func s
	sf::Vector2f getPosition() const;
	sf::Vector2f getVelocity() const;
	sf::Vector2f getAcceleration() const;
	float getMass() const;
	float getRadius() const;
	sf::CircleShape getDrawable() const;

	// set func s
	void setVelocity(sf::Vector2f velocity);

private:
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	sf::Vector2f m_acceleration;
	float m_mass;
	float m_radius;

	sf::Color m_color;

	float calculateMass() const;
};