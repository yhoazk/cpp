# `rvalues` `lvalues` `xvalues` `glvalues` `prvalues`

In c++03 the expressions are either an `rvalue` or an `lvalue`, but C++
introduced more types. All this began with the move semantics. Once we have
expressions that can be moved and not copied, it is necessary to distinguish 
between expressions that can be moved and in which direction.

### `lvalue`

Historically `lvalues` could appear in the left-hand side of an assignment.
They designate a function or an object.
### `xvalue`

An `xvalue` (an eXpiring value) also refers to an object, usually near the 
end of its lifetime (So that its resources may be moved).
An xvalue is the result of certain kinds of expressions involving rvalue 
referenes. For example the result of calling a function whose return type
is an rvalue reference is an xvalue.

### `glvalue`
A Generalized lvalue is a lvale or an xvalue.

### `rvalue`
Also called Rvalue because could appear on the right-hand side of an assignment
expression. The rvalue is a xvalue, a temporary object or subobject or a value
not associated to an object.

### `prvalue`

Pure rvalue is an rvalue that is not an xvalue.
for example the result of calling a function whise return type is not a reference
  is a prvalue.

![](./values.png)

### Macros to test values

```
#define IS_LVALUE(...) std::is_lvalue_reference<decltype((__VA_ARGS__))>::value
#define IS_XVALUE(...) std::is_rvalue_reference<decltype((__VA_ARGS__))>::value
#define IS_PRVALUE(...) !std::is_reference<decltype((__VA_ARGS__))>::value
```


- - -

This classification exists to be able to talk about values where it's 
safe to move from them, and to talk about values where is not.

In the earliest bersion of r-value references, movement happended easily.
Easily enough that was a lot of potential for implicitly moving things that
the use really didnt meant to..

It is only safe to move something when:

1. It's a temporary or subobject thereof.
2. When the user has explicitly said to move.


