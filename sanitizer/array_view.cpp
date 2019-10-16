#include <iostream>

// constexpr constructor which fails to be a constexpr when 
// the sanitizers are used
struct array_view_s {
    explicit constexpr array_view_s(void* p, size_t n) : size((p == nullptr)? 0:n), data(p){}
    size_t size;
    void* data;
};

using array_view = struct array_view_s;

int main(){
    unsigned char chunk [45];
    array_view arv{&chunk, 99};
    std::cout << arv.size << std::endl;
    return 0;
}