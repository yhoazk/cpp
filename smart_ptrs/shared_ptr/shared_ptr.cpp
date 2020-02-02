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
#include <fcntl.h> // for open
#include <unistd.h> // for close :-/

#include "emmc_health.h"

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

const size_t kBlockSize{512};

//alignas(8) std::array<std::uint64_t, kBlockSize> emmc_data;
// share a pointer to this array or create a filter where the 
// passed array is filtered according to the given settings

using emmc_block_t = std::array<std::uint8_t, kBlockSize>;

std::shared_ptr<emmc_block_t>  emmc_block;
std::array<std::uint8_t, kBlockSize> emmc_data;

int mock_emmc_ioctl(int fd, int flags, struct mmc_ioc_cmd* mmc_operation){
    uint64_t* data_ptr = reinterpret_cast<uint64_t*>(mmc_operation->data_ptr);
    if(fd >= 0){
        for (size_t i = 0; i < mmc_operation->blksz; i++)
        {
            *(data_ptr)++ = i;
        }

        return 0;
    }
    return -1;
}


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
        if(mock_emmc_ioctl(emmc_fd, MMC_IOC_CMD, &data) < 0){
            std::cerr << "ioctl failed";
        } else {
            for(auto& datum : emmc_data){
                std::cout << datum << '\n';
            }
            return state;
        }
        close(emmc_fd);
    } else {
        std::cerr << "Unable to open emmc device: " << std::string(strerror(errno));
    }
    return state;
}

// std::shared_ptr<emmc_block_t> emmc_data_view(){
//     return std::make_shared<emmc_block_t>(emmc_block);
// }


// int test_emmc(){
//     emmc::registers::cid_data_t cid;
//     int count = 0;
//     if(emmc::utils::read_register(cid)){
//         for(auto&& element: cid){
//             std::cout << "element#:" << static_cast<int>(element) << '\n';
//             count++;
//         }
//     }
//     return count;

// }

int main(int argc, char** argv){
    // std::cout << std::hex << &emmc_data[0] << '\n';
    auto addr =  emmc_data.data();
    std::cout << addr << '\n';
    std::cout << alignof(std::max_align_t) << '\n';
    std::cout << alignof(emmc_data.data()) << '\n';
    std::cout << sizeof(unsigned long) << '\n';

    std::cout << "reference counter: " << emmc_block.use_count();
    // auto view_array = emmc_data_view();
    std::cout << "reference counter: " << emmc_block.use_count();
    std::vector<uint8_t> copy_mmc;
    {
        emmc::utils::handle_fd mmcblk0("/tmp/some_file");
        std::cout << "It was successfully open: " << !mmcblk0 << '\n';

    }
    {
        std::cout << "Test find_in_sys" << emmc::detail::find_in_sys("/dev/mmcblk0").str();
        
        emmc::registers::cid_data_t cid{0};
        std::cout << "Test read cid" << emmc::utils::read_cid_register(cid, "/dev/mmcblk0");
        for (auto &&i : cid){
            std::cout << std::hex << i << ' ';
        }
        
        emmc::registers::csd_data_t csd{0};
        std::cout << "Test read csd" << emmc::utils::read_csd_register(csd, "/dev/mmcblk0");
        for (auto &&i : csd){
            std::cout << std::hex << i << ' ';
        }
        

    }
    // emmc_health(copy_mmc);
    // for (auto &&i : emmc_data)
    // {
        // std::cout << "emmc:" << static_cast<int>(i) << '\n';
    // }
    // test_emmc();
    return argc;
}