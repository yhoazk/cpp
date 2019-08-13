#include <bits/stdc++.h>

using namespace std;

class non_pod{
  public:
  non_pod(){
    cout << "non pod ctor\n";
    fd = 5;
    name = "";
  }

  non_pod(int a, const string& nm){
    cout << "non pod ctor param\n";
    fd= a;
    name.assign(nm);
  }
  ~non_pod(){
    cout << "Dtor for non pod\n";
  }
  private:
    int fd;
    string name;
};

class demo_ctors{
  public:
    /* default ctor*/
    demo_ctors() {
      std::cout << "demo ctor\n";
      np = make_shared<non_pod>(5,"init");
    }

    // usage of explicit

  shared_ptr<non_pod> np; // This is a prt? Where is his dtor
};

int main(int argc, char const *argv[]){
  std::cout << "fname " << __FILE__ << '\n';
  demo_ctors dc;
  return 0;
}


/*
Nono shared ptr

fname oop/constructors/constructors.cpp
non pod ctor
demo ctor
Dtor for non pod

Shared:

fname oop/constructors/constructors.cpp
demo ctor
non pod ctor param
Dtor for non pod

*/