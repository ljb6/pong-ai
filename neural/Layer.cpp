#include "Layer.h"
#include <random>

Layer::Layer(int n_inputs, int n_neurons)
{
  std::mt19937 rng(std::random_device{}());
  std::uniform_real_distribution<float> dist(-0.5f, 0.5f);

  weights.resize(n_neurons);
  for (size_t i = 0; i < weights.size(); i++)
  {
    weights[i].resize(n_inputs);
    for (size_t j = 0; j < weights[i].size(); j++)
      weights[i][j] = dist(rng);
  }

  bias.resize(n_neurons);
  std::fill(bias.begin(), bias.end(), 0);
}

std::vector<float> Layer::forward_pass(const std::vector<float> &inputs)
{
  std::vector<float> output(weights.size());
  last_output.clear();
  last_output.resize(weights.size());

  last_input = inputs;

  for (size_t i = 0; i < weights.size(); i++)
  {
    float sum = bias[i];

    for (size_t j = 0; j < weights[i].size(); j++)
      sum += (inputs[j] * weights[i][j]);

    last_output[i] = sum;

    output[i] = std::max(0.0f, sum);
  }

  return output;
}