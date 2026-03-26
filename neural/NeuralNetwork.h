#include <vector>
#include "Layer.h"

class NeuralNetwork
{
public:
  NeuralNetwork(std::vector<int> n_layers);

  std::vector<float> forward(const std::vector<float> &inputs);
  std::vector<float> backward(const std::vector<float> &grad_output, float learning_rate);

  void save(std::string filename);
  void load(std::string filename);

private:
  std::vector<Layer> layers;

  std::vector<float> softmax(std::vector<float> input);
};