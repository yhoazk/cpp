#include <iostream>

class test_class{
  int a;
  int c;

  test_class(): a(6), c(5)
  {
  }
  public:
    int const_function(int in_arg) const //<- this makes the function const
    {
      // This way the function CANNOT write in class functions
      // The next statement will throw an error
      //a = 55;
      return a;
    }

    int const_function2(int in_arg)
    {
      a = 5; // <- This will compile
      return a;
    }
};


int main ()
{
  test_class* tc = new test_class();
  tc->const_function2(4);
  return 0;
}
