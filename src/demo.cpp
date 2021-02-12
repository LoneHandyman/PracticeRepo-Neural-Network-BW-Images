#include "NeuralNetwork.hpp"

int __cdecl main(){
  nn::Neuron new_neuron(5, nn::predef_functions::sigmoid);
  new_neuron.printInfo();
  std::vector<double> data = {0.12,2.3,0.2,0.22,0.05};
  new_neuron.onProcessing(data);
  std::cout << new_neuron.onSynapsis() << std::endl;
  return EXIT_SUCCESS;
}