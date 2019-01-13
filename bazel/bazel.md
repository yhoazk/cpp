# [Bazel](https://docs.bazel.build/versions/master/tutorial/cpp.html)

Tutorial to start with bazel build system.

Bazel need a file `WORKSPACE` which has to be located at the root of the
project to make it a bazel project. Bazel also uses a file `BUILD` which
contains the information about how to build the binaries.

The commands to run the compilation are: `bazel build //<src-folder>:<bin_name>`

## WORKSPACE

The file `WORKSPACE` can be empty or contain references to external deps.

## BUILD

The file `BUILD` defines the primary unit of code called a _package_. By definition
is a collection of related files and a specification of its dependencies.
The package is a container of _targets_. Targets are mostly either a file or a rule
the other group is package.

Files can written code or generated also called derived files which normally are not
checked in but are the result of the build tool.

Packages can be groupes to limit its visibility by using the function 
`package_group` function the visibility is modified with the `visibility`
attribute.

### Rules

[src](https://docs.bazel.build/versions/master/skylark/rules.html#actions)

#### Macros and rules

Macros instantiate rules in the loading phase. Macros are useful to repetitive
tasks. Macros are less powerful than rules and should be used only for simple
logic.

Rules especify the relationship between a set of inputs and a set of outputs,
including the necessary steps to derive the outputs from the inputs. This inputs
include other rules as well. Rules can access bazel internals and have full 
control, also rules can pass information to other rules.

## Evaluation mode

Bazel builds consist of the next steps

### loading phase

- load and evaluate all extensions.
- Load all `BUILD` files needed
- instantiate the needed rules
- Evaluate the macros
- Genererate the dependency graph

### Analysis

- Execute the implementation of the rules
- Instantiate the rule action
  - can be one of `ctx.actions.{run, run_shell, write, expand_template}`
- The execution graph is created from the dependency graph

### Execution

- Actions, which describe the process to get every output from the specified input are executed
- If a file is missing the build fails
- Run the tests if any

#### Error: `ccache: error: Failed to create temporary file`

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

Use the option `--strategy=CppCompile=standalone` in the bazel build cmd call.
This error can be fixed by exporting the `CC` and `CXX` environment variables.

```bash
export CC="/usr/bin/gcc"
export CXX="/usr/bin/g++"
```

### Debugging

1. Generate executables with debug information

```sh
bazel build ... --compilation_mode=dbg -s
```

( the mode is `dbg` not `gdb`)
2. Run `gdbtui` calling the binary in `bazl-bin/bin/main`
