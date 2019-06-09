# Wrapping `C++` Member Function Calls

Proposal to wrapp calls to an object in pairs of prefix and suffix code.
This solution is non-intrusive, applies to existing code and allows the use of
seveal prefixx/suffix pairs.

There are two simple alternatives to solve this:

Explicitly call the functions:
```cpp
void fct(X* p){
    prefix();
    p->f();
    sufficx();
}
```
And add the prefix and suffix to the function definition
```cpp
class X{
    public:
    void f() { prefix(); /* f own stuff */ suffix();}
}
```

These solutions are error prone and tedious to use and implement and mantain.
Also this solutions have the advantage of allowing some, but not all functions
to be wrapped. The method presented here focuses on the case where every
operation on a class needs to be wrapped.

## Prefix

Overloading the `->` operator has long been a popular way to specifying a
prefix, e.g.:

```cpp
template<class T>
class Prefix{
    T* p;
public:
    Prefix(T* pp) : p(pp){}
    T* operator->(){ /* prefix code */ return p;}
};

X my_object;
Prefix<X> pref_obj(&my_object); // available for prefixed use

void fct(Prefix<X> p){
    p->f(); // prefix code 
}
```

Here the prefix is attached to the object and its functions non-intrusively.

## Suffix

One non-intrusive way of getting something done "later" is to create an object
with a class with a destructor that does something. The destructor will be
executed at the end of the objects lifetime.


```cpp
class Suffix{
public:
    ~Suffix(){ /* suffix code */}
};

void fct(«* p){
    Suffix suf;
    p->f();
    // the suffix code is implicitly executed here
}
```

The proble with this technique is that:
1. The user must explicitly declare an object
2. The user must name the `Suffix` object
3. The suffix isn't executed until the end of the block

## Prefix and suffix

The problems presented before can be solved by a combination of a destructor
to invoke the suffix with the use of an `operator->` to invoke a prefix. As
before `operator->` executes the prefix and returns something that identifies
the object for which the function is to be called.

```cpp
template<class T>
class Wrap{
    T* p;
public:
    Wrap(T* pp) : p(pp){}
    Call_proxy<T> operator->() { prefix(); return Call_proxy<T>(p); }
};
```

The difference with the last example is that the value returned by the
`operator->()` is an object holding the pointer to the object to be called
rather than the pointer itself. We use that object's destructor that calls
the suffix

```cpp
template<class T>
class Call_proxy{
    T* p;
    public:
    Call_proxy(T* pp): p(pp){}
    ~Call_proxy(){ suffix();}
    T* operator->() { return p; }
};
```

Now we can use them like:

```cpp
#include <iostream>

using namespace std;

void prefix(){ cout << "prefix"; }
void suffix(){ cout << "suffix\n"; }

template<class T> class Call_proxy{ /* ... */};
template<class T> class Wrap { /* ... */ };

class X {
public:
    X(){ cout << "make an X\n"; }
    int f() const { cout << "f()"; return 1; }
    void g() { cout << "g()"; }
};

class Y { // another user class
public:
    Y() { cout << "make a y\n";  }
    void h() const { cout << "h()"; }
};

int main(){
    Wrap<X> xx(new X);
    Wrap<Y> yy(new Y);

    if(xx->f()) cout << "done\”";
    xx->g();
    yy->h();
    return 0;
}
```

Each call of xx and yy is bracketed by a pair of prefix and suffix calls,
the expected ouput is:

```
make an X
make a Y
prefix f() suffix
done
prefix g() suffix
prefix h()
```


- - -
[Src](http://www.stroustrup.com/wrapper.pdf)