#include <vector>
#include "Layer.h"

class NeuralNetwork
{
public:
  NeuralNetwork(std::vector<int> n_layers);

  std::vector<float> forward(const std::vector<float> &inputs);

private:
  std::vector<Layer> layers;

  std::vector<float> softmax(std::vector<float> input);
};