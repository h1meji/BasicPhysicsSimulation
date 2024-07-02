#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main()
{
    sf::Window window(sf::VideoMode(800, 600), "Basic Physics Simulation");

    window.setFramerateLimit(60);

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}