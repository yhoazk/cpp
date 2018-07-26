# Object Slicing

Object slicing happens when a derived class object is assiged to a base class
object, additional attributes created in the derived class are slicedd of the
from the base class object.


In `C++` a derived class object can be assigned to a base class obj. but the
other way around in not possible.

```cpp
class base{
  int x, y;
};

class derived : public base{
  int z,w;
}

int main(){
  derived d;
  base b = d; /* z and w are sliced off  */
}
```
