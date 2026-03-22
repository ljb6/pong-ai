#include "Paddle.h"

Paddle::Paddle(float xInitialPosition, float yInitialPosition, float maxY)
{
  xPosition = xInitialPosition;
  yPosition = yInitialPosition;
  this->maxY = maxY;
}

Paddle::~Paddle() {}

void Paddle::draw(sf::RenderWindow *window)
{
  sf::RectangleShape rectangle({width, height});
  rectangle.setPosition({xPosition, yPosition});
  window->draw(rectangle);
}

void Paddle::moveUp(sf::Time time)
{
  if (yPosition > 0)
    yPosition -= (velocity * time.asSeconds());
}

void Paddle::moveDown(sf::Time time)
{
  if (yPosition < (maxY - height))
    yPosition += (velocity * time.asSeconds());
}