#include <SFML/Graphics.hpp>

class Ball
{
public:
  Ball(float xInitialPosition, float yInitialPosition, float maxX, float maxY);
  ~Ball();

  void draw(sf::RenderWindow *window);
  void update(sf::Time time);

  void invertX();
  void invertY();

  float getRadius();
  sf::Vector2f getPosition();

private:
  float radius = 15;

  float xPosition;
  float yPosition;

  float xVelocity = 200;
  float yVelocity = 200;

  float maxX;
  float maxY;
};