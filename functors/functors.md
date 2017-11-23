# Functors (a.k.a. Function objects)
[](http://www.geeksforgeeks.org/functors-in-cpp/)
Functors are objects that can be treated as though they are
a function or a function pointer. F

In C++ is an object which implements the operatior `operator()`


An example of a functor:
```cpp
#include <bits/stdc++.h>

usign namespace std;

class increment
{
    private:
        int num;
    public:
        increment(int n): num(n){}

        // This implements the () operator
        int operator()(int arr_num) const 
        {
            return num + arr_num;
        }
};

int main()
{
    int arr[] = {1,2,3,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int to_add = 2;

    // using tthe stl function `transform`
    transform( arr, arr+n, arr, increment(to_add));
    // print the elements

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
} 
```
