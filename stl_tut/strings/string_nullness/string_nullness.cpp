#include <iostream>
#include <string>
// The problem heres is that the string is not decided at compile time
// a string is created and the a reference is passed to this fnc at run
// time, because of this is not possible to chech for nullness in this call
bool test_null( const std::string& cstr ) {
    std::cout << cstr << '\n';
    return cstr.empty();
}


int main() {
    test_null(nullptr);
    return 0;
}
