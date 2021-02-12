#ifndef _SOURCE_NEURAL_NETWORK_HPP_
#define _SOURCE_NEURAL_NETWORK_HPP_

#include "NeuronLayer.hpp"

#include <array>

namespace nn{
  template<std::size_t numOfLayers>
  class NeuralNetwork{
    std::array<NeuronLayer, numOfLayers> topology;
  public:
    NeuralNetwork(const std::size_t inputLayerDentrites,
                  std::array<uint32_t, numOfLayers>& rawTopology){
      topology[0] = NeuronLayer(inputLayerDentrites, rawTopology[0]);
      for(std::size_t idx = 1; idx < numOfLayers; ++idx){
        topology[idx] = NeuronLayer(static_cast<std::size_t>(rawTopology[idx - 1]), rawTopology[idx]);
      }
    }
  };
}

#endif //_SOURCE_NEURAL_NETWORK_HPP_