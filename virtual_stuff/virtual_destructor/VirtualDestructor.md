# Virtual Destructors


A class with at least one vitual pure functions is abstract and it can't 
be used to create a new object from it. This means that the class was meant to
be inherited. 

```cpp
virtual void f() = 0; // This is a pure virtual function
```

The `=0` mark a function as a pure virtual


When a parent class has virutal functions, the derived classes do **not**
need to implement **all** the virtual methods, but they *do* need to 
implement the pure ones.

The destructor of a class has to be virtual if we intend to inherit from it.
Otherwise the destructir of the derived class will not be called when you 
delete an object through a base pointer, and you'll get corrupted program
states like memory leaks.


