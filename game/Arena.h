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

  Ball *ball;

  Paddle *paddle1;
  Paddle *paddle2;

  int paddle1Points = 0;
  int paddle2Points = 0;

  sf::Font font;
  sf::Text text1;
  sf::Text text2;

  void checkScore();
  bool checkPaddleCollision(Paddle *paddle);
  void resetArena();
};