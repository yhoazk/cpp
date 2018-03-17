# Deque - STL

Double ended queue or deque(part of the C++ stl) are sequece containers with
dynamic sizes that can be expanded or contracted on both ends ( either its 
front or its back). The member functions of deque that are mainly used are:

* Deque Template:
```cpp
std::deque<Value_type>
```
* Declaration:
```cpp
deque<int> my_deque;
```
* Size:
```cpp
int length = my_deque.size();
```
*  Push
```cpp
my_deque.push_back(1); // push element at the end
my_deque.push_front(1); // push element at the beginning
```
* pop:
```cpp
my_deque.pop_back(); // pop element from the end
my_deque.pop_front(); // pop element fron the beginning
```
* Empty:
```cpp
my_deque.empty() == true
```

## Task

Given a set of arrays of size `n` and an integer `k`, find the maximum
integer for each and every contiguos subaray of size `k` for each of the 
given arrays.

### input format

First line of input will contain the number of test cases T. For each 
test case, you will be given the size of the array `n` and the size of
the subarray to be used `k`. This will be followed of the elements of 
the array.

### Output format

For each of the contiguous subarrays of size `k` of each array, print the 
maximum integer in one line.
