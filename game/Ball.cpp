#include "Ball.h"

Ball::Ball(float xInitialPosition, float yInitialPosition, float maxX, float maxY)
{
  xPosition = xInitialPosition;
  yPosition = yInitialPosition;
  this->maxX = maxX;
  this->maxY = maxY;
}

Ball::~Ball() {}

void Ball::draw(sf::RenderWindow *window)
{
  sf::CircleShape circle(radius);
  circle.setPosition({xPosition, yPosition});
  window->draw(circle);
}

void Ball::update(sf::Time time)
{
  xPosition += (xVelocity * time.asSeconds());
  yPosition += (yVelocity * time.asSeconds());

  if (yPosition >= (maxY - (radius * 2)))
  {
    yVelocity *= -1;
    yPosition = (maxY - (radius * 2));
  }

  if (yPosition <= 0)
  {
    yVelocity *= -1;
    yPosition = 0;
  }

  if (xPosition >= (maxX - (radius * 2)))
  {
    xVelocity *= -1;
    xPosition = (maxX - (radius * 2));
  }

  if (xPosition <= 0)
  {
    xVelocity *= -1;
    xPosition = 0;
  }
}

void Ball::invertX()
{
  xVelocity *= -1;
}

void Ball::invertY()
{
  yVelocity *= -1;
}

float Ball::getRadius()
{
  return radius;
}

sf::Vector2f Ball::getPosition()
{
  return {xPosition, yPosition};
}