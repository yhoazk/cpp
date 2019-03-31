# Maps

## `<map>`

Maps are ascociative containers, where each element has a key and mapped value.
No two mapped values can have the same key.

## `<unordered_map>`

Has the same properties as a std::map, an associative container with unique keys and mapped elements.
The unordered_map is implemented using a hash table, the provided key is mapped into indices of a table
because of this the operations `search`, `insert` and `delete` have a cost of `O(1)`.

## `<map>::multimap`

This type of map is similar to `std::map` with the additional propertie that multiple elements
can have the same key. The pair key::value must be unique.
