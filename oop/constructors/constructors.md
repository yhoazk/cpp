# Constructors

A constructor is a member function of a class which initializes the objects'
members. The constructor is automatically called when an object is created.

The constructor is different from a normal member function in:

- Constructor has the same name of the class itself
- Constructors dont have return type
- It's automatically called when the object is created
- If the constructor is not specified, the compiler creates a default
constructor. This constructor expects no params and has empty body.

## Types of ctors

### Default Constructor

By definition, the default constructor is the constructir that expects no
parameters.

** Examples of default ctors**:

```cpp
class Foo{
public:
    Foo();
};
```

```cpp
class Foo {
public:
    Foo(int i=3; int j=5);
};
```

### Parametrized Constructors

It's possible to pass arguments to constructors. Typically these arguments are
used to initialize the object when it's created.
This constructor is create when a constructor with arguments is declared.

```cpp
class Foo {
public:
    Foo(int i; int j);
};
```

### Move Constructor

A move ctor is a class T is a non-template ctor whose first parameter is `T&&`,
`const T&&`, `volatile T&&` or `const volatile T&&` and either there are no
parameters, or the rest of the parameters have default values.

```cpp
class Foo {
public:
    Foo(Foo&&); // Move ctor
};

- The move ctor is called when an obj `aT` is initialized with `std::move(T)`
- AS function argument `f(std::move(aT))` where `aT` is of type `T` and `f` is
 `void F(T t)`
- As function return: `return a;` inside a function such as `T f()`
### Copy Constructors

A copy constructor is a member function which initializes an object using 
another object of the same class. A copy ctor has the following function 
prototype:

```cpp
className(const className &old_obj);
```


#### When is the copy constructor called?

1. When an object of the class is returned by value
2. When an object of the class is passed to a function by value as an arg
3. When an object is constructed based on another object of the same class
4. When the compiler generates a temporary object

It is not guaranteed that a copy constructor will be called in all these
cases, because C++ Std. allows the compiler to optimize the copy away.

#### When is necesary to defina a copy ctor?

If we do not define a copy ctor, the compiler generates one and does a
member-wise copy between objects. A copy ctor needs to be defined if an object
has pointers or any run time allocation of the resources it handles, Eg file
handle, network connection, etc.

Is important to notice that the **default copy ctor, makes a shallow copy**. This
means that the memory is the same for src and dst objects.
**Deep copy is possible only with user defined copy ctor**