# Placement New

Placement new allows to construct an object on memory that's already allocated

```cpp
char* buf = new char[sizeof(string)]; // ple-allocated buffer
string* p = new(buf) string("sss");   // placement new
string* q = new string("sd");         // normal heap allocation
```

The objects created with placement new should not be `deleted`, instead the
buffere memory should be `deleted[]`


### Is there a "placement delete"

http://www.stroustrup.com/bs_faq2.html#placement-delete
