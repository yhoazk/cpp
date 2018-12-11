# Nonlinear programming using CppAD and Ipopt:

# Example and test

This example program demostrated how to use [ipopt solve](https://www.coin-or.org/CppAD/Doc/ipopt_solve.htm) to solve the next
example problem:
![](./sample_eq.png)
Syntax:
```cpp
#include <cppad/ipopt/solve>
ipopt::solve(options, xi, xl, xu, gl, gu, fg_eval, solution)

```



- - -
Obtain the core utils source code:
```
git clone --depth=1 git://git.sv.gnu.org/coreutils

```
