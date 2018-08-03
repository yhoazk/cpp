# Contracts

Contracts are a new kind of assertions for C++

When designing a library two factor are to be considered:
* Correctness: Degree to which a SW component matches its specification.
* Robustness: Ability of a software component to react appropriately to 
abnormal conditions.

Today many libraries use a single feature for managing both properties:
**exception handling**.

When a failure happens, we use exceptions as an error reporting mechanism.
- Notify about the error
- Decouple error identification from error handling
- eg: `bad_alloc`

When library detects an _assumption was not met_, it needs a mechanism to 
react. At the presetn when an assumption is not met (contract violation)
we document, ignore it or throw exceptions.

A contract violation happens because a caller does not fulfill the expectations
before calling a function or does not fulfill what should be ensured after its
execution.

The difference:
- A program failure is usually due to external conditions and cannto be avoided
- A contract violation should never happen in a correct program

## what is a contract

A contract is the set of preconditions, postconditions and assertions 
associated to a function.
- *Preconditions*: What are the expectations of the function?
- *postconditions*: What must the function ensure upon termination
- *assertions*: What predicates must be satisfied in specific locations of a
funciton body.

Formally: states rights and obligations of client and supplier.


## Precondition:
- A predicate that should hold upon entry into a function
- Expresses functions expectations on its inArgs
- expressed by attr: `expects`

```cpp
double sqrt(double x) [[expects: x >0]];
void queue::push(const T& x) [[expects: !full()]];
```
## postcondition

- A predicate that should hold upon exit from a funciton
- It expresses the conditions that a function should ensure for the return value
- postconditions are expressed by `ensures` attrubite

```cpp
double sqrt(double x)
[[expects: x>=0]]
[[ensures result: result >=0]];
```

Postconditions may introduce a name for the result of the funciton.

## Assertions
- A predicate that should hold at that point in a function
- Expresses the conditions that must be satisfied
- assertions are expressed by assert attributes



## Effects of contracts

Contracts do not have observable effect on a correct program (except for performance).
The only semantic effect happens if it's violated.
