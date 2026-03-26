#include "Arena.h"
#include <random>

Arena::Arena(float width, float height) : font("assets/fonts/Geneva.ttf"), text_1(font), text_2(font)
{
  this->width = width;
  this->height = height;

  float wall_padding = 10;
  float initial_y = 10;
  float paddle_width = 10;

  agent = new Agent({4, 8, 3}, width, height);
  paddle_1 = new Paddle(wall_padding, initial_y, height);
  paddle_2 = new Paddle(width - wall_padding - paddle_width, initial_y, height);
  ball = new Ball(width / 2, height / 2, width, height);
}

Arena::~Arena()
{
  delete agent;
  delete ball;
  delete paddle_1;
  delete paddle_2;
}

void Arena::draw(sf::RenderWindow *window)
{
  ball->draw(window);
  paddle_1->draw(window);
  paddle_2->draw(window);

  text_1 = sf::Text(font, "Score: " + std::to_string(paddle_1_points), 20);
  text_2 = sf::Text(font, "Score: " + std::to_string(paddle_2_points), 20);

  text_1.setPosition({10, height - 30});
  text_2.setPosition({width - 90, height - 30});

  window->draw(text_1);
  window->draw(text_2);
}

void Arena::update(sf::Time time)
{
  ball->update(time);

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    paddle_1->move_up(time);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    paddle_1->move_down(time);

  int paddle_2_move = agent->decide({paddle_1->get_position().y,
                                     paddle_2->get_position().y,
                                     ball->get_position().x,
                                     ball->get_position().y});
  if (paddle_2_move == 1)
    paddle_2->move_up(time);
  else if (paddle_2_move == 2)
    paddle_2->move_down(time);

  if (check_paddle_collision(paddle_2) && !already_learned)
  {
    agent->learn(1);
    already_learned = true;
  }

  if (!check_paddle_collision(paddle_1) && !check_paddle_collision(paddle_2))
    already_learned = false;

  if (check_paddle_collision(paddle_1) or check_paddle_collision(paddle_2))
  {
    ball->invert_x();
  }

  check_score();
}

bool Arena::check_paddle_collision(Paddle *paddle)
{
  sf::Vector2f ball_position = ball->get_position();
  sf::Vector2f paddle_position = paddle->get_position();
  sf::Vector2f paddle_size = paddle->get_size();
  float ball_diameter = ball->get_diameter();

  return (ball_position.x <= paddle_position.x + paddle_size.x) and
         (ball_position.x + ball_diameter >= paddle_position.x) and
         (ball_position.y <= paddle_position.y + paddle_size.y) and
         (ball_position.y + ball_diameter >= paddle_position.y);
}

void Arena::check_score()
{
  sf::Vector2f ball_position = ball->get_position();

  if (ball_position.x < 0)
  {
    paddle_2_points++;

    reset_arena();
  }
  else if (ball_position.x > width)
  {
    paddle_1_points++;

    agent->learn(-1);

    reset_arena();
  }
}

void Arena::reset_arena()
{
  paddle_1->set_position(height / 2 - paddle_1->get_size().y / 2);
  paddle_2->set_position(height / 2 - paddle_2->get_size().y / 2);
  static std::mt19937 rng(std::random_device{}());
  std::uniform_real_distribution<float> dist(ball->get_diameter(), height - ball->get_diameter());
  ball->set_position(width / 2, dist(rng));
}