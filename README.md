# cpp
c++



### Difference for `++i` and `i++`

[http://www.embedded.com/design/programming-languages-and-tools/4410601/Pre-increment-or-post-increment-in-C-C-](http://www.embedded.com/design/programming-languages-and-tools/4410601/Pre-increment-or-post-increment-in-C-C-)

For the case when:
```
```


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
>0
>f
>t

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


## Eigen library:

https://eigen.tuxfamily.org/dox/group__TutorialMatrixClass.html



## Pointer to functions:

```C
typedef double_t (*pfnc)(int, int);
pfnc costFunctions[] = {
    lane_error,
    speed_error,
    collision_avoid
};
```
