#include <iostream>
#include <type_traits>

enum class selectors : size_t {
    foo=1, bar=1, baz
};

template<typename sel>
void test_selector(sel s);

template<>
void test_selector(selectors f){
    if(selectors::bar == f){
        std::cout << "Ima bar\n";
    }
}


int main(int argc, char const *argv[])
{
    test_selector(selectors::foo);
    std::cout << "is same " << std::is_same<selectors, size_t>::value << '\n';
    return 0;
}
