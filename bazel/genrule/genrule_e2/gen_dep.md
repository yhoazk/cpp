## Generating a dependency

When a executable file created a dependency, something like the contents of a
header file or configuration files.

The genrule has to use the `$@`, if the file is not generated this way we get
an error:
```
genrule/genrule_e2/BUILD:3:1: declared output 'foo.h' was not created by genrule. This is probably because the genrule actually didn't create this output, or because the output was a directory and the genrule was run remotely (note that only the contents of declared file outputs are copied from genrules run remotely)
```

https://github.com/bazelbuild/bazel/issues/2532
