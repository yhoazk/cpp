# C++

## Iterators

For iterators prefer the member functions cbeing and cend instead of the
`std::begin`, `std:end` this way is clear that they are innmutable.



### Difference for `++i` and `i++`

[Src](http://www.embedded.com/design/programming-languages-and-tools/4410601/Pre-increment-or-post-increment-in-C-C-)

For the case in this simple application:
```cpp
#include <iostream>
int main(int argc, char const *argv[]) {
  for (size_t i = 0; i < count; i++) {
    std::cout << i << '\n';
  }
  return 0;
}

```
The Src article mentions that `++i` it's better than `i++` because `++i` does not
generates an intermediate storage variable, which is needed by `i++` to store the
current value while the operation is being executed.

Our test didn't find the mentioned behaviour, the test results are in [post_pre_inc](./post_pre_inc).
Which found that identiacal ASM code is being generated for gcc (GCC) 6.3.1 20161221 (Red Hat 6.3.1-1).




#### Creating scopes with brackets

Each bracket defines a new scope, thus if the variables defined inside the `{}` have precedence on the variables defined outside of the `{}`.
E.g.

```cpp
#include <iostream>
using namespace std;

int main(void)
{
    int t = 0;
    cout << t << endl;
    {
        char t = 'f';
        cout << t << endl;
        {
        char t = 't';
        cout << t << endl;
        }
    }
    return 0;
}
```

prints:
```
>0
>f
>t
```

## Show which directories gcc/g++ looks in for libraries:
[src]()
```
echo | gcc -Wp,-v -x c++ - -fsyntax-only
#or for
gcc -xc -E -v -
#or for c++
gcc -xc++ -E -v -
```

And if the route where the libraries are is not in that list, the switch
to add the path is `-Idir` or if the libraries are not system libraries use the switch `-idir`.

## About bits/stdc++.h

It is basically a header file that includes every standard library. In programming contests, using this file is a good idea, when you want to reduce the time wasted in doing chores; especially when your rank is time sensitive.
In programming contests, people do focus more on finding algorithm to solve a problem than on software engineering. From, software engineering perspective, it is a good idea to minimize the include. If you use it actually includes a lot of files, which your program may not need, thus increases both compile time and program size unnecessarily.

Disadvantages of bits/stdc++

bits/stdc++.h is not a standard header file of GNU C++ library. So, if you try to compile your code with some compiler other than GCC it might fail; e.g. MSVC do not have this header.
Using it would include a lot of unnecessary stuff and increases compilation time.
This header file is not part of the C++ standard, is therefore non-portable, and should be avoided.
Moreover, even if there were some catch-all header in the standard, you would want to avoid it in lieu of specific headers, since the compiler has to actually read in and parse every included header (including recursively included headers) every single time that translation unit is compiled.

Advantages of bits/stdc++

In contests, using this file is a good idea, when you want to reduce the time wasted in doing chores; especially when your rank is time sensitive.
This also reduces all the chores of writing all the necessary header files.
You don’t have to remember all the STL of GNU C++ for every function you use.


## Is malloc re-entrant?

[https://stackoverflow.com/questions/855763/is-malloc-thread-safe](https://stackoverflow.com/questions/855763/is-malloc-thread-safe)


## Re-entrant vs thread safe:

A function is thread-safe if:

>it only manipulates shared data structures in a manner that guarantees safe execution by multiple threads at the same time.

A function is reentrant if:

>it can be interrupted at any point during its execution and then safely called again ("re-entered") before its previous invocations complete execution.


## [Eigen library:](https://eigen.tuxfamily.org/dox/group__TutorialMatrixClass.html)

Look at [Eigen](./Eigen)

## Pointer to functions:

```C
typedef double_t (*pfnc)(int, int);
pfnc costFunctions[] = {
    lane_error,
    speed_error,
    collision_avoid
};
```


## Aliases

### `namespace`
- Namespace aliases allow the programmer to define an alternate name for a namespace.
- They are commonly used as a convenient shortcut for long or deeply-nested namespaces.

```cpp
#include <iostream>
namespace taco{
  namespace tortilla{
    namespace cosa {
      int value = 42;
    }
  }
}
namespace x = taco::tortilla::cosa;
int main()
{
 std::cout << x::value << std::endl;
 return 0;
}
```

### [`Types`](http://en.cppreference.com/w/cpp/language/type_alias)
Type alias is a name that refers to a previously defined type (similar to typedef)

```cpp
using Vec = vector<T, Alloc<T>>; // type-id is vector<T, Alloc<T>>
```

## `template<class T>` vs `template<typename T>`

For template declarations either `class` or `typename` can be used. Apparently
there is no difference between them.

* Some prefer to use `typename` as does not overloads the behaviour of the `class`
keyword.
* Others use `class` or `typename` as a hint for the user of the code. If `class`
 is used, then an `class` is expected.
* Some point that a `template template`  parameters there is difference, this
 difference will be fixed in C++17


## `mutable` vs `volatile`

The mutable and the volatile, both describe an object that can change out-of scope.
The `mutable` field can be changed even in an object accessed through a `const`
pointer or reference; or in a `const` object, so the compiler knows not to stash
it in registers or R/O memory. 

## `sizeof` vs `tuple_size`

```cpp
[cling]$ using a8l5 = array<unsigned char, 5>;
[cling]$ using a32l5 = array<int, 5>;
[cling]$ sizeof(a8l5);
[cling]$ sizeof(a8l5)
(unsigned long) 5
[cling]$ sizeof(a32l5)
(unsigned long) 20
[cling]$ tuple_size<a8l5>::value
(const unsigned long) 5
[cling]$ tuple_size<a32l5>::value
(const unsigned long) 5

```


### Sample memcheck with valgrind

```
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt 
         ./tested_binary arg1 arg2
```