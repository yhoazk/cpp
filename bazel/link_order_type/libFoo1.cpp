#include "foo.hpp"
#include <iostream>

template<>
bool first::Result<int>::get() {
    std::cout << "Foo1 GET" << std::endl;
    return true;
}

template<>
void first::Result<int>::clear() {
    value = 10000;
}

template<>
int first::Result<int>::get_val() {
    return value;
}
/*
template<>
first::Result<int>::~Result() {
        std::cout << "Desrozs" << std::endl;
}
*/
