# Static Members of a C++ Class

When a member of a class is defined with the modifier `static` no matter how
many objects of the class are created, there is only one copy of the static
member.

This static member is shared by all objects of the class. All static data is
initialized to zero **when the first object is created** if no other
initialization is present.

## Static function members

When a method of a class is declared as static, this method can be called
without the need of creating an instance of the class, this method can be
called with the resolution operator `::`. Static member functions have a class
scope and they **do not have access to the `this` pointer**.

### Rules for static data members

* A `const` static data member of integral or enumeration type can be
initialized in class with a constant expression.
* A `constexpr` static data member MUST be initialized in class with a constant
expression.
C++17 no longer requires an initializer when the default constructor initializes
every member. Also `constexpr` static data members  are implicitly inline 
variables, which makes their declaration a definition,
* Other kinds of static data members can have an initializer at their definition

* `static` members must already be constructed before the main is entered.

The `static` keyword is used **only** with the decalaration of a static memeber,
inside the class definition, but **not** with the definition of that static 
member.

```cpp
class X{static int n;}
int X::n = 1;
```

Static data members are no associated with any object. They exist even if no
objects of the class have been defined. There's only one instane of the static
data member in the entire program; **unless** the keyword `thread_local` is
used, in which case there is one instance per thread with thread storage 
duration.

**Static data members cannot be `mutable`**

## The `static` initialization order Fiasco

### How to avoid it?