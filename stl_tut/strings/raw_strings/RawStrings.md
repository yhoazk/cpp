# Raw strings


In C++11 and newer a new notation was introduced to get the raw strings which
where already available in python and ruby.

The syntax for raw string is the following:

```cpp
char* raw = R"(
dsdsds
sdf
sf
sdf
sfd   sdf
    )";

```

Also most of the complilers take adjacent string and concatenate them at 
compile time, this means that the next statement is valid.


```cpp
char* concatenated = "12345678"
  "pepepacaspicapapas conun pico pepe pecas"
  "pepe pecas pica papas con un pico en la penal";
```
