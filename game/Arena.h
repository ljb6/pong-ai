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

  int paddle1Points = 0;
  int paddle2Points = 0;

  void checkScore();
  bool checkPaddleCollision(Paddle *paddle);
  void resetArena();
};