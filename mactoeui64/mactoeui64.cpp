#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

uint64_t stringtomac(std::string mac) {
    mac.erase(std::remove(mac.begin(), mac.end(), ':'), mac.end());
    return std::stoul(mac.c_str(), nullptr, 16);
}

uint64_t mactoeui64(uint64_t mac) {
    uint64_t upper{mac & 0xff'ff'ff'ff'ff'00'00'00};
    uint64_t lower{mac & ~0xff'ff'ff'ff'ff'00'00'00};
    uint64_t eui64{0x00'00'00'ff'fe'00'00'00};

    upper <<= 16;
    upper ^= 1UL << ((7*8)+1) ;
    eui64 |= upper | lower;
    return eui64;
}
/*
 * Algorithmo to convert MAC to EUI-64
 * 1. Split the mac in 2, 3 upper bytes and 3 lower bytes
 * 2. Insert 0xfffe in the middle
 * 3. flip the bit 7th bit of the MSB from upper ie | 0x020000
 * 4. Merge upper shifted << 16 and 0xfffe and lower part
 * eg:
 * 00:15:2B:E4:9B:60 -> 02:15:2B:FF:FE:E4:9B:60
 * 11:22:33:44:55:66 -> 13:22:33:ff:fe:44:55:66
 * 1f:22:33:44:55:66 -> 1d:22:33:ff:fe:44:55:66
 * */

int main(int argc, char** argv) {
    std::vector<std::string> args{argv, argv+argc};

    if (args.size() >= 2) {
        for (const auto& arg : args) {
            std::cout << "Arg:" << arg << '\n';
        }
        uint64_t nmac{stringtomac(args[1])};

        std::cout << std::to_string(nmac) << '\n';
        std::cout << std::hex << mactoeui64(nmac) << '\n';
    }
}
