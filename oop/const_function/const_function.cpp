#include <bits/stdc++.h>

template<class T>
void print_iter(T& container){
  for(const auto& item : container){
    std::cout << static_cast<int>(item) << std::endl;
  }
}


class test_class{
  int a;
  int c;
  mutable bool mutti;

  public:
  test_class(): a(6), c(5), mutti(true)
  {
  }
    int const_function(int in_arg) const //<- the const at the end is like sending a const this ptr
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

/** Class with a const function is able to change other vars
 * in which are not members ie temporal vars in a function
 */

class change_vars{
  public:
  bool change_var(std::vector<uint8_t>& tgt) const {
    for(auto x : tgt){
      tgt.push_back(x++);
    }
  }


  bool call_change(void){
    std::vector<uint8_t> test = {1,2,3,34};
    size_t n = test.size();
    print_iter(test);
    std::cout << "---------------\n";
    if(change_var(test)){
      std::cout << "alles ok" << std::endl;
    }

    print_iter(test);
    return(n == test.size());
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

  std::cout << "------ Const test -------\n";

  change_vars chv;
  chv.call_change();
  return 0;
}
