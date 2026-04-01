#include <SFML/Graphics.hpp>
#include "game/Arena.h"
#include <iostream>
#include <unistd.h>

const int WIDTH = 800;
const int HEIGHT = 600;

int main(int argc, char *argv[])
{
  int opt;
  std::string output;

  bool is_render_activated = true;

  while ((opt = getopt(argc, argv, "n")) != -1)
  {
    switch (opt)
    {
    case 'n':
      std::cout << "Render deactivated\n";
      is_render_activated = false;
      break;
    }
  }

  sf::RenderWindow window;
  if (is_render_activated)
    window.create(sf::VideoMode({WIDTH, HEIGHT}), "PongAI");

  sf::Clock clock;

  Arena arena(WIDTH, HEIGHT);

  bool running = true;
  while (running)
  {
    sf::Time delta_time = clock.restart();

    if (is_render_activated)
    {
      if (!window.isOpen())
        break;

      while (const std::optional event = window.pollEvent())
      {
        if (event->is<sf::Event::Closed>())
          running = false;
      }
    }

    arena.update(delta_time);

    if (is_render_activated)
    {
      window.clear();
      arena.draw(&window);
      window.display();
    }
  }

  return 0;
}