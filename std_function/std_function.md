# std::function

It's a class template of general purpose.
- It´s a polymorphic function wrapper.
- It can store:
    - lambdas
    - classic functions
    - member functions
    - the result of `std::bind`
        - Bind is a method to bind certain paramenter to a function call and rename it.
- It can be empty, then returns the exception `bad_function_call`

```cpp
using function_name = std::function<return_type(parameter1, parameter2..)>;
```
