# Psudo code of utilities


## Length and index of the longest sequence of `x` element in the array:
This algorithm returns the index of the first element if the element is unique
in the array.
```js

// init
max_len = 0
last_eq =false
seq_start = 0
current_len = 0
iteration = 0
/* For each element in array */
foreach ( e in array) {
  current_len++
  if (max_len < current_len)
  {
    seq_start = iteration
    max_len = current_len
    if(last_eq)
    {
        seq_start = iteration - max_len + 1
    }
    last_eq = true
  }
  else {
    current_len = 0
    last_eq = false
  }

}
return seq_start, max_len
```

## Circular shift of an array
shift the array k places

| shift `k` | direction     |
| :------------- | :------------- |
| `<0`       | shift to the left       |
| `>0`       | shift to the right       |

```js

if(k == 0){return;}
/* Temporal space for shifted elements */
tmp = allocate(k * sizeof(element))

if (k > 0) {
  /*shift to the right*/
  memcpy(tmp, pArray+lenOfArray-shift, shift)
  memcpy(pArray+shift,pArray,lenOfArray-shift)
  memcpy(pArray, tmp,shift)
} else {
  /* shift to the left */
  memcpy(tmp, pArray, shift)
  memcpy(pArray,pArray+shift,lenOfArray-shift)
  memcpy(pArray+lenOfArray-shift, tmp,shift)
}
delete tmp
```
