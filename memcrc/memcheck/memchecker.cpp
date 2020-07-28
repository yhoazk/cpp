#include "memchecker.h"

namespace mem {

memchecker* memchecker::pinst{nullptr};
std::mutex memchecker::mtx;
std::map<reg_pair, uint64_t> memchecker::crc_reg{};
int memchecker::_mtdfd{0};

memchecker* memchecker::getInsance(const std::string& dev_path){
    if(pinst == nullptr) {
        std::lock_guard<std::mutex> lock(mtx);
        if(pinst == nullptr) {
            pinst = new memchecker(dev_path);
        }
    }
    return pinst;
}


void memchecker::start_calc_crc64(const mem_reg& mr) {
    std::array<uint8_t,mem::buff_size> mem_buff;
    
    auto count = read(_mtdfd, mem_buff.data(), mem_buff.size());
    if(-1 != count) {
        std::cout << "Read bytes: " << std::to_string(count) << '\n';
    } else {
        std::cerr << "Error reading\n";
    }
}


bool memchecker::query_calc_crc64(mem_reg& mr) {
    return true;
}

}