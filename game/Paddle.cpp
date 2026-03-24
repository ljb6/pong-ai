#include "Paddle.h"

Paddle::Paddle(float x_initial_position, float y_initial_position, float max_y)
{
  x_position = x_initial_position;
  y_position = y_initial_position;
  this->max_y = max_y;
}

Paddle::~Paddle() {}

void Paddle::draw(sf::RenderWindow *window)
{
  sf::RectangleShape rectangle({width, height});
  rectangle.setPosition({x_position, y_position});
  window->draw(rectangle);
}

void Paddle::move_up(sf::Time time)
{
  if (y_position > 0)
    y_position -= (velocity * time.asSeconds());
}

void Paddle::move_down(sf::Time time)
{
  if (y_position < (max_y - height))
    y_position += (velocity * time.asSeconds());
}

void Paddle::set_position(float y_position)
{
  this->y_position = y_position;
}

sf::Vector2f Paddle::get_position()
{
  return {x_position, y_position};
}

sf::Vector2f Paddle::get_size()
{
  return {width, height};
}