#include <SFML/Graphics.hpp>

class Ball
{
public:
  Ball(float xInitialPosition, float yInitialPosition, float maxX, float maxY);
  ~Ball();

  void draw(sf::RenderWindow *window);
  void update(sf::Time time);

private:
  int radius = 15;

  float xPosition;
  float yPosition;

  float xVelocity = 200;
  float yVelocity = 200;

  float maxX;
  float maxY;
};