#ifndef _SOURCE_NN_FUNCTION_HPP_
#define _SOURCE_NN_FUNCTION_HPP_

#include <cmath>
#include <functional>

namespace nn{
  struct NNFunction{
    NNFunction(const std::function<double(double)>& _function){
      defaultFunc = _function;
    }

    double operator()(double x){
      return defaultFunc(x);
    }

    double d$(double x){
      return (defaultFunc(x + h) - defaultFunc(x - h))/(h * 2);
    }

    static double h;
  private:
    std::function<double(double)> defaultFunc;
    std::function<double(double)> derivFunc;
  };

  double NNFunction::h = 0.00001;

  namespace predef_functions{
    std::function<double(double)> sigmoid = [](double x){
      return 1 / (1 + exp(-x));
    };
  }
}

#endif //_SOURCE_NN_FUNCTION_HPP_