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
  void bounce_off_paddle(float hit_position, int direction);

  float get_radius();
  float get_diameter();

  void set_position(float x_position, float y_position);
  void reset_velocity();
  sf::Vector2f get_position();

  void set_x(float x);
  float get_x_velocity();
  float get_y_velocity();

private:
  float radius = 15;

  float x_position;
  float y_position;

  float x_velocity = 800;
  float y_velocity = 800;

  float base_speed = 800;
  float max_speed = 1200;
  float speed_increment = 25;

  float max_x;
  float max_y;
};