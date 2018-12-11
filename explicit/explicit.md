# C++ `explicit` keyword

In `C++`, a constructor with only one required parameter is considered an
**implicit** conversion function. It converts the parameter type to the
class type. Whether this is a good thing or not depends on the semantics
of the constructor.

For example, if you have a string class with constructor `String(const char* s)`
 that's probably exactly what you want. You can pas a `const char*` to a
 function expecting a `String`, and the compiler will automatically
 construct a temporary `String` object for you.

 On the other hand, if you have a buffer class whose constructor
 `buffer(int size)` takes the size of the buffer in bytes, you probably don't
 want the compiler to quietly turn `int`s into `buffer`s. To prevent that, you
 declare that, you declare the constructor with the `explicit` keyword.

 ```cpp
 class buffer {
   explicit buffer(int size);
 }
 ```
 That way
 ```cpp
 void useBuffer(buffer& buf);
 useBuffer(4);
 ```
 becomes a compile-time error, if you want to pass a temporary `buffer` object,
 you have to do so explicitly.

 ```cpp
 useBuffer(buffer(4)); // This creates a buffer of size 4 explicitly
 ```

 In summary, if your single-parameter constructor converts the parameter into an
 object of your class, you probably dont want to use the `explcit` keyword. But
 if you have a constructor that simply happens to take a single parameter, you
 should declare it as `explcit` to prevent the compiler from surprising you with
 unexpected conversions.
