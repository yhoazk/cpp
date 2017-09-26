# Static classes


There are no static class in C++, the nearest concept would be a class with only
static methods. _static classes_ are hacks for java-like languages which are
unable to have non-member functions, so they have instead to move them inside
classes as static methods.

Other languages created that "impediment" so every function is tied to a namespace
and for this  C++ includes `namespace`s. An example of a namespace and a possible
mapping between static class and namespace is the `cout` in C++ `std::cout` is
called to print in java one must use the `System.out.println`.
