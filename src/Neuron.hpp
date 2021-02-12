#ifndef _SOURCE_NEURON_HPP_
#define _SOURCE_NEURON_HPP_

#include "TransferFunction.hpp"

#include <chrono>
#include <iostream>
#include <memory>
#include <random>
#include <vector>

namespace nn{
  std::default_random_engine random(std::chrono::system_clock::now().time_since_epoch().count());
  struct Neuron{
    Neuron(const std::size_t inputs, const std::function<double(double)>& activation){
      std::uniform_real_distribution<double> distribution(-1.0,1.0);
      ptrTransferFunc = std::make_shared<TransferFunction>(activation);
      inputWeights.resize(inputs);
      numOfDentrites = inputs;
      for(double& val : inputWeights){
        val = distribution(random);
      }
      bias = distribution(random);
    }

    void printInfo(){
      std::cout << "Weights:" << std::endl;
      for(double& val : inputWeights){
        std::cout << '\t' << val << std::endl;
      }
      std::cout << "Bias: " << bias << std::endl;
    }

    void onProcessing(const std::vector<double>& inputValues){
      outPutValue = 0.0;
      for(std::size_t idx = 0; idx < numOfDentrites; ++idx){
        outPutValue += inputValues[idx] * inputWeights[idx];
      }
    }

    double onSynapsis(){
      //std::cout << "Transfer Function: " << (*ptrTransferFunc)(-1.2) << std::endl;
      //std::cout << "Desc. Gradient Function: " << ptrTransferFunc->d$(-1.2) << std::endl;
      return (*ptrTransferFunc)(outPutValue);
    }

  private:
    std::shared_ptr<TransferFunction> ptrTransferFunc;
    std::vector<double> inputWeights;
    std::size_t numOfDentrites;
    double outPutValue, bias;
  };
}

#endif //_SOURCE_NEURON_HPP_