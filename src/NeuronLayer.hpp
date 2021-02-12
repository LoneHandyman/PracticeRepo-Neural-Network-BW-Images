#ifndef _SOURCE_NEURON_LAYER_HPP_
#define _SOURCE_NEURON_LAYER_HPP_

#include "Neuron.hpp"

namespace nn{
  struct NeuronLayer{
    NeuronLayer(){}

    NeuronLayer(const std::size_t numOfDentrites, const uint32_t numOfNeurons){
      this->numOfDentrites = numOfDentrites;
      for(uint32_t counter = 1; counter <= numOfNeurons; ++counter){
        setOfNeurons.emplace_back(numOfDentrites, predef_functions::sigmoid);
      }
    }
  private:
    std::vector<Neuron> setOfNeurons;
    std::size_t numOfDentrites;
  };
}

#endif //_SOURCE_NEURON_LAYER_HPP_