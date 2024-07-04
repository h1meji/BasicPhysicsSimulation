#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Particle
{
public:
	Particle(float radius, float x, float y);

	void update(float deltaTime);
	void applyForce(const sf::Vector2f& force);

	// get func s
	sf::Vector2f getPosition();
	sf::Vector2f getVelocity();
	sf::Vector2f getAcceleration();
	float getMass();

private:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	float mass;
	float radius;

	float calculateMass(float g = 9.81f);
};