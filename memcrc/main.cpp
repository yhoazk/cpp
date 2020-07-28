#include <iostream>
#include <memchecker.h>

std::array<mem::mem_reg, 3> regions{{
    {.name = "First", .start = 0x0,     .len = 0x400*5, .crc64=0},
    {.name = "Sec",   .start = 0x400*5, .len = 0x400*7, .crc64=0},
    {.name = "Thrd",  .start = 0x400*7, .len = 0x400*1, .crc64=0},
}};

int main(){
    for(const auto& reg : regions){
        std::cout << reg.name <<'\n';
    }
    return 0;
}