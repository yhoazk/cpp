#include <iostream>
#include "stack_allocator.h"

int main(int argc, char const *argv[])
{
    ::stack_string::allocator_type::store_type s;
    std::cout << stack_string("sdfasdf", s).c_str() << std::end;   
    return 0;
}
