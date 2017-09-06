# Smart pointers

[src](http://www.informit.com/articles/article.aspx?p=25264)


Smart pointers are C++ objects that simulate built-in pointers by implementing
the `operator->` and the unary `operator*`. In addition to supporting syntax and
semantics, smart pointers often perform other tasks as memory management or
locking  tasks in the background, this way freeing the application from
carefully managing the lifetime of pointed-to objects.


### The problem with built-in pointers
With pointers that hold values allocated with `new`, Once you have written.

```cpp
Widget* p = new Widget;
```
The variable `p` not only points to. but also owns, the memory allocated
for the widget object. This is because later you must issue `delete p` to
ensure that the `Widget` object is destroyed and its memory is released.
If in the line after you write:
```cpp
p = 0; // assign snomething else to p
```
you loose ownership of the object prevously pointed by `p`, and you have
no chance at all to get a grip on it again. You have a resource leak.

Furthemore, when you copy `p` into another variable, the compiler does not
automatically manage the ownership of the memory to which the pointer
points. All you get is two raw pointers pointing  to the same object, and
you have to track them even more carefully becaise double deletions are
even more catastrophic than no deletion. Consequently, pointers to
allocated objects do *not* have value semantics -you cannot copy and assign
to them at will-.


The `operator->`. When you apply `operator->` to a type that's not a
built-in pointer, the compiler does an interesitng thing. After looking
up and applying the user-defined `operator->` to that type, it applies
`operator->` again to the result- The compiler keeps doing this recursively
until it reaches a pointer to a built-in type, and only then proceeds with
member access. It follows that a smart pointer's `operator->` does not
have to return a pointer. It can return and object that in turn implements
`operator->` without changinig the syntax.

This leads to a very interesitng idiom: pre- and postfunction calls. If
you return an object of type `PointerType` by value from `operator->`,
the sequence of execution is as follows:
1. Constructor of `PointerType`
2. `PointerType::operator->` called, likely returns a pointer to an
object of type `PointeeType`
3. Member access for `PointeeType` - likely a function called.
4. Destructor of `PointerType`



To generalize the type universe of smart pointers, we distinguish three
potentially distinct types in a smart pointer.
* **The storage type**: This is the type of `pointee_`. By default is a raw pointer
* **The pointer type**: This is the type returned by `operator->`. It can be different from the storage type if you want to return a proxy object instead of just a pointer.
* **The reference type**: This is the type returned by the `operator*`.
