#include <SFML/Graphics.hpp>

class Paddle
{
public:
  Paddle(float xInitialPosition, float yInitialPosition, float maxY);
  ~Paddle();

  void draw(sf::RenderWindow *window);
  void moveUp(sf::Time time);
  void moveDown(sf::Time time);

  sf::Vector2f getPosition();
  sf::Vector2f getSize();

private:
  float xPosition;
  float yPosition;

  float width = 10;
  float height = 100;

  float velocity = 300;

  float maxY;
};