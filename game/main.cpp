#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"

const int WIDTH = 800;
const int HEIGHT = 600;

int main(void)
{
  sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "SFML window");

  Paddle *p1 = new Paddle(10, 10, HEIGHT);
  Ball *ball = new Ball(WIDTH / 2, HEIGHT / 2, WIDTH, HEIGHT);

  sf::Clock clock;

  while (window.isOpen())
  {
    sf::Time deltaTime = clock.restart();

    while (const std::optional event = window.pollEvent())
    {
      if (event->is<sf::Event::Closed>())
        window.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
      p1->moveUp(deltaTime);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
      p1->moveDown(deltaTime);
    }

    window.clear();

    ball->draw(&window);
    p1->draw(&window);

    ball->update(deltaTime);

    window.display();
  }

  return 0;
}