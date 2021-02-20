#ifndef _SOURCE_NEURON_LAYER_HPP_
#define _SOURCE_NEURON_LAYER_HPP_

#include "NNFunction.hpp"
#include "Tools.hpp"

namespace nn{
  class NNLayer {
    NNMatrixNxM weights;
    std::shared_ptr<NNFunction> ptrTransferFunc;
  public:
    NNLayer() {}
    NNLayer(const std::function<double(double)>& activation, 
                                      uint32_t numOfNeurons, 
                                      uint32_t numOfLinksLL = 1) {
      ptrTransferFunc = std::make_shared<NNFunction>(activation);
      weights = NNMatrixNxM(numOfNeurons, numOfLinksLL, "random");
    }

    NNMatrixNxM onSynapsis(NNMatrixNxM& invars){//Nx1 invars
      NNMatrixNxM weightedSum = weights * invars;// Calculating weighted sum
      for(std::size_t rowidx = 0; rowidx < weightedSum.get_sdim('N'); ++rowidx)
        weightedSum[rowidx][0] = (*ptrTransferFunc)(weightedSum[rowidx][0]);//Activation
      return weightedSum;
    }
    
  };
}

#endif //_SOURCE_NEURON_LAYER_HPP_