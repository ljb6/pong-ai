#include "Ball.h"
#include <cmath>

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

void Ball::bounce_off_paddle(float hit_position, int direction)
{
  float max_angle = 75.0f * (3.14159265f / 180.0f);
  float angle = hit_position * max_angle;

  float speed = std::sqrt(x_velocity * x_velocity + y_velocity * y_velocity);
  speed = std::min(speed + speed_increment, max_speed);

  x_velocity = speed * std::cos(angle) * direction;
  y_velocity = speed * std::sin(angle);
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

void Ball::set_x(float x)
{
  x_position = x;
}

sf::Vector2f Ball::get_position()
{
  return {x_position, y_position};
}

float Ball::get_x_velocity()
{
  return x_velocity;
}

float Ball::get_y_velocity()
{
  return y_velocity;
}

void Ball::reset_velocity()
{
  x_velocity = base_speed;
  y_velocity = base_speed;
}