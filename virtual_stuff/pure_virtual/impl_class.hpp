
#include "model_class.hpp"


class impl_bool: public model<bool>
{
  public:
  bool v_method();
};

class impl_int: public model<int>
{
  public:
  int v_method();
};
