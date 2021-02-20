#ifndef _SOURCE_NEURAL_NET_HPP_
#define _SOURCE_NEURAL_NET_HPP_

#include "NeuronLayer.hpp"

#include <array>

namespace nn{
  template<std::size_t NUM_OF_LAYERS = 1>
  class MultiLayerPerceptron{
    std::array<NNLayer, NUM_OF_LAYERS> topology;
  public:
    MultiLayerPerceptron(const std::array<uint32_t, NUM_OF_LAYERS> rawTopology){
      topology[0] = NNLayer(predef_functions::sigmoid, rawTopology[0]);
      for(std::size_t idx = 1; idx < NUM_OF_LAYERS; ++idx){
        topology[idx] = NNLayer(predef_functions::sigmoid,
                                          rawTopology[idx],
                                          rawTopology[idx - 1]);
      }
    }

    std::vector<double> getAnswer(const std::vector<double>& inputLayerData){
      std::vector<double> outputValues = topology[0].keepForward(inputLayerData);
      for(std::size_t idx = 1; idx < numOfLayers; ++idx){
        outputValues = topology[idx].keepForward(outputValues);
      }
      return outputValues;
    }

    std::vector<double> predict(const std::vector<double>& input){

    }

    void train(){

    }
  };
}

#endif //_SOURCE_NEURAL_NET_HPP_
