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
g++ link_order.cpp -o link_order_1_2 -lFoo1 -lFoo2 -L.
g++ link_order.cpp -o link_order_2_1 -lFoo1 -lFoo2 -L.
```