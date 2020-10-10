# C++ mock using google mock

#### Features

- xunit testing framework
- test discovery
- includes test runner
- rich set if assertions
    - custom
    - Matchers
- Parametrized tests
- Report generation

## Real world unit testing problems
- slow test
- Inconsistent result
- Test break due to external factors

### Google mock
- c++ library

_benefits_:
- Remove dependencies
- Test isolation
- reduce run time
- test hard-to-set scenarios
- Test failures
- Test system under development

Steps:
Inclide: 

```cpp
#include <gtest/gtest.h>
#include <gmock/gmock.h>
```

## Unit testing with google test

Testing framework structure
- Arrange, act, assert
- Test setup and teardown
- Use of assertions
    - Assert vs expect
    - Assert finishes the test, fatal failure
    - Expect prints error, but test continues. Only reports failure when the test has finished

### Test names
- Must be valid function names
- must be descriptive
- in gtest use `DISABLED_` prefix to ignore

### Command line options

*Test selection:*
- `--gtest_list_test`
- `--gtest_filter:wildcard` (adding `-` excludes a test)
- `--gtest_also_run_disabled_test`

*Test execution:*
- `--gtest_repeat=count`
- `--gtest_shuffle`

*test output:*
- `--gtest_color`
- `--gtest_print_time`
- `--gtest_output=xml`

*Assert behaviour:*

- `--gtest_break_on_failure`
- `--gtest_throw_on_failure`
- `--gtest_catch_exceptions`


## 3 parts of unit test:

1. Arrange
    - Set up preconditions and outputs
2. Act
    - Invoke the method under test
3. Assert
    - Verify test result
    - Ideally one assert per test

## Basic assertions

- Expected value is the first value by convention
- These different macros change the error message
- Use the correct assert to:
    - reduce debug time
    - show the purpose of the test
    - Understand why the test failed

`ASSERT_`:
* boolean values
    - `TRUE` : The passed bool is true-ty
    - `FALSE`: The passed bool is falsy

* Comparison
    - `EQ`: The result of calling the `==` is `true`
    - `NE`: The result of calling the? `!=` is `true`
    - `LT`: The result of calling the `<` is `true`
    - `GT`: The result of calling the `>` is `true`
    - `GE`: The result of calling the `>=` is `true`

### String assertions for (`c` string)

- `STREQ`
- `STRNE`
- `STRCASEEQ`
- `STRCASENE`

### Exception assertions

- `THROW(statement, exception_type)`
- `ANY_THROW(statement)`
- `NO_THROW(statement)`

### Predicate assertions
Evaluates the predicate with the given params

- `PRED1(IsEven, num)`
- `PRED2(sum, a, b)`
- `PRED3(sum, a, b, c)`


### Move assertions
- floating point
- type
- death test

### Custom failure message

`ASSERT_EQ(x,y) << "x not equal to y`

