#include <iostream>
#include <typeinfo>
using namespace std;
//template<class T>

class ov
{
public:
  int k;
  ov(): k(0){};
  void operator()(int n)
  {
    cout << n << endl;
  }
  /* Here ther argument is ingored or is called with value == 0 */

  void operator++(int l){
    cout << k++  << " l:" <<  l<< endl;
  }

  operator bool() const
  {
    cout << "converted to bool" << endl;
    return 1==1;
  }

};


int main(int argc, char const *argv[]) {
  ov overloaded;
  overloaded(5);
  overloaded++;
  overloaded++;
  if(bool(overloaded))
  {

    std::cout << "/* message */" << typeid(overloaded).name()<< '\n';
  }

  return 0;
}
