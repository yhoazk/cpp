# `unique_ptr`

From Scott's book Effective Modern C++

- `unique_ptr` should be used for exclusive ownereship resource management
- it covers the most common use cases for pointers and should be used whenever a raw pointer could be used
- `unique_ptr` embodies the exclusive ownership. This means that a `unique_ptr` *owns* what it points to. ALWAYS
- Moving a unique pointer transfers the ownership and sets the src pointer to `nullptr`
- Copying a `unique_ptr` is not allowed. Therefore a `unique_ptr` is a `move` onlt type
-
When a non-null unique+ptr is destroyed, it destroys its resource
- smart pointers accept *custom destroyers*, which could be used for logging
- normally samrt pointers are destroyed in case of program termination. There are exceptions in case that the proram terminates abnoramally:

    - An exceptin propagates oout of the primary function (sometimes that is main)
    - A `nonexcept` specification is violated
    - One of the following functions are invoked:
        - `std::abort`
        - `std::_Exit`
        - `std::exit`
        - `std::quick_exit`
- with smart pointers we dont need to care about how an object has to be destroyed or that the destruction happens only once
- Attempting to assign a raw pointer to a unique_ptr would constitute an implicit convversion from raw to smart pointer. This conversion can be problematic so it is prohibited. The member function `reset` shall be used instead
- Remember, base class destructor has to be `virtual` otherwise derived class destructors will not be called
- when a custom deleter is used, prefer lambdas and not function pointers. Function pointers increase the size of the pointer while lambdas do not
- Note that the last statement is valid only for stateless lambdas
- unique_ptr are popular mechanims for implementing the PIMPL idiom
- unique_ptr comes in two forms:
    - `unique_ptr<T>`:  For single objects
        - Does not implement the `operator[]`
    - `unique_ptr<T[]>`: For arrays
        - Does not implement the `operator*` nor the `operator->`
        - This API shall be used only when interacting with C code
- It is easy to convert from a `unique_ptr` for `shared_ptr`, then the `unique_ptr` is preferred
- `unique_ptr` is a small, fast, move-only smart pointer for managing resources with exclusive ownership semantics
- By default resource destruction takes place via delete, but custom deleters can be specified. Stateful deleters and function pointers as deleters increase the size of `unique_ptr` objects.