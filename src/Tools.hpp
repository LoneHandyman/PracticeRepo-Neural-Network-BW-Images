#ifndef _SOURCE_TOOLS_HPP_
#define _SOURCE_TOOLS_HPP_

#include <algorithm>
#include <chrono>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <vector>

namespace nn{
  std::default_random_engine randomGen(std::chrono::system_clock::now().time_since_epoch().count());
  
  struct NNMatrixNxM{
    NNMatrixNxM(){}

    NNMatrixNxM(std::size_t N, std::size_t M, std::string filling_mode = "none"){
      body.resize(N);
      for(std::vector<double>& row : body){
        row.resize(M);
      }
      N_ = N; M_ = M;
      if(filling_mode != "none"){
        std::uniform_real_distribution<double> distribution(-1.0,1.0);
        for(std::size_t rowidx = 0; rowidx < N; ++rowidx){
          for(std::size_t colidx = 0; colidx < M; ++colidx){
            if(filling_mode == "null")
              body[rowidx][colidx] = 0;
            else if(filling_mode == "random")
              body[rowidx][colidx] = distribution(randomGen);
          }
        }
      }
    }

    NNMatrixNxM operator*(const NNMatrixNxM& other){
      try{
        if(N_ != other.M_)
          throw EXIT_FAILURE;
      }
      catch(int mode){
        std::cerr << "El # de columnas de la matriz $A no es igual al # de filas de $B." << std::endl;
        exit(mode);
      }
      NNMatrixNxM ans(N_, other.M_, "null");
      for(std::size_t rowidx = 0; rowidx < ans.N_; ++rowidx){
        for(std::size_t colidx = 0; colidx < ans.M_; ++colidx){
          for(std::size_t vsame = 0; vsame < M_/*or N_*/; ++vsame){
             ans.body[rowidx][colidx] += body[rowidx][vsame] * other.body[vsame][colidx];
          }
        }
      }
      return ans;
    }

    std::vector<double>& operator[](std::size_t idx) {
      return body[idx];
    } 

    std::size_t get_sdim(char id){
      if(id == 'M') return M_;
      if(id == 'N') return N_;
    }
  private:
    std::vector<std::vector<double>> body;
    std::size_t N_, M_;
  };
}

#endif //_SOURCE_TOOLS_HPP_