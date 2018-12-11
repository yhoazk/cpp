# Non-copyable Objects

When a singleton is being used, the objet shall be unique.
Therefore the copy operation `=` has to be overloaded or
deleted to have only one element of that class.

The first method to make an object non-copyable is to have
its `operator=` as private in the class.

The second, was included in `C++11` with the `delete` 
operation.

- - -

The use case is a class implementing mutex or counters
which should not be duplicated 
