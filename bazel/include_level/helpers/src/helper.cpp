#include "helper.h"

bool helper::print_help(int times){
  for(size_t k=times; k>0; --k){
    std::cout << first::helpers_id << '\n';
  }
  return true;
}

bool helper::print_help2(int times){
  times *= 2;
  for(size_t k=times; k>0; --k){
    std::cout << second::helpers_id2 << '\n';
  }
  return true;
}