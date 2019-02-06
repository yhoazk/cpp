#include <iostream>

namespace  mod_x
{
  class xer
  {
  private:
    /* data */
  size_t std_len;
  ID self_id;
  public:
    enum class ID {
      xx, xxx, xxxx, not_used
    };
    xer(size_t l): std_len(l), self_id(ID::xx){};

    ~xer();
    bool print_sqr(const size_t l);
    bool set_id(const ID id); 
  };
  
} // name mod_x
