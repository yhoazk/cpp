# Const correctness

A "const function", denoted with the keyword const after a function declaration,
makes it a compiler error for this class function to change a member variable of
the class. However, reading of a class variables is ok inside of the function,
but writing inside of this function will generate a compiler error.

Another way of thinking about such "const function" is by viewing an class
function as a normal function taking an implicit this pointer. So a method 
`int Foo::Bar(int random_arg)` (without the const at the end) results in a
function like int `Foo_Bar(Foo* this, int random_arg)`, and a call such as 
`Foo f; f.Bar(4)` will internally correspond to something like 
`Foo f; Foo_Bar(&f, 4)`. Now adding the const at the end 
`(int Foo::Bar(int random_arg) const)` can then be understood as a declaration
with a const this pointer: `int Foo_Bar(const Foo* this, int random_arg)`.
Since the type of this in such case is `const`, no modifications of member
variables are possible.

It is possible to loosen the "const function" restriction of not allowing the
function to write to any variable of a class. To allow some of the variables to
be writable even when the function is marked as a "const function", these class
variables are marked with the keyword mutable. Thus, if a class variable is
marked as `mutable`, and a "const function" writes to this variable then the
code will compile cleanly and the variable is possible to change. (C++11)

As usual when dealing with the `const` keyword, changing the location of the
`const` keyword in a C++ statement has entirely different meanings. The above
usage of const only apply when adding const to the end of the function
declaration after the parenthesis. `const` is a highly overused qualifier
in C++ and the syntax and ordering is often not straightforward
in combination with pointers. 
Some readings about const correctness and the const keyword:

[https://en.wikipedia.org/wiki/Const_(computer_programming)](https://en.wikipedia.org/wiki/Const_(computer_programming))
