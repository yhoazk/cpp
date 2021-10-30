#include <iostream>
#include <vector>
#include <algorithm>

// https://man7.org/linux/man-pages/man3/mtrace.3.html

// #include <mtrace.h>
// Demostrates how iterators become invalid
// when the underlying container needs to reserve more memory
// then it has to copy from the initial memory to the newly
// allocated leaving the memory pointed in the interator in an
// invalid state
void iter_test() {
    std::vector<int> v{};
    std::cout << "&v: " << &v << std::endl;
    v.push_back(1);
    std::cout << "&v: " << &v << std::endl;
    v.push_back(2);
    std::cout << "&v: " << &v << std::endl;
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    std::cout << "&v: " << &v << std::endl;
    // Iterator points to the address where 3 was found
    const auto three{std::find(std::begin(v), std::end(v), 3)};
    std::cout << "Three: " << *three << std::endl;
    for(auto n=0; n < 10; ++n) {
        v.push_back(9);
    }
    // the iterator gets invalidated due to vector being moved
    // as it needs more storage
    std::cout << "Three: " << *three << std::endl;
}


int main() {
    // mtrace();
    iter_test();
    return 0;
}
