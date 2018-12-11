# Stack Unwinding

When an ecpetion is thrown and control passes from a try block to a handler,
the C++ run time calls destructors for all automatic objects constructed since
since the beginning of the try block. This process is calle stack unwinding.
The automatic objects are destroyed in reverse order of their construction. 

## Example:

From the example note:

```
bazel run unwind
INFO: Found 1 target...
Target //:unwind up-to-date:
  bazel-bin/unwind
INFO: Elapsed time: 0.185s, Critical Path: 0.00s

INFO: Running command line: bazel-bin/unwind
Entering Main
Created Dummy: M
Copy created dummy: M
Entering FncA
Copy created dummy:A
Entering FncB
Copy created dummy:B
entering fncC
Destroyed dummyC
Destroyed dummyB
Destroyed dummyA
Destroyed dummy M
Caught an exception of type: 11MyException
Exiting main

```

[src](https://docs.microsoft.com/en-us/cpp/cpp/exceptions-and-stack-unwinding-in-cpp#stack-unwinding-example)
