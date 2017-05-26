# challenge


[Src](https://software.intel.com/en-us/articles/how-to-use-loop-blocking-to-optimize-memory-use-on-32-bit-intel-architecture)<br>

Improve memory utilization by means if loop blocking:
The main purpose of loop blocking is to eliminate as many cache misses
as possible. Consider the following loop, as it exists before blocking:

```c
float A[MAX, MAX], B[MAX,MAX];

for (size_t i = 0; i < MAX; i++) {
  for (size_t j = 0; j < MAX; j++) {
    A[i][j] = A[i][j] + B[i][j];
  }
}

```


## Solution:

**Transform the memory domain of a given problem into smaller chunks, rather
than sequentially traversing through the entire memory domain.** Each chunk
should be small enough to fit  all the data for a given computation into the
cache, thereby maximizing data reuse. In fact one can treat loop blocking as
strip mining in two or mre dimensions.

The two-dimesional array **A** is referenced in the `j` (column)
