# Multiple inheritance

A feature of C++ where a class can inherit from more than one class.

The constructors of inherited classes are called in the same order in which
they are inherited.

## Diamond problem


The Diamond problem occurs when two superclasses of a class hace a common base
class. For example, in the diagram, the cross over class gets two copies of all
the attributes of Car class, which is ambiguous at best.

![](./dimond.png)



[Src](http://www.geeksforgeeks.org/multiple-inheritance-in-c/)
