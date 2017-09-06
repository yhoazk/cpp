#include <iostream>
#include <typeinfo>
using namespace std;
//template<class T>

class ov
{
public:
  struct n
  {
    int t;
  };
  int k;
  ov(): k(2){};
  void operator()(int n)
  {
    cout << n << endl;
  }
  /* Here ther argument is ingored or is called with value == 0 */

  void operator++(int l){
    cout << k++  << "k++ l:" <<  l<< endl;
  }

  operator bool() const
  {
    cout << "converted to bool" << endl;
    return 1==1;
  }

  n* operator->()
  {
    n* q = new n;
    q->t = 6;
    return q;
  }

  /* Overloading the multiply  */
  int operator*(int n)
  {
    std::cout << "multiply: n== " << n << '\n';
    return k*n;
  }
/*
  ov operator*(const int lhs, const ov& rhs)
  {
    std::cout << "sec multiply: n== "  << '\n';
    return 100;
  }*/



  int operator*()
  {
    std::cout << "dereference operatr" << '\n';
    return k;
  }
};

int operator*(const int lhs, const ov& rhs)
{
  std::cout << "overloaded * second" << '\n';
  return 100;
}


int main(int argc, char const *argv[]) {
  ov overloaded;
  overloaded(5);
  overloaded++;
  overloaded++;
  if(bool(overloaded))
  {

    std::cout << "class name: " << typeid(overloaded).name()<< '\n';
  }
  std::cout << "ov->" << overloaded->t <<'\n';

  auto x = *overloaded;
  std::cout << "*overloaded: " << x << '\n';

  auto y = overloaded * 8;
  std::cout << "overloaded*8: " << y << '\n';


  auto z = 5 * overloaded;
  std::cout << "5*overloaded: " << z << '\n';
  return 0;
}
