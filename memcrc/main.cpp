#include <iostream>
#include <memchecker.h>
#include <cstdio>
#include <chrono>

std::array<mem::mem_reg, 3> regions{{
    {.name = "First", .start = 0x0,        .len = 343000, .crc64=0},
    // {.name = "Sec",   .start = 0x400*1500, .len = 0x400*1700, .crc64=0},
    // {.name = "Thrd",  .start = 0x400*1700, .len = 0x400*1900, .crc64=0},
}};


int main(){
    using namespace std;
    using namespace chrono_literals;
    auto memcheck = mem::memchecker::getInsance("/tmp/test_block");
    auto prom = memcheck->async_crc64(regions);
    auto prom1 = memcheck->async_crc64(regions);
    auto prom2 = memcheck->async_crc64(regions);
    auto prom3 = memcheck->async_crc64(regions);
    auto prom4 = memcheck->async_crc64(regions);
    auto prom5 = memcheck->async_crc64(regions);

    // memcheck->start_calc_crc64(regions[1]);

    while('X' != std::getchar()) {
        if(prom.wait_for(0ms) == std::future_status::ready){
            std::cout << "REadyyy\n";
        } else {
            std::cout << "Busy\n";
        }
    }
    return 0;
}