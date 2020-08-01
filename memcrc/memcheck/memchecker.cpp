#include "memchecker.h"
#define CRCPP_INCLUDE_ESOTERIC_CRC_DEFINITIONS
#define CRCPP_USE_CPP11
#include "CRC.h"
namespace mem {

using namespace std;
using namespace chrono_literals;

memchecker* memchecker::pinst{nullptr};
std::mutex memchecker::mtx;
std::map<reg_pair, uint64_t> memchecker::crc_reg{};
int memchecker::_mtdfd{0};

memchecker* memchecker::getInsance(const std::string& dev_path){

    uint64_t crc = CRC::Calculate("123456789", sizeof("123456789"), CRC::CRC_64());
    std::cout << "TEST: " << std::hex << crc << '\n';
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
    uint64_t crc{0}; // what is the probability of 0x00 if being the CRC?
    bool first{true};
    int count;
    // std::cerr << "Len: " << len << " read_size: " << read_size <<'\n';
    auto reg_id = std::make_pair(mr.start, mr.len);
    auto crc_it = crc_reg.find(reg_id);

    if(crc_it == std::cend(crc_reg)) {
        std::lock_guard<std::mutex> lock(mtx);
        crc_it = crc_reg.find(reg_id);
        if(crc_it == std::cend(crc_reg)) {
            lseek64(_mtdfd, mr.start, SEEK_SET); 
            while (count = read(_mtdfd, mem_buff.data(), read_size) ) {
                // std::this_thread::sleep_for(10ms);
                if(count > 0) {
                    std::cout << "Read bytes: " << std::to_string(count) << " Planned: " << std::to_string(read_size) << '\n';
                    if(first){
                        crc = CRC::Calculate(mem_buff.data(), count, CRC::CRC_64());
                        first = false;
                    } else {
                    crc = CRC::Calculate(mem_buff.data(), count, CRC::CRC_64(), crc);
                    }
                    // std::cout << "xx crc: " << std::hex << crc << '\n';
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
            crc = CRC::Calculate(mem_buff.data(), count, CRC::CRC_64(), crc);
            //calc and update chesum
            crc_reg.emplace(std::make_pair(mr.start, mr.len), count);
        } else {std::cout << "BLCOK\n";}
    } else {
        std::cerr << "CRC ALREADY CALC\n";
    }
    // std::cerr << "LEN: " << std::to_string(len) << "  count: " << count << '\n';
    std::cout << "Total bytes read: " << std::to_string(total) << " CRC: " << std::hex << crc  << '\n';
}


bool memchecker::query_calc_crc64(mem_reg& mr) {
    return true;
}

}