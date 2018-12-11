# std::weak_ptr

### Defined in `<memory>`
```cpp
template<class T> class weak_ptr;
```

`std::weak_ptr` is a smart pointer that holds a non-owning ("weak") reference to
an object that is managed by `std::shared_ptr`. It mst be converted to
`std::shared_ptr` in order to access the referenced object.

`std::weak_ptr` models temporary ownership when an object needs to be accessed
only if it exists, and it may be deleted at any tyme by someone else,
`std::weak_ptr` is used to track the object, and it is converted to `shared_ptr`
to assume temprary ownership. If the original `shared_ptr` is destroyed at this
time, the object's lifetime is extended until the temporary `shared_ptr` is
destroyed as well.

In addition `std::weak_ptr` is used to break circular references of `shared_ptr`


## Methods

| modifiers |  |
| :------------- | :------------- |
| reset | releases the ownership of the managed object |
| swap  | swaps the managed objects |

| observers |  |
| :------------- | :------------- |
| use_count | returns the number of `shared_ptr` objects that manage the object |
| expired   | checks whether the reference object was already deleted |
| lock      | creates a `shared_ptr` that manages the referenced object |
| owner_before | provides owner-based ordering of weak pointers. |
