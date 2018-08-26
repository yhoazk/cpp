# `py_test`

Sample to get a `py_test` and a binary dependency in it.

The sample runs and the test gets the logged output to verify the 
behaviour.


## Writing tests with `pytest`

### Skipping tests



### Marking a test as expected to fail

Use the pytest marker `xfail` to tell pytest to run a test that is expected to
fail. Use the next python decorator.

```py
@pytest.mark.xfail
@pytest.mark.xfail(<bool_exp>, reason=<str_for_reason>)
```

It's also possible to call the expected to fail in the test:

```py
def test_fnc():
    if not valid_cfg():
        pytest.xfail("No valid configuration")
```

To return the result of the test to bazel add the [next snippet](https://groups.google.com/forum/#!topic/bazel-discuss/d1RKUmyve_Q):

```py
if __name__ == "__main__":
    sys.exit(pytest.main([__file__]))
```


## Build

```sh
bazel build --strategy=CppCompile=standalone //...
```

## Test
https://docs.bazel.build/versions/master/command-line-reference.html#test

```sh
bazel test --nocache_test_results //...
```

The test logs are stored in `bazel-testlogs/test_logger`

## Run

```sh
bazel run //:logger_generator
```