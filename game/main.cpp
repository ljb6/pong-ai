#include <SFML/Graphics.hpp>
#include "Arena.h"

const int WIDTH = 800;
const int HEIGHT = 600;

int main(void)
{
  sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "SFML window");

  sf::Clock clock;

  Arena *arena = new Arena(WIDTH, HEIGHT);

  while (window.isOpen())
  {
    sf::Time deltaTime = clock.restart();

    while (const std::optional event = window.pollEvent())
    {
      if (event->is<sf::Event::Closed>())
        window.close();
    }

    arena->update(deltaTime);

    window.clear();

    arena->draw(&window);

    window.display();
  }

  return 0;
}