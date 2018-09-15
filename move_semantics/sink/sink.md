# Sink values


the example here is supposed to give a segmentation fault, and is what we
expect, the code attempts to dereference `p` after it was captured and moved
into the lambda.


One of the guidelines from modern C++ is to avoid using raw `new` and `delete`.
Instead you should use a smart pointer, a container or other RAII object.



## Sink Functions

In short sink functions take ownership of input parameters. This functions are
now responsible for the allocated memory/resource. 


 - - -

 RAII: Resource aquisition is initialization
