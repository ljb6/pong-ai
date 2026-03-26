#include <SFML/Graphics.hpp>

class Paddle
{
public:
  Paddle(float x_initial_position, float y_initial_position, float max_y);
  ~Paddle();

  void draw(sf::RenderWindow *window);
  void move_up(sf::Time time);
  void move_down(sf::Time time);

  void set_position(float y_position);
  sf::Vector2f get_position();
  sf::Vector2f get_size();

private:
  float x_position;
  float y_position;

  float width = 10;
  float height = 100;

  float velocity = 1200;

  float max_y;
};