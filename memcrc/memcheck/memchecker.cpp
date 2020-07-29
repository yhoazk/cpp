#include "memchecker.h"
#define CRCPP_INCLUDE_ESOTERIC_CRC_DEFINITIONS
#include "CRC.h"
namespace mem {

using namespace std;
using namespace chrono_literals;

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
    uint64_t crc{0};
    int count;
    // std::cerr << "Len: " << len << " read_size: " << read_size <<'\n';
    auto reg_id = std::make_pair(mr.start, mr.len);
    auto crc_it = crc_reg.find(reg_id);

    if(crc_it == std::cend(crc_reg)) {
        std::lock_guard<std::mutex> lock(mtx);
        lseek64(_mtdfd, mr.start, SEEK_SET); 
        while ( (read_size <= len) and (count = read(_mtdfd, mem_buff.data(), read_size))){
            std::this_thread::sleep_for(10ms);
            if(count > 0) {
                // std::cout << "Read bytes: " << std::to_string(count) << " Planned: " << read_size << '\n';
                crc = CRC::Calculate(mem_buff.data(), count, CRC::CRC_64(), crc);
                std::cout << "xx crc: " << crc << '\n';
                total += count;
            } else {
                if(count == 0) {
                    std::cerr << "DONE\n";
                    break;
                }
                std::cerr << "Error reading\n";
                break;
            }
            // std::cerr << "LEN: " << std::to_string(len) << "  count: " << count << '\n';
            // std::cout << ".\n";
            len -= count;
            // std::cerr << "REM LEN: " << std::to_string(len) << "  count: " << count << '\n';
        }

        count = read(_mtdfd, mem_buff.data(), len);
        //calc and update chesum
        crc_reg.emplace(std::make_pair(mr.start, mr.len), count);
    } else {
        // std::cerr << "CRC ALREADY CALC\n";
    }
    // std::cerr << "LEN: " << std::to_string(len) << "  count: " << count << '\n';
    total +=count;

    std::cout << "Total bytes read: " << std::to_string(total) << " CRC: " << crc  << '\n';
}


bool memchecker::query_calc_crc64(mem_reg& mr) {
    return true;
}

}