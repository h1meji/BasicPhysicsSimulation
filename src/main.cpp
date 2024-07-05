#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Simulation/Simulation.h"

#include <iostream>

int main()
{
    // random seed
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(800, 600), "Basic Physics Simulation");
    window.setFramerateLimit(60);

    Simulation simulation(window.getSize(), 10, true, true);

    const float timeStep = 1.0f / 60.0f;
    sf::Clock clock;
    float accumulator = 0.0f;
    float currentTime = clock.getElapsedTime().asSeconds();

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float newTime = clock.getElapsedTime().asSeconds();
        float frameTime = newTime - currentTime;
        currentTime = newTime;
        accumulator += frameTime;

        while (accumulator >= timeStep) {
            simulation.update(timeStep);
            accumulator -= timeStep;
        }

        window.clear();

        // Draw particles
        for (const auto& particle : simulation.getParticles()) {
            window.draw(particle.getDrawable());
        }

        window.display();

        std::cout << accumulator << "\n" << frameTime << "\n" << newTime << "\n" << std::endl;
    }

    return 0;
}