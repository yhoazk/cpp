# Linker symbol resolution

## compile the relocatable object

```
g++ -c -fPIC libFoo1.cpp
g++ -c -fPIC libFoo2.cpp
```
This generates `libFoo1.o` and `libFoo2.o`, now generate the `so`
libraries:

```
g++ -shared -o libFoo1.so libFoo1.o
g++ -shared -o libFoo2.so libFoo2.o
```

Then the current directory needs to be added in the linker search.
```
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD
```

Now generate the binary:

```
g++ link_order.cpp -o link_order_1_2.exe -lFoo1 -lFoo2 -L.
g++ link_order.cpp -o link_order_2_1.exe -lFoo2 -lFoo1 -L.
```

The point of this is to show how the result of the operation depends on the order in which the
type is find at link/load time and not of the content of the sources.
This comes from a bug found in test code from production.
The test code uses a type which implements similar functionality, but reduced to the production one.
The production code got leaked in the test, where apparenly the compiler uses a method from a
different type, but same namespace and typename. The solution would be to cleanly separate test and
production code, this is not always easy due to strage dependencies.
