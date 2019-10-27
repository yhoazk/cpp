# Pragma pack

By default, the natural alignments of datatypes in structs are used.
ie. if the size of the datatype is a multiple of memory address. This can cause
gaps in the struct in memory, making it larger than expected.

From the example, w/o any pragma directive the results are:
```
./pragma_demo.exe
size of struct = 40
a =0x7ffff219fae0
aa=0x7ffff219fae0   offset = 0
bb=0x7ffff219fae4   offset = 4
cc=0x7ffff219fae8   offset = 8
dd=0x7ffff219faf0   offset = 16
ee=0x7ffff219faf8   offset = 24
pt=0x7ffff219fadc
```

Adding the pragma `#pragma pack(1)`

```
./pragma_demo.exe
size of struct = 31
a =0x7ffd7bf28c40
aa=0x7ffd7bf28c40   offset = 0
bb=0x7ffd7bf28c41   offset = 1
cc=0x7ffd7bf28c45   offset = 5
dd=0x7ffd7bf28c47   offset = 7
ee=0x7ffd7bf28c4f   offset = 15
pt=0x7ffd7bf28c3c
```

The pragma option allows to change the aligment of datatypes within the struct
to align to boundaries smaller than it's size. It does not foce aligment of
_ALL_ variables, it only changes the aligment of variables larger than the pack
setting. For example, ifwe set the pragma pack to 8, the 16-byte datatype
aligns on the 8-byte boundary, but the other datatypes still use their natural
aligment.

```
./pragma_demo.exe
size of struct = 40
a =0x7ffd6de75590
aa=0x7ffd6de75590   offset = 0
bb=0x7ffd6de75594   offset = 4
cc=0x7ffd6de75598   offset = 8
dd=0x7ffd6de755a0   offset = 16
ee=0x7ffd6de755a8   offset = 24
pt=0x7ffd6de7558c
```