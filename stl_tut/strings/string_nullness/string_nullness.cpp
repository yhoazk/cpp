#include <iostream>
#include <string>
#include <type_traits>
// The problem heres is that the string is not decided at compile time
// a string is created and the a reference is passed to this fnc at run
// time, because of this is not possible to chech for nullness in this call
bool test_null( const std::string& cstr ) {
    static_assert(std::is_null_pointer<decltype(cstr)>::value == false);
    //if(cstr != nullptr) {
    if( not cstr.empty()) {
        std::cout << cstr << '\n';
        return cstr.empty();
    } else { return false;  }
}


int main(int c, char** cv) {
    char* var;
    std::cout << "c: " << std::to_string(c) << '\n';
    if(c > 1) {
        var = nullptr;
    } else {
     //   var = "Taco\n";
    }
    test_null("dsdasd");
    test_null(nullptr);
    return 0;
}
