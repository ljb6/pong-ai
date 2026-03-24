#include <vector>

class Layer
{
public:
  Layer(int n_inputs, int n_neurons);

  std::vector<float> forwardPass(const std::vector<float> &inputs);

private:
  std::vector<std::vector<float>> weights;
  std::vector<float> bias;
};