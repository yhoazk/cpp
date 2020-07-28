
#ifndef _MEMCHECKER_H_
#define _MEMCHECKER_H_

#include <mutex>
#include <array>
#include <string>


namespace mem {

struct mem_reg {
    const std::string name;
    const size_t start;
    const size_t len;
    uint64_t crc64;
};


class memchecker {
public:


private:
    static memchecker* pinst;
    static std::mutex mtx;
};
} // mem
#endif  // _MEMCHECKER_H_