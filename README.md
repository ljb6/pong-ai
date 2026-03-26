# Pong AI

A Pong game where an AI agent learns to play from scratch using a neural network trained with **Policy Gradient Reinforcement Learning** — built entirely from the ground up in C++ with no ML libraries.

![C++17](https://img.shields.io/badge/C%2B%2B-17-blue)
![SFML 3](https://img.shields.io/badge/SFML-3-green)

## Highlights

- **Neural network from scratch** — fully connected layers, backpropagation, softmax, and ReLU implemented without any ML framework
- **REINFORCE with baseline** — policy gradient algorithm with variance reduction for stable training
- **Discounted rewards** — temporal credit assignment so the agent knows which actions mattered most
- **Persistent training** — weights are saved to disk and reloaded on startup, allowing incremental training across sessions

## How It Works

### Architecture

```
Game State [4] → Hidden Layer [8, ReLU] → Output [3, Softmax] → Action
```

The agent observes 4 normalized inputs:

| Input               | Description                |
| ------------------- | -------------------------- |
| `paddle_self_y`     | Agent's paddle position    |
| `paddle_opponent_y` | Opponent's paddle position |
| `ball_x`            | Ball horizontal position   |
| `ball_y`            | Ball vertical position     |

And outputs a probability distribution over 3 actions: **stop**, **move up**, **move down**.

### Training Loop

1. Each frame, the agent observes the game state and samples an action from the network's output distribution
2. When a point ends (+1 for scoring, -1 for conceding), the agent backpropagates through every frame of the rally
3. A **discount factor** (0.99) weights recent actions more heavily than earlier ones
4. A **moving average baseline** is subtracted from the reward to reduce gradient variance — this prevents the network from collapsing to a single action when rewards are predominantly negative

### Key Techniques

| Technique                   | Purpose                                                                                   |
| --------------------------- | ----------------------------------------------------------------------------------------- |
| Policy Gradient (REINFORCE) | Learn directly from game outcomes without needing a value function                        |
| Baseline subtraction        | Reduce variance — episodes better than average get positive gradients, worse get negative |
| Discounted rewards          | Assign more credit to actions taken closer to the outcome                                 |
| Softmax exploration         | The agent naturally explores by sampling from its output distribution                     |

## Project Structure

```
pong-ai/
├── main.cpp                 # SFML window and game loop
├── game/
│   ├── Arena.cpp/h          # Game state, collisions, scoring, and training triggers
│   ├── Ball.cpp/h           # Ball physics and wall bouncing
│   └── Paddle.cpp/h         # Paddle movement with configurable velocity
├── neural/
│   ├── NeuralNetwork.cpp/h  # Multi-layer network with softmax, save/load
│   └── Layer.cpp/h          # Forward/backward pass, weight updates
├── agent/
│   └── Agent.cpp/h          # RL agent: action selection, gradient computation, learning
└── CMakeLists.txt
```

## Build & Run

### Prerequisites

- CMake 3.16+
- C++17 compiler
- [SFML 3](https://www.sfml-dev.org/)

### Build

```bash
mkdir build && cd build
cmake ..
make
./PongAI
```

The agent starts training immediately. Weights are saved to `weights.txt` every 10 episodes and reloaded on the next launch.

## Technical Details

- **Weight initialization**: Uniform random in [-0.5, 0.5], biases at zero
- **Learning rate**: 0.0001
- **Discount factor**: 0.99
- **Baseline decay**: 0.99 (exponential moving average)
- **Network parameters**: 68 total (32 weights + 8 biases + 24 weights + 3 biases)
- **Opponent**: Rule-based paddle that tracks the ball at reduced speed (75% of ball velocity), allowing the agent to score occasionally for balanced reward signals
