#include <iostream>
#include "wtf.h"

int main() {
    func::module mod;
    for(const auto _ : {0,0}) {
        if (mod.is_ok()) {
            std::cout << "Module is ok" << std::endl;
        } else {
            std::cout << "module is not ok" << std::endl;
            mod.apply_change(99);
        }
    }
    
    return 0;
}