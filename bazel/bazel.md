#[Bazel](https://docs.bazel.build/versions/master/tutorial/cpp.html)

Tutorial to start with bazel build system.


Bazel need a file `WORKSPACE` which has to be located at the root of the
project to make it a bazel project. Bazel also uses a file `BUILD` which 
contains the information about how to build the binaries.

The commands to run the compilation are: `bazel build //<src-folder>:<bin_name>`

For example for example_1: `bazel build //src:hello`.

Bazel has the "feature" that **everyting** must be specified, then for a simple
example like this example_1 the compilation as it is it will fail with the next
message:

```log
Extracting Bazel installation...
.............
INFO: Found 1 target...
ERROR: cpp/bazel/example_1/src/BUILD:1:1: C++ compilation of rule '//src:hello' failed (Exit 1).
ccache: error: Failed to create temporary file for /tmp/tmp.cpp_stderr: Read-only file system
Target //src:hello failed to build
Use --verbose_failures to see the command lines of failed build steps.
INFO: Elapsed time: 2.376s, Critical Path: 0.06s
```

#### Error: `ccache: error: Failed to create temporary file`

Use the option `--strategy=CppCompile=standalone` in the bazel build cmd call.

### Debugging

1. Generate executables with debug information
```
bazel build ... --compilation_mode=dbg -s
```
( the mode is `dbg` not `gdb`)
2. Run `gdbtui` calling the binary in `bazl-bin/bin/main`
