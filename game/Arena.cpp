#include "Arena.h"

Arena::Arena(float width, float height)
{
  this->width = width;
  this->height = height;

  paddle1 = new Paddle(10, 10, height);
  paddle2 = new Paddle(width - 20, 10, height);
  ball = new Ball(width / 2, height / 2, width, height);
}

Arena::~Arena() {}

void Arena::draw(sf::RenderWindow *window)
{
  ball->draw(window);
  paddle1->draw(window);
  paddle2->draw(window);
}

void Arena::update(sf::Time time)
{
  ball->update(time);

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    paddle1->moveUp(time);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    paddle1->moveDown(time);

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    paddle2->moveUp(time);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    paddle2->moveDown(time);
}