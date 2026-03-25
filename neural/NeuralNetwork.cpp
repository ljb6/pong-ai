#include "NeuralNetwork.h"
#include <algorithm>
#include <cmath>

NeuralNetwork::NeuralNetwork(std::vector<int> n_layers)
{
  size_t size = n_layers.size();

  layers.reserve(size - 1);

  for (size_t i = 0; i < size - 1; i++)
  {
    layers.emplace_back(n_layers[i], n_layers[i + 1]);
  }
}

std::vector<float> NeuralNetwork::forward(const std::vector<float> &inputs)
{
  std::vector<float> output = layers[0].forward_pass(inputs);

  for (size_t i = 1; i < layers.size(); i++)
  {
    output = layers[i].forward_pass(output);
  }

  return softmax(output);
}

std::vector<float> NeuralNetwork::softmax(std::vector<float> input)
{
  size_t size = input.size();
  std::vector<float> output(size);

  float max_val = *std::max_element(input.begin(), input.end());
  float sum = 0;

  for (size_t i = 0; i < size; i++)
  {
    output[i] = std::exp(input[i] - max_val);
    sum += output[i];
  }

  for (size_t i = 0; i < size; i++)
    output[i] /= sum;

  return output;
}