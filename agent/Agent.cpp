#include "Agent.h"
#include <algorithm>

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
  return choose_action(forwarded);
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