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
