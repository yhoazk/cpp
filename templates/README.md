# C++ Templates

C++ Templates is a programming model that allows plugging-in of any data-type to the code 
(Templated code). Without template, you would need to replicate the same code all over again
and again, for all required data-types. And obviously, as said before requires code maintenance.



## The Syntax Drama:

Templates use the angle brackets `<content>`.
<br>
The `content` can be:
1. class T / Type T
2. A data type which maps to T
3. An integral specification
4. An integral constant/pointer/reference which maps to specification mentioned.

For point one and two, the symbol `T` is nothing but some data-type, which can
be any primitive data type or UDT.

For example:
```c
void PrintTwice (int data)
{
    cout << "twice: " << data * 2 << endl;
}
```
In order to print a double a function that accepts double as a input parameter must be created.

```c
void PrintTwice (double data)
{
    cout << "twice: " << data * 2.0f << endl;
}
```

There are two types of templates:

### Function templates

For the example function `PrintTwice` a templated function could be:

```c
template<class TYPE>
void PrintTwice(TYPE data)
{
    cout << "Twice: " << data * 2 << endl;
}
```

Dissecting the code by lines:

`template<class TYPE>`
Tells the compiler that is a function template. The actual meaning of TYPE would be deducted 
by the compiler depending on the argument passed to this function. Here TYPE is known as 
**template type parameter**.

For instance, if we call the function as:
```c
PrintTwice(123);
```

TYPE would be replaced by the compiler as int, and compler would instantiate the template
function as:

```c
void PrintTwice(void data)
{
    cout << "Twice: " << data * 2 << endl;
}
```

For each type an instance of the function `PrintTwice` is created, the code is duplicated, but 
the overloads are instantiated by te compiler and not by the programmer. The true benefit is 
that there no need to copy-paste the same code, or to manually mainain the code for different
data-types, or to wite up a new overload for new data-type that arrives later.
<br>
It is true, also, that the code size will be larger, since there are now two function definitions.
The code size at binary/assembly level would be almost the same. There are advanced compiler/linker
level optimizations which can somewhat reduce the code size, if instantiated functions are same or
some part of functions body is the same.



### How to call a templated function as if the type were a different as the passed.

For example, lets assume that we have this function
```c
void show(int data);
```
Which is called as follows:
```c
show(23);
show('e');
show(55.65);
```

The first call is fine, the second will print the value of the char as int, and the third
one will convert the float 55.65 to 55 and the appropiate compiler warining.
As illogical as it may seems to demand such a thing, here is how it's done:

```c
show<double>(1234);
```

Wth this special syntax `Show<>()` you are demanding compiler to instantiate `show` function for
the type being explicitly passed, and asking the compiler not to deduce the type by function
argument.

#### Function template vs template function.






### Class Templates



### References:
** Idiots guide to templates **
(https://www.codeproject.com/Articles/257589/An-Idiots-Guide-to-Cplusplus-Templates-Part)[https://www.codeproject.com/Articles/257589/An-Idiots-Guide-to-Cplusplus-Templates-Part]

** Template compilation **
(http://stackoverflow.com/questions/19798325/template-compilation)[http://stackoverflow.com/questions/19798325/template-compilation]


** Use `class` or `typename` for template parameters? **
(http://stackoverflow.com/questions/213121/use-class-or-typename-for-template-parameters)[http://stackoverflow.com/questions/213121/use-class-or-typename-for-template-parameters]

The answer seems to be " No, there is no good reason to prefer one over the other"
* They are equivalent
* Some people have reasons to always use `typename`
* Some people have reasons to always use `class`

The general rule:
> Advice is to use `class` if it is expected `T` will always be a class, with `typename`
> if other types (int, char ...) may be expected.




