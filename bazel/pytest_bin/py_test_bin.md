# `py_test`

Sample to get a `py_test` and a binary dependency in it.

The sample runs and the test gets the logged output to verify the 
behaviour.


## Build

```
bazel build --strategy=CppCompile=standalone //...
```

## Test
https://docs.bazel.build/versions/master/command-line-reference.html#test
```
bazel test --nocache_test_results //...
```
The test logs are stored in `bazel-testlogs`

## Run

```
bazel run //:logger_generator
```