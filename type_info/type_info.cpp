#include <iostream>
#include <typeinfo>

class tst
{
  public: 
    int i;
    int test(int k)
    {
      return k*k;
    }
};

int main()
{
  int k = 0;
  const int ck = 0;
  char c_type = 'e';
  double d_type = 0.25;
  tst* t = new tst();
  std::cout << typeid(k).name() << std::endl;
  std::cout << typeid(ck).name() << std::endl;
  std::cout << typeid(c_type).name() << std::endl;
  std::cout << typeid(d_type).name() << std::endl;
  std::cout << typeid(t).name() << std::endl;
  return 0;
}
