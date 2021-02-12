#include "NeuralNetwork.hpp"

int __cdecl main(){
  nn::NeuralNetwork<5> new_neural_net(3, {2,4,8,4,1});
  std::vector<double> varInputs = {0.012,0.25,0.69};
  for(double& ans : new_neural_net.getAnswer(varInputs)){
    std::cout << ans << std::endl;
  }
  return EXIT_SUCCESS;
}