#include <iostream>

class nonVirtDestrBase{
  public:
  ~nonVirtDestrBase(){
    std::cout << "In base destructor" << std::endl;
  }

  int getVal() { return 222; }

};

class derived : public nonVirtDestrBase{
  public:
  ~derived(){
    std::cout << "in derived destructor" << std::endl;
  }
  
  int getVal(){
    return (int) 9;
  }

};


int main(int, char**)
{
    // object with automatic storage, mainly stack
    {
      derived d;
      d.getVal();
    } // As the object is in automatic storage and is not longer referenced is deleted.
    std::cout << "flushing" << std::endl;
    // object with dynamic stirage, mainly the heap.
    derived* dd = new derived();
    dd->getVal();
    delete dd;
    std::cout << "Now the test for the derived class destructor\n";
    nonVirtDestrBase* base = new derived();
    base->getVal();
    delete base;
    std::cout << "Here the derived constructor was never called, only the base constructor\n";
    // in which case is expected to have a derived class assigned to a base class
    return 0;
}
