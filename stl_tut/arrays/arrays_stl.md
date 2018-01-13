#


[Data contiguity](https://stackoverflow.com/questions/9762662/is-the-data-in-nested-stdarrays-guaranteed-to-be-contiguous):


## Are array elements padding-free? (contiguous)

(**this for "regular" arrays in C99**)
All array (including multidimensional ones) are padding free, this can be inferred
from `sizeof` rules.

Array subscription ([] operator) is a special case of pointer arithmetics, and
c99 section 6.5.6 -8 states clearly that behaviour is only defined if the pointer
operand and the resulting pointer lie in the same array (or one element past).


Most compilers treat pointer expressions like:
```cpp
arr[0]+5
```
Identically to well defined conterparts:
```cpp
(int*)((char* )mtx + 5*sizeof(int))
```

The above is for C built-in arrays which differ from the STL objects.
Then for STL objects contiguity is NOT guaranteed.

`std:array` is guaranteed to be an aggregate, and is specified in such way that
the underlying array used for storage must be the first data member of the type.

But there is no requirement that guarantees that:

```cpp
sizeof(std::array<T,N> == sizeof(T) * N)
```

Nor is in the requirements that there are no unnamed padding bytes at the end of
the object `std::array`
