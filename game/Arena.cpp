#include "Arena.h"

Arena::Arena(float width, float height)
{
  this->width = width;
  this->height = height;

  float wallPadding = 10;
  float initialY = 10;
  float paddleWidth = 10;

  paddle1 = new Paddle(wallPadding, initialY, height);
  paddle2 = new Paddle(width - wallPadding - paddleWidth, initialY, height);
  ball = new Ball(width / 2, height / 2, width, height);
}

Arena::~Arena() {}

void Arena::draw(sf::RenderWindow *window)
{
  ball->draw(window);
  paddle1->draw(window);
  paddle2->draw(window);
}

void Arena::update(sf::Time time)
{
  ball->update(time);

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    paddle1->moveUp(time);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    paddle1->moveDown(time);

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    paddle2->moveUp(time);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    paddle2->moveDown(time);

  if (checkPaddleCollision(paddle1) or checkPaddleCollision(paddle2))
  {
    ball->invertX();
  }
}

bool Arena::checkPaddleCollision(Paddle *paddle)
{
  sf::Vector2f ballPosition = ball->getPosition();
  sf::Vector2f paddlePosition = paddle->getPosition();
  sf::Vector2f paddleSize = paddle->getSize();
  float ballDiameter = ball->getDiameter();

  return (ballPosition.x <= paddlePosition.x + paddleSize.x) and
         (ballPosition.x + ballDiameter >= paddlePosition.x) and
         (ballPosition.y <= paddlePosition.y + paddleSize.y) and
         (ballPosition.y + ballDiameter >= paddlePosition.y);
}