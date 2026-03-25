#include "Agent.h"
#include <algorithm>
#include <iostream>

Agent::Agent(std::vector<int> n_layers, float width, float height) : nn(n_layers)
{
  this->width = width;
  this->height = height;
}

// 0 - stop
// 1 - move up
// 2 - move down
int Agent::choose_action(const std::vector<float> &probs)
{
  return std::max_element(probs.begin(), probs.end()) - probs.begin();
}

std::vector<float> Agent::normalize(const std::vector<float> &state)
{
  std::vector<float> output(state.size());
  for (size_t i = 0; i < 2; i++)
    output[i] = state[i] / height;

  output[2] = state[2] / width;
  output[3] = state[3] / height;

  return output;
}

int Agent::decide(const std::vector<float> &state)
{
  std::vector<float> normalized = normalize(state);
  std::vector<float> forwarded = nn.forward(normalized);

  static int frame_count = 0;
  frame_count++;

  if (frame_count % 100 == 0)
  {
    std::cout << "probs: ";
    for (float p : forwarded)
      std::cout << p << " ";
    std::cout << "\n";
  }

  int choosen_action = choose_action(forwarded);

  Episode episode = {
      forwarded,
      choosen_action};

  history.push_back(episode);

  return choosen_action;
}

std::vector<float> Agent::compute_grad(const std::vector<float> &forward_res, int selected_i, int reward)
{
  size_t size = forward_res.size();
  std::vector<float> grad(size);

  for (size_t i = 0; i < size; i++)
  {
    if (i == selected_i)
      grad[i] = (forward_res[i] - 1) * reward;
    else
      grad[i] = forward_res[i] * reward;
  }

  return grad;
}

void Agent::learn(int reward)
{
  size_t h_size = history.size();
  for (size_t i = 0; i < h_size; i++)
  {
    std::vector<float> grad = compute_grad(history[i].probs, history[i].decision, reward);
    nn.backward(grad, learning_rate);
  }

  history.clear();
}