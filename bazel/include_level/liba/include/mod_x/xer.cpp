#include "xer.h"

namespace mod_x {
  bool xer::print_sqr(const size_t l){
    for(size_t i = 0; i < l; i++){
      for(size_t j=0; j < l;  j++){
        std::cout << "#";
      }
      std::cout << '\n';
    }
  }

  bool xer::set_id(const xer::ID id){
    if(xer::ID::not_used != id){
      std::cout << "Update id\n";
      self_id = id;
    } else {
      std::cout << " Given the not used id\n";
    }
  }
}