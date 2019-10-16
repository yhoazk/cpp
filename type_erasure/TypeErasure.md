# Type Erasure

The typical way to achieve polymorphism in C++ is to define an interface
consisting of a pure-virtual method you want to be able to call. Then, for each
implementation that will be used polymorphically, a sub-class inherits from the
base class and implements those virutal methods.

- - -

http://davekilian.com/cpp-type-erasure.html
