#include <iostream>

class test_class{
  int a;
  int c;
  mutable bool mutti;

  public:
  test_class(): a(6), c(5), mutti(true)
  {
  }
    int const_function(int in_arg) const //<- this makes the function const
    {
      // This way the function CANNOT write in class functions
      // The next statement will throw an error
      //a = 55;
      // However the mutable keyword overrides the const on this function
      mutti ^= true; 
      return a;
    }

    int const_function2(int in_arg)
    {
      a = 5; // <- This will compile
      return a;
    }
    bool get_mutti(void){
      return mutti;
    }
};


int main ()
{
  test_class* tc = new test_class();
  tc->const_function2(4);
  for (size_t i = 0; i < 5; i++){
    tc->const_function(8);
    std::cout << "Val of mutti: " << tc->get_mutti() << '\n';
  }
  
  return 0;
}
