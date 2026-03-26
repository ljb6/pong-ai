#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"
#include "../agent/Agent.h"

class Arena
{
public:
  Arena(float width, float height);

  void draw(sf::RenderWindow *window);
  void update(sf::Time time);

private:
  float width;
  float height;

  float wall_padding = 10;
  float paddle_width = 10;

  Agent agent;
  bool already_learned = false;

  Ball ball;

  Paddle paddle_1;
  Paddle paddle_2;

  int paddle_1_points = 0;
  int paddle_2_points = 0;

  sf::Font font;
  sf::Text text_1;
  sf::Text text_2;

  void check_score();
  bool check_paddle_collision(Paddle &paddle);
  void reset_arena();
};
