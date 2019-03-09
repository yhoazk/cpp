# Choosing Random Elements


Choosing random elements is trivial when the elements are already present as an
a set or array by getting a random number and then using this number as index.

In the Perl Cookbook an optimization is presented:
```perl
srand;
rand($.) < 1 && ($line = $_) while <>;
```

Translated to python:

```python
import random
def random_element_iter(iterator):
    N = 0
    for item in iterator:
        N += 1
        # 1/N chance
        if random.random() * N < 1:
            element = item
    return element
```

For the `n`-th element of the iterator there is a `1/N` chance of being keept.
The base case `N=1` the element has a 100 chance of being picked. When `N=2`
every element has a chance of 50% of being picked. 

Suppose for the first `N` items, the probability of choosing any of the `N`
elements is equal to `1/N`. When the item `N+1` is processed the probability
of being choose is `1/(N+1)` for the element `N/(N+1)` the probability to stay
is `(1/N) * (N / (N+1)) = 1/(N+1)`. Each of the elements has a probability of
`1/(N+1)` of being choose.

This is useful when we need to pick elements of a stream, where the cardinality
is not known.


[src](http://web.archive.org/web/20141026071430/http://propersubset.com:80/2010/04/choosing-random-elements.html)

## Fisher Yates Algorithm

This is the cannonical way to create an unbiased shuffled array where every
permutation is equally likely. One every iteration an item is extracted from
the remainig elements.

```python
import random

def suffle(a, N):
    for i in range(N-1, 0, -1):
        j = int(random.random() * i)
        a[i], a[j] = a[j], a[i]
    return a
```


- - -

The general problem here is picking `K` **distinct** elements randomly from a
set of `N` items. If the items could be repeated, then we just need to run the
algorithm several times with replacement. We want an algorithm for picking `K`
elements from the set `N` without replacement.

The simple solution is to keep track of the elements already picked.


## Sattolo's Algorithm


## Reservoir Sampling