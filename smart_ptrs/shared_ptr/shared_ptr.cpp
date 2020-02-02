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


//alignas(8) std::array<std::uint64_t, kBlockSize> emmc_data;
// share a pointer to this array or create a filter where the 
// passed array is filtered according to the given settings


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
    // auto view_array = emmc_data_view();
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
        std::cout << std::endl;
        emmc::registers::csd_data_t csd{0};
        std::cout << "Test read csd" << emmc::utils::read_csd_register(csd, "/dev/mmcblk0");
        for (auto &&i : csd){
            std::cout << std::hex << i;
        }
        std::cout << std::endl;
        
        emmc::registers::ecsd_data_t ext_csd{0};
        std::cout << "Test read ext_csd" << emmc::utils::read_ecsd_register(ext_csd, "/dev/mmcblk0");
        for (auto &&i : ext_csd){
            std::cout << std::hex << i;
        }
        std::cout << std::endl;
        

    }
    // emmc_health(copy_mmc);
    // for (auto &&i : emmc_data)
    // {
        // std::cout << "emmc:" << static_cast<int>(i) << '\n';
    // }
    // test_emmc();
    return argc;
}