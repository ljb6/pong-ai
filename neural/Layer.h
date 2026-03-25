#include <vector>

class Layer
{
public:
  Layer(int n_inputs, int n_neurons);

  std::vector<float> forward_pass(const std::vector<float> &inputs);
  std::vector<float> backward_pass(const std::vector<float> &grad_output, float learning_rate);

private:
  std::vector<std::vector<float>> weights;
  std::vector<float> bias;
  std::vector<float> last_input;
  std::vector<float> last_output;
};