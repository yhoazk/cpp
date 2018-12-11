# Network Configurator

## Build

```bzl
bazel build //src:netcfg
```

Get information about the `g++` compiler in case is being used:
```
gcc -E -xc++ -v
```

## Reqs

- Gets the configuration for the network adapters from a JSON file.
- The structure of the json file is not kown, and can change.
- The progress, errors etc shall be reported to a logger `DLT` or `syslog`.
- Shall report errors of failure via a configurable mechanism.
- Shall handle errors in input
- Shall check for errors in the systemcalls that it may need.
- Shall handle errors in the actions it perfomrs.
- The application has to be able to change the interface from static to automatic
configuration based on the status of a bit flag. This can be implemented as a 
generic interface to check the state.
- Use the rapid json library to parse the input.

## Tools

- Use compiler clang.
- Compile using [`Bazel`](https://docs.bazel.build/versions/master/tutorial/cpp.html)
- Run static checks with [clang tidy](http://clang.llvm.org/extra/clang-tidy/)
- Run unit tests with [`gtest`](https://github.com/google/googletest)
- Check for memory issues with [`valgrind`](https://web.stanford.edu/class/cs107/guide/valgrind.html)

## Notes

### Prepend a `for(;;);` or `while(1);` to a JSON

### Mixing `c` and `c++` [code](https://isocpp.org/wiki/faq/mixing-c-and-cpp)

Here are some points to take into account when using mixed `C`/`C++`

* The `C++` compiler shall be used to compile the `main()`.


### Usign `clang` and `bazel`

Bazel requires a simplified model of the compiler, and some parts of that model
are hard-coded into Bazel. Most importantly bazel expects the compiler 
toolchain to be based on (or at least be very similar to) GCC and have most of
the associated tools, like ld, ar and objcopy.

To use a differen compiler the external information about the compiler is 
encoded into ASCII protobuf, which is read by Bazel whenever a build operation
is requested. The file must be named `CROSSTOOL` and must be present in the
top-level toolchain directory. (the value given to `--crosstool-top`).
At present. if the file is not available, Bazel falls back to its previous
hard-coded implementation.

Example of [`crosstool_config.proto`](https://github.com/bazelbuild/bazel/blob/3f611ab4ee905c09aff05f8fd8f19517be54efa6/src/main/protobuf/crosstool_config.proto)


### Relevant man pages

```
man 7 proc
man 7 capabilites
man 7 ip
man 7 rtnetlink
man 7 netdevice
```

### AF_UNIX vs AF_INET




