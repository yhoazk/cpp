#include "first/helpers.h"
#include "second/helpers_2.h"

bool print_help(int times){
  for(size_t k=times; k>0; --k){
    std::cout << helpers_id << '\n'; 
  }
  return true;
}

bool print_help2(int times){
  times *= 2;
  for(size_t k=times; k>0; --k){
    std::cout << helpers_id2 << '\n'; 
  }
  return true;
}