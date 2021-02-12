#include "NeuralNetwork.hpp"

int __cdecl main(){
  nn::Neuron new_neuron(nn::predef_functions::sigmoid);
  new_neuron.onSynapsis();
  return EXIT_SUCCESS;
}