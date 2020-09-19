# Rule of three

If a class needs any of the next user-defined {d-c}-tors, all of them need to
be defined

- destructor
- copy-constructor
- copy-assignment operator

This is necessary because the compiler will generate a default implementation
which is likely to do shallow copies resources without duplicating the
underlying resource. For example POSIX file descriptors.

# Rule of Five


Before C++11 and move semantics there were the rule of the Big three which
deals with copy a resource  manager. Copying a resource manager object is the
first issue.

The rule of five states that if you have to write one of the funcitons below
the you have to have a policy for _all_ of them.

Rule of 5 is essentially rule of three plus the two move operators:

- move constructor
- move assignment operator

unlike rule of three, failing to provide moving operator and move constructor
is usually not an error, but a missed optimization oportunity.

### The destructor

### The assignment operator

### The copy ctor

### The move ctor

### The move assignment operator



## Rule of zero




https://en.cppreference.com/w/cpp/language/rule_of_three