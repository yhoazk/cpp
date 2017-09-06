# operator overloading

Any of the next operators can be overloaded:
 - `+`
 - `-`
 - `*`
 - `/`
 - `%`
 - `ˆ`
 - `&`
 - `|`
 - `~`
 - `!`
 - `=`
 - `<`
 - `>`
 - `+=`
 - `-= `
 - `*=`
 - `/=`
 - `%=`
 - `ˆ=`
 - `&=`
 - `|=`
 - `<<`
 - `>>`
 - `>>=`
 - `<<=`
 - `==`
 - `!=`
 - `<=`
 - `>=`
 - `&&`
 - `||`
 - `++`
 - `--`
 - `,`
 - `->*`
 - `->`
 - `( )`
 - `[ ]`


* The operators `::`, `.`(member access), `.*`(member access through pointer to member), and `:?` (ternary conditional) cannot be overloaded.
* The operators `&&` and `||` loose short-circuit evaluation.
* The overload of `->` must either return a raw pointer or return an object
(by reference or by value), for which the operator `->` is in turn overloaded.


## Overloading the `->` operator:

If this operator overload is used, ts return type must be a pointer
or an object of a class to which you can apply `->`.

```cpp
class prt{
  X* operator->();
}
```
Objects of class `ptr` can be used to access members of class X in a
very similar manner to the way pointers are used.
```cpp
void f(ptr p) {
  p->m = 10; // expands to (p.operator->())->m = 10;
}
```

The statement `p->m` is interpreted as `(p.operator->()->m)`.

## Overloading the `*` (dereference) and not the `*` multiply operator.

The difference when overloading this two operators which appen to use
the same symbol(*) is the number of inArgs to the function.

For example:
```cpp
template<class T>
T operator*()
{
  return this->data;
}
```
If no parameters are given then the dereference operator is overloaded.

```cpp
template<class T>
T operator*(T& k)
{
  return this->data;
}
```

If an input argument is given, then the multiply operator is overloaded.

## Overloading `++` and `--`

This need to implement the postfix and prefix version.

##
