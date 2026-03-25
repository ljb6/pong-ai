#include <vector>
#include "../neural/NeuralNetwork.h"

struct Episode
{
  std::vector<float> probs;
  int decision;
};

class Agent
{
public:
  Agent(std::vector<int> n_layers, float width, float height);

  int decide(const std::vector<float> &state);
  std::vector<float> compute_grad(const std::vector<float> &forward_res, int selected_i, int reward);
  void learn(int reward);

private:
  float width;
  float height;

  NeuralNetwork nn;
  std::vector<float> normalize(const std::vector<float> &state);
  int choose_action(const std::vector<float> &probs);

  std::vector<Episode> history;

  float learning_rate = 0.01;
};