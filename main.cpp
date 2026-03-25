#include <SFML/Graphics.hpp>
#include "game/Arena.h"
// #include "../neural/NeuralNetwork.h"
// #include <iostream>

const int WIDTH = 800;
const int HEIGHT = 600;

int main(void)
{
  // std::vector<float> simulation = {8.4, 2.1, 2, 8.6};
  // NeuralNetwork nn({4, 8, 3});
  // std::vector<float> v = nn.forward(simulation);

  // for (auto x : v)
  //   std::cout << x << " ";
  // std::cout << "\n";

  sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "SFML window");

  sf::Clock clock;

  Arena arena(WIDTH, HEIGHT);

  while (window.isOpen())
  {
    sf::Time delta_time = clock.restart();

    while (const std::optional event = window.pollEvent())
    {
      if (event->is<sf::Event::Closed>())
        window.close();
    }

    arena.update(delta_time);

    window.clear();

    arena.draw(&window);

    window.display();
  }

  return 0;
}