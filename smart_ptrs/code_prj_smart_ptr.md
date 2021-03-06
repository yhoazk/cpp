# Implementing smart pointers in C++
[g4g](http://www.geeksforgeeks.org/smart-pointers-cpp/)
[cprj](https://www.codeproject.com/Articles/15351/Implementing-a-simple-smart-pointer-in-c)

Smart pointes is a wrapper class over a pointer with overloaded operators like
`*` and `->`. The objects of smart pointer class look like pointer but can do
many things that a normal pointer can't like automatic destruction (we dont have
  to explicitly use delete) reference counting and more.

Since destructor is automatically called when an object goes out if scope, the
dynamically allocated memory would be deleted in the destructor of the class
automatically or the reference count can be decremented.

Consider the following simple smartPtr class:

```cpp
#include <iostream>
using namespace std;

class smartPtr
{
  int *prt; /* the actual pointer*/
public:
  // Constructor
  explicit smartPtr(int *p =NULL)
  {
    ptr = p;
  }

  // Destructor
  ~smartPtr()
  {
    std::cout << "delete ptr" << '\n';
    delete(ptr);
  }
  // overloading dereference operator
  int &operator*()
  {
    std::cout << "return value" << '\n';
    return *ptr;
  }
};

int main()
{
  smartPtr prt(new int());
  *ptr = 20;
  std::cout << "ptr: " << *ptr << '\n';
  /* No need to call delete ptr */
}
```

Expected output:
```
return value
return value
20delete ptr
```

## Can we write one smart pointer class that works for all types?

```cpp
#include<iostream>
using namespace std;

// A generic smart pointer class
template <class T>
class SmartPtr
{
   T *ptr;  // Actual pointer
public:
   // Constructor
   explicit SmartPtr(T *p = NULL) { ptr = p; }

   // Destructor
   ~SmartPtr() { delete(ptr); }

   // Overloading dereferncing operator
   T & operator * () {  return *ptr; }

   // Overloding arrow operator so that members of T can be accessed
   // like a pointer (useful if T represents a class or struct or
   // union type)
   T * operator -> () { return ptr; }
};

int main()
{
    SmartPtr<int> ptr(new int());
    *ptr = 20;
    cout << *ptr;
    return 0;
}
```


```cpp
#include <iostream>

template <typename T> class sp
{
private:
  T* pData;
public:
  SP(T* pvalue) : pData(pValue)
  {

  }
  ~SP()
  {
    delete pData;
  }

  T& operator* ()
  {
    return *pData;
  }

  T* operator->()
  {
    return pData;
  }
};

void main()
{
  SP<person> p (new Person("scott", 23));
  p->display();
}

```
