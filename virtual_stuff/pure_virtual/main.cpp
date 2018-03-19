#include "impl_class.hpp"
#include <iostream>

using namespace std;
int main(int, char**)
{
  impl_bool *b = new impl_bool();
  impl_int *i = new impl_int();
  if(b->v_method()){
    cout << "works\n";
  }
  else
  {
    cout << "NO works\n";
  }

  cout << "Int Method: " << i->v_method() * i->v_method() << endl;
  return 0;
}
