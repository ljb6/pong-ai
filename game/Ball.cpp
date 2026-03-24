#include "Ball.h"

Ball::Ball(float x_initial_position, float y_initial_position, float max_x, float max_y)
{
  x_position = x_initial_position;
  y_position = y_initial_position;
  this->max_x = max_x;
  this->max_y = max_y;
}

Ball::~Ball() {}

void Ball::draw(sf::RenderWindow *window)
{
  sf::CircleShape circle(radius);
  circle.setPosition({x_position, y_position});
  window->draw(circle);
}

void Ball::update(sf::Time time)
{
  x_position += (x_velocity * time.asSeconds());
  y_position += (y_velocity * time.asSeconds());

  if (y_position >= (max_y - (radius * 2)))
  {
    y_velocity *= -1;
    y_position = (max_y - (radius * 2));
  }

  if (y_position <= 0)
  {
    y_velocity *= -1;
    y_position = 0;
  }
}

void Ball::invert_x()
{
  x_velocity *= -1;
}

void Ball::invert_y()
{
  y_velocity *= -1;
}

float Ball::get_radius()
{
  return radius;
}

float Ball::get_diameter()
{
  return (radius * 2);
}

void Ball::set_position(float x_position, float y_position)
{
  this->x_position = x_position;
  this->y_position = y_position;
}

sf::Vector2f Ball::get_position()
{
  return {x_position, y_position};
}