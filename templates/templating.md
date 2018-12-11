

Using templates

Functions templates define a family of functions for different template arguments.

When an argument is passed to function parameters depending on template parameters,
function deduce the template parameters to be instantiated for the corresponding
parameter types.

Templates are not compiled into single entities that can handle any type.
Instead, different entities are generated from the template for every type for
which the template is used.


### Two-phase translation

An attempt to instantiate a template for a type that doesnot suppport all the
operations used within it will result in a compile time error.

The two phases of template compilation:

1. Without instantiation at definition time, the template code itself is checked
for correctness ignoring the template paramenters.
  - Syntax errors
  - using unknown types
  - static assertions
2. At instantiation time, the template code is checked again to ensure tht all
coe is valid. That is, now especially, all parts that depend on the template
parameters.

Some compilers do not perform the full checks of the first phase. So you might not
see problems until the template code is instantiated at least once.

### Template argument deduction

The template parameters are determined by the arguments we pass. If we pass
two ints, the c++ compiler concludes that T == int.

But additional cualifiers need to be taken into account.

**Type conversion during type deduction:**

When declaring call parameters by reference, even trivial conversions do not
apply yto type deduction. The arguments must **match exaclty.**S

When declaring call parameters by value, only trivial conversions that `decay`
are supported: Qualifications with `const` or `volatile` are ignored. References
convert to the referened tyoe and raw arrays or funtions convert to the corresponding
pointer type. Also, for two arguments declared with the same template parameter
T the decayed types must match.

When the type needs to be as we specify, there are three ways to create tell the
compiler how to handle the parameter.

1. Cast the argument so that the type matches.
```cpp
static_cast<double>(5)
```
2. Specify or qualify explicitly the type of T to prevent the compiler from
attempting type deduction:

```
max<double>(4, 4.4);
```

3. Specify that the parameters may have different types:


Type deduction does not works for default parameters, this means that when a
function has a default parameter, its type is not assumed to be of the type of
the default value.
```cpp
template<typename T>
void f(T="");

f(1); // T deduced to f<int>(1)
f(); //Error cannot deduce T
```

To support this case, the Type T has to have a default type:

```cpp
template<typename T=std::string>
void f(T="");
f(); // Ok

```

### Multiple Template parameters

Function templtes have two distinct sets of parameters.

1. **Template parameters**: Declared in angle brackets before the function name.
```cpp
template<typename T> // T being the template parameter
```
2. **Call parameters** declared in parentheses after the function template.
```cpp
T max( T a, T b) // a and B are the call parameters
```

Is possible to have any number fo template parameters.
```cpp
template<typename T1, typename T2>
T1 max(T1 a, T2b)
```

The problem with this approach is that the max function will always return T1
and is probably desirable to return a T2, and the return type will depend on the
order of the arguments.

This are some strategies to deal with the situation:
* Introduce a third template parameters for the return type.
* Let the compiler find out the type
* Declare the return type to be the "common type" of the two params.


#### Option 1: Template parameter for return types

```cpp
template<typename T1, typename T2, typename RT>
RT max(T1 a, T2 b)
```

Then call the funciton as follows:

```cpp
::max<int, double, double>(4,7.2); // Which is ok, but tedious.
```

#### Option2 Deducing the return type

Since C++14 is possible not to declare the return type and let the compiler to
do the job. We just need to specify the return type as auto.

```cpp
template<typename T1, typename T2>
auto max(T1 a, T2 b) { return b < a? a:b;}
```
With the use of `auto` without the corresponding **trailing return type** ->
indicates that the return type must be deduced from the return statement in the
function body.

```cpp
template<typename T1, typename T2>
auto max(T1 a, T2 b) -> decltype(b<a?a:b)
{
  return b < a? a:b;
}
```

Note that:
```cpp
template<typename T1, typename T2>
auto max(T1 a, T2 b) -> decltype(b<a?a:b);
```

Is a declaration, so that the compiler uses the rules of the `operator?:` called
for parameters `a` and `b` to find out the return type. The implementation does
not hae to match, In fact usign `true` as the condition for `operator?:` is
enough.

```cpp
template<typename T1, typename T2>
auto max(T1 a, T2 b) -> decltype(true?a:b);
```
however this definition has drawbacks, it might happen that the return type is a
reference. For this reason we should return the type `decayed` from T.

```cpp
#include <type_traits>

template<typename T1, typename T2>
auto max(T1 a, T2 b) ->typename std::decay<decltype(true?a:b)>::type
{
  return b<a?a:b;
}

```


Here the type trait `std::decay<>` is used, which returns the resulting type in
a member `type`. Because the member `type` is a type, you have to qualify the
expression with the `typename` to access it.

#### Option 3 Return type as common type


Since C++11 the std library provides a mean to specify
"choosing the more general type"  `std::common_type<>::type` yields the
"common type" of two or more different types passed as template arguments.

```cpp
#include <type_traits>

template<typename T1, typename T2>
std::common_type<T1, T2> max(T1 a, T2 b)
{
  return b<a?a:b;
}

```


The `std::common_type<>` uses metaprogramming to choose the return type from the
rules of the operator `?:`. Thus both `max(4,7.2)` and `max(7.2,4)` return double.


## Default Template arguments
NOTE: The `std::decay_t<>` ensures that no referene is returned.

## Overloading function templates
