

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
apply yto type deduction. The arguments must match exaclty.

When declaring call parameters by value, only trivial conversions that `decay`
are supported: Qualifications with const or volatile are ignored. References
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

###
