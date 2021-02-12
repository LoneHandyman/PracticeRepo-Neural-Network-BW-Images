#ifndef _SOURCE_NEURON_HPP_
#define _SOURCE_NEURON_HPP_

#include "TransferFunction.hpp"

#include <iostream>
#include <memory>
#include <vector>

namespace nn{
  struct Neuron{
    Neuron(std::size_t inputs, const std::function<double(double)>& activation){
      ptrTransferFunc = std::make_shared<TransferFunction>(activation);
      inputWeights.resize(inputs);
      for(double& val : inputWeights){
        val = static_cast<double>(rand() / RAND_MAX);
      }
    }

    void onProcessing(const std::vector<double>& inputValues){
      
    }

    void onSynapsis(){
      std::cout << "Transfer Function: " << (*ptrTransferFunc)(-1.2) << std::endl;
      std::cout << "Desc. Gradient Function: " << ptrTransferFunc->d$(-1.2) << std::endl;
    }

  private:
    std::shared_ptr<TransferFunction> ptrTransferFunc;
    std::vector<double> inputWeights;
    double outPutValue, bias;
  };
}

#endif //_SOURCE_NEURON_HPP_