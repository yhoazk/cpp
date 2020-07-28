
#ifndef _MEMCHECKER_H_
#define _MEMCHECKER_H_

#include <mutex>
#include <array>
#include <string>
#include <map>
#include <iostream>

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

namespace mem {

using reg_pair = std::pair<size_t, size_t>;
const size_t buff_size{128*1024};

struct mem_reg {
    const std::string name;
    const size_t start;
    const size_t len;
    uint64_t crc64;
};

class memchecker {
public:

    memchecker(memchecker& other) = delete;
    void operator=(const memchecker& ) = delete;
    void start_calc_crc64(const mem_reg&);
    bool query_calc_crc64(mem_reg& );
    static memchecker* getInsance(const std::string& dev_path);

private:
    explicit memchecker(const std::string& path){
        _mtdfd = open(path.c_str(), O_RDONLY);
        if(!_mtdfd) {
            throw;
        }
    }
    ~memchecker(){}
    static memchecker* pinst;
    static std::mutex mtx;
    static int _mtdfd;
    static std::map<reg_pair, uint64_t> crc_reg;
};



} // mem
#endif  // _MEMCHECKER_H_