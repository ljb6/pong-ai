#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"
class Arena
{
public:
  Arena(float width, float height);
  ~Arena();

  void draw(sf::RenderWindow *window);
  void update(sf::Time time);

private:
  float width;
  float height;

  Paddle *paddle1;
  Paddle *paddle2;
  Ball *ball;
};