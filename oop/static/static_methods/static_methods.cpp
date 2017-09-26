/* Example/demo for static methods */

#include <iostream>

using namespace std;

/* Static member functions have no `this` pointer */
class my_static
{
private:
  static double k;
public:
  my_static()
  {

  }
  static double mult(double x, double y)
  {
    return(x*y);
  }
  double sum(double x, double y)
  {
    return(x+y);
  }
};

/* Static methods need to be initialized outside the class */
double my_static::k = 0;

int main(int argc, char const *argv[]) {
  std::cout << "test static: 5x5:" << my_static::mult(5,5) << '\n'; // ATTENTION: the method is called with :: not . as in other languages
  /* Creating an instance of the class then access it's method */
  std::cout << "Test non static:" << (new my_static())->sum(5,5)  << '\n';
  return 0;
}
