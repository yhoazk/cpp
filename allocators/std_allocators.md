# Allocators

Allocators are objects that encapsulate memory management. `std::allocator` is
used when the allocation and the construction are done in two separate steps.

All the STL containers have a parameter `Allocator` that is by default
`std::allocator`, this allocator simply uses the `new` and `delete` operators.

The default allocator is stateless, this means that all the instances are
interchangeable, compare equal and can de allocate memory allocated by any
other instance of the same allocator type.

### Member functions of `std::allocator()`

* `address`: (removed in C++20) Used to obtain the address of the object
* `construct`: (removed in C++20) Constructs the object
* `destroy`: (removed in C++20) Destructs the obj.
* `max_size`: (removed in C++20) Returns the largest supported allocation
* `allocate`: Allocates the memory
* `deallocate`: Deallocates the memory

### Why use an allocator?

Allocators are used to separate the memory (de)allocation from the
initialization/construction of the contents of that memory. Then memory is
reserved, but without calling the constructors

The reason, or one of the reasons to implement an allocator is that `new T[n]`
doesn't allow to control what constructors are called. It forces to construct
all the objects at the same time, this is specially important for containers
like `std::vector` where the elements could be created occasionally.

With a raw memory allocator, a certain amount of memory can be allocated, which
will determine the capacity. Then, as items are added to the container (usign
the constructor of their choice), objects can be constructed in this memory.

Then when the memory is full, a new allocation is done, typically twice as much
for `std::vector`. The new objects have to be reallocated if the container 
requires so, for example `std::vector` has to be copied to the new memory as
its elements must be continuous.

**Example**:
```cpp
std::vector<T> v;
v.reserve(5);     // Allocate memory for 5 objects, w/o construct them
v.push_back(T{}); // Construct object and place them in reserved memory
v.push_back(T{}); // A new object, no new allocations are made
v.clear()         // Destroy objects, but do NOT deallocate the memory
//...
// The memory is deallocated in the destructor of v
```

## polymorphic allocator

A polymorphic allocator supports run-time polymorphism based on the 
`std::memory_resource` it is constructed with. 

```
g++ -std=c++11 -O1 -pedantic -Wall -Wconversion -Wsign-conversion -Wsign-promo -pthread
```

#### Full example:
```
g++ -std=c++11 -O1 -pedantic -Wall -Wconversion -Wsign-conversion -Wsign-promo -O1 -pthread full_example.cpp && ./a.out
```