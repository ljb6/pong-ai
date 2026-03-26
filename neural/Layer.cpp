#include "Layer.h"
#include <random>
#include <fstream>

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

std::vector<float> Layer::forward_pass(const std::vector<float> &inputs, bool apply_relu)
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

    if (apply_relu)
      output[i] = std::max(0.0f, sum);
    else
      output[i] = sum;
  }

  return output;
}

std::vector<float> Layer::backward_pass(const std::vector<float> &grad_output, float learning_rate, bool apply_relu)
{
  size_t n_neurons = weights.size();
  size_t n_inputs = last_input.size();

  std::vector<float> grad_input(n_inputs, 0.0f);

  for (size_t i = 0; i < n_neurons; i++)
  {
    float delta = apply_relu ? grad_output[i] * (last_output[i] > 0 ? 1.0f : 0.0f) : grad_output[i];

    for (size_t j = 0; j < n_inputs; j++)
    {
      grad_input[j] += delta * weights[i][j];
      weights[i][j] -= learning_rate * delta * last_input[j];
    }
    bias[i] -= learning_rate * delta;
  }

  return grad_input;
}

void Layer::save(std::ofstream &file)
{
  for (size_t i = 0; i < weights.size(); i++)
    for (size_t j = 0; j < weights[i].size(); j++)
      file << weights[i][j] << " ";

  file << "\n";

  for (size_t i = 0; i < weights.size(); i++)
    file << bias[i] << " ";

  file << "\n";
}

void Layer::load(std::ifstream &file)
{
  for (size_t i = 0; i < weights.size(); i++)
    for (size_t j = 0; j < weights[i].size(); j++)
      file >> weights[i][j];

  for (size_t i = 0; i < weights.size(); i++)
    file >> bias[i];
}