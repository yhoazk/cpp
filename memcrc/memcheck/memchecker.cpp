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
    size_t read_size{std::min(mr.len, mem::buff_size)};
    size_t len{mr.len};
    size_t total{0};
    int count;

    lseek64(_mtdfd, mr.start, SEEK_SET); 
    std::cerr << "Len: " << len << " read_size: " << read_size <<'\n';

    while ( (read_size <= len) and (count = read(_mtdfd, mem_buff.data(), read_size))){
        if(count > 0) {
            std::cout << "Read bytes: " << std::to_string(count) << " Planned: " << read_size << '\n';
            total += count;
        } else {
            if(count == 0) {
                std::cerr << "DONE\n";
                break;
            }
            std::cerr << "Error reading\n";
            break;
        }
        std::cerr << "LEN: " << std::to_string(len) << "  count: " << count << '\n';
        len -= count;
        std::cerr << "REM LEN: " << std::to_string(len) << "  count: " << count << '\n';
    }

    count = read(_mtdfd, mem_buff.data(), len);
    std::cerr << "LEN: " << std::to_string(len) << "  count: " << count << '\n';
    total +=count;

    std::cout << "Total bytes read: " << std::to_string(total) << '\n';
}


bool memchecker::query_calc_crc64(mem_reg& mr) {
    return true;
}

}