#include <iostream>
#include <memory>
#include <cassert>
/* Here we will have an error at compile time as the copy constructor was 
 * deleted from the base obj
 * */

struct pod {
    double kk;
    float m;
    int i;
    pod() {
        std::cout << "pod ctor" << std::endl;
    }

    ~pod() {
        std::cout << "pod dtor" << std::endl;
    }

    pod(pod&&) {
        std::cout << "move ctor" << std::endl;
    }
};


auto some_dtor = [](pod* p){
    std::cout << "From custom dtor" << std::endl;
    delete p;
};

void func_dtor(pod* p) {
    std::cout << "From custom dtor function" << std::endl;
    delete p;
}

int main(){
    std::unique_ptr<pod> a;
    std::unique_ptr<pod, decltype(some_dtor)> b(new pod, some_dtor);
    // std::unique_ptr<pod, decltype(func_dtor)> c(new pod, &func_dtor);
    // smart pointers are initialized with nullptr as pointer, no ctor from pod is called at this point
    a.reset(new pod);
    pod* pod_ptr;
    std::cout << "unique_ptr size: " <<  sizeof(a) << std::endl;
    std::cout << "raw ptr size: " <<  sizeof(pod_ptr) << std::endl;
    std::cout << "unique_ptr size lambda deleter: " <<  sizeof(b) << std::endl;
    // if this is called, the desctructors for the smart pointers are not called
    //{std::abort();}
    return 0;
}
