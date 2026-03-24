#include "NeuralNetwork.h"

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

  return output;
}
