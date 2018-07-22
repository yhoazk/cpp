# LAMBDAS

What problem does lambdas solve that cannot be solved by using fnc pointers or
function objects? Function pointers have minimal syntactic overhead but do not
retain state within a scope. and function objects can maintain state but
require the syntactic overhead of a class definition.

A lambda combines the benefits of function pointers and function objects
and avoids their disadvantages. Like a funciton objects, a lambda is flexible
and can maintain state, but unlike a function object, its compact syntax
doesn't require an explicit class definition. By using lambdas, you can write
code that is less cumbersome and less prone to errors.

Syntax:
```
[ ]( ){ }
 ^  ^  ^
 |  |  |
 |  |  `-- Function implementation
 |  `----- List of input parameters
 `-------- Capture list
```

## Example

```cpp
auto l = [](int x, int y){ return x + y;};
// Get the sum of 1+1
std::cout << l(1,1) << std::endl;
```


## Capture list vs parameters

https://stackoverflow.com/questions/28669941/c-lambdas-capture-list-vs-parameter-list/28670097

## Nested lambdas


## `constexpr` Lambdas (std:c++17)

A lambda expression may be declared as `constexpr` or used in a constant
expression. A lambda is implicitly `constexpr` if its result satisfies the
requirements of a `constexpr`.

```c++
int y = 11;
auto ans = []() constexpr
{
    int x = 31;
    return y + x;
}

constexpr int Inc(int n){
    return [n]{return n + 1;}()
}
```

## Function objects

In short a functor is a class that implements the `opertor()`.