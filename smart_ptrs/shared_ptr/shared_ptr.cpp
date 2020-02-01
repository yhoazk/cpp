#include <memory> // shared_ptr
#include <iostream> //cout
#include <iomanip> // 
#include <array>
#include <cstddef>
#include <string>
#include <vector>

#include <linux/mmc/ioctl.h>
#include <sys/ioctl.h>
#include <linux/major.h>
#include <cstring>
#include <cerrno>
#include <cstdlib>
#include <fcntl.h>

const int mmc_rsp_present {1 << 0};
const int mmc_rsp_136     {1 << 1};
const int mmc_rsp_crc     {1 << 2};
const int mmc_rsp_busy    {1 << 3};
const int mmc_rsp_opcode  {1 << 4};

const int mmc_cmd_adtc    {1 << 5};
const int mmc_rsp_spi_s1  {1 << 7};
const int mmc_rsp_spi_r1  {1 << 7};
const int mmc_rsp_r1{(mmc_rsp_present | mmc_rsp_crc | mmc_rsp_opcode)};

const int mmc_send_ext_csd {(1 << 3)};

const size_t kBlockSize{3};

//alignas(8) std::array<std::uint64_t, kBlockSize> emmc_data;
std::array<std::uint8_t, kBlockSize> emmc_data;


bool emmc_health(std::vector<uint8_t>& health_data){
    struct mmc_ioc_cmd data;
    bool state{false};

    memset(&data, 0, sizeof(data));
    data.write_flag = 0;
    data.opcode = mmc_send_ext_csd;
    data.arg = 0;
    data.flags = mmc_rsp_spi_r1 | mmc_rsp_r1 | mmc_cmd_adtc;
    data.blksz = kBlockSize;
    data.blocks = 1;
    data.data_ptr = reinterpret_cast<uint64_t>(emmc_data.data());

    auto emmc_fd = open("/dev/mmcblk0", O_RDWR);

    if(emmc_fd != -1){
        if(ioctl(emmc_fd, MMC_IOC_CMD, &data) < 0){
            std::cerr << "ioctl failed";
        } else {
            for(auto& datum : emmc_data){
                std::cout << datum << '\n';
            }
            return state;
        }
    } else {
        std::cerr << "Unable to open emmc device: " <<  std::string(strerror(errno));
    }
    return state;
}


int main(int argc, char** argv){
    // std::cout << std::hex << &emmc_data[0] << '\n';
    auto addr =  emmc_data.data();
    std::cout << addr << '\n';
    std::cout << alignof(std::max_align_t) << '\n';
    std::cout << alignof(emmc_data.data()) << '\n';
    std::cout << sizeof(unsigned long) << '\n';
    return argc;
}