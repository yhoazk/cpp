# C++ lambda expressions



A lambda expression is an unnamed function object capable of capturing variables
in scope.

### Syntax

This is the full declaration.
> [capture-list](params)mutable constexpr exception attribute->ret{body}

declaration of a const lambda: The objects captured by copy cannot be modified.
> [capture-list](params)->ret{body}



#### Lambda capture
The `capture-list` is a comma-separated list of zero or more captures, optionally
beginning with the capture-default.
The only capture defaults are:
* `&` Implicitly catch the odr-used automatic variables and `*this` by reference
* `=` Implicitly catch the odr-used automatic variables by copy and Implicitly catch
  `*this` by reference if this is odr-used




`odr-used`:
