#include <SFML/Graphics.hpp>

class Ball
{
public:
  Ball(float x_initial_position, float y_initial_position, float max_x, float max_y);
  ~Ball();

  void draw(sf::RenderWindow *window);
  void update(sf::Time time);

  void invert_x();
  void invert_y();

  float get_radius();
  float get_diameter();
  void set_position(float x_position, float y_position);
  sf::Vector2f get_position();

private:
  float radius = 15;

  float x_position;
  float y_position;

  float x_velocity = 200;
  float y_velocity = 200;

  float max_x;
  float max_y;
};