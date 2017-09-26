# Static Methods:
[src](http://www.learncpp.com/cpp-tutorial/812-static-member-functions/)

Static methods are methods which do NOT need a class instance to be called.
This methods are not associanted wih an instance, so they cannot access any non-static fields in the class.
You would use a static methos if the method does not use any fields (or only static fields) of a class.

[When use static methods](https://stackoverflow.com/questions/2671496/java-when-to-use-static-methods)

One rule of thumb to know if a method should be static:
ask yourself, _does it make sense to call this method, even id no Object has
been constructed yet?_


Define static methods only in the following scenarios:

1. It belongs to a utility class, and they are not supposed to be changed.
2. The method is not usign any instance variable.
3. Any operation is not dependent on instance creation.
4. There's some code that can easily be shared by all the instance methods.
5. The definition of the method will never be changed or overriden, **Static methods cannot be overrriden.


#### Advantages of static methods
* Performance
  * There's no need to instantiate objects
* Practicality
  * Are easier to use `new Util().method(arg)` is no static, whereas `Util.method(arg)` is static.
* Adding methods
* Purity


**Static member functions have no `this` pointer**
