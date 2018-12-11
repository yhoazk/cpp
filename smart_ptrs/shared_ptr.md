# std::shared_ptr

### Defined in header <memory>
```cpp
template<class T> class shared_ptr; (since c++11)
```

`std::shared_ptr` is a smart pointer that retains shared ownership of an object
through a pointer. Several `shared_ptr` objects may own the same object. The
object is destroyed and its memory deallocated when either of the following
happens:
* The last remainig `shared_ptr` owning the object is destroyed;
* The last remainig `shared_ptr` owning the object is assined another pointer
  via `operator=` or `reset()`.

The object is destroyed using `delete-expression` or a custom delete that is
supplied to `shared_ptr` during construction.
