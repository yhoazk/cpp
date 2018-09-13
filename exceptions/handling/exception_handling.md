# Exception handling


### Standard exceptions

Some functions in the standard C++ library send exceptions which are derived
from the `std::exception`. This class is defined in the `<exception>` and
serves as a pattern for the standard hierarchy of exceptions

```
exception
    bad_alloc     (Thrown by new)
    bad_cast      (Thrown by dynamic_cast)
    bad_exception (Thrown when an exception does not match a catch)
    bad_typeid    (Thrown by typeid)
    logic_error
        domain_error
        invalid_argument
        length_error
        out_of_range
    runtime_error
        overflow_error
        range_error
        underflow_error
    ios_base::failure  
```

## Rules for exceptions and error handling

#### Do not abruptly terminate the program

Do not call the next functions:

* `std::abort()`
* `std::quick_exit()`
* `std::_Exit()`

These functions terminate the program immediately, without calling the exit
handlers registered with `std::atexit()` and without executing the destructors
for objects with [automatic](), [thread](), [static]() storage duration. 

Plus open streams with unwritten buffered data may or may not be flushed, open
streams may or may not be closed and temporary files may or may not be removed.

#### Handle all exceptions

When an exception is thrown, control is transferred to the nearest handler with
matching type. If no matching handler is found directly, a dynamic search for
handlers in the sorrounding `try` blocks of the same thread is used.

If no matching handler is found, the function `std::terminate()` is called;
whether or not the stack is unwound before this call to `std::terminate()` is
implementation-defined. Because of this implementation defined stack unwind,
the destructors probably are not called before the end of the process, this 
abnormal termination is the typical vector for DoS attacks.

All exceptions thrown by an application must be caught by a matching handler.
Even if the exception cannot be handled, having a matching handler ensures that
the stack will be properly unwound and the destructors called.

One possible solution is to catch all exceptions in the `main()` funciton, while
this does not generally allow the application to recover from the exception, it
does allow the application to terminate in a controlled fashion.

#### Do not use `setjmp()` or `longjmp()`

The functions `setjmp()` and `longjmp()` which are part of the std C library
can be used to simulate and catching exceptions, but they bypass automatic
resource management and can result in undefined behaviour including resource
leaks and DoS.

#### Do not reference base classes or class data members in a constructor

When an exception is caught by a [function-try-block handler]() in a constructor
any fully constructed base classes and class members of the object are destroyed
prior to entering the handler. Similarly, when an exception is caught by a
function-try-block handler in a destructor, all base classes and nonvariant
class members of the objects are destroyed prior to enter the handler.

#### Catch handlers should order their parameter types from most derived to least derived

The handlers for a try-block are tried in order of appearance. That makes it
possible to write handlers that can never be executed, for example by placing
a handler for a derived class after a handler for a corresponding class.

If two handlers catch exceptions that are derived from the same base class, the
most derived exception must come first.

 Example of non the error:
```cpp

class B{};
class D: B public {};

void f() {
    try{
        // ..
    } catch(B& b){
        // ...
    } catch(D& d){
        // ... This should be called first
    }
}
```

#### Honor exception specifications
#### Guarantee exception safety
#### Do not leak resources when handling exceptions
#### Handle all exceptions thrown before `main()` begins
#### Do not throw an exception across execution boundaries
#### Exception objects must be nothrown copy constructible
#### Catch exceptions by `lvalue` reference
#### Detect errors when converting a string to number.

## Capture exceptions by reference or value




