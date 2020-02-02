#include <array>
#include <string>
#include <iostream>
#include <fstream>
#include <cerrno>

#include <sys/stat.h>
#include <sstream>
/* whether the variable is in stack or in heap
   is relevant depending on the OS. In FC30 x86_64
   the  */

namespace emmc { 
namespace detail {

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
    const size_t mmc_block_bize{512};
    const size_t mmc_driver_major = MMC_BLOCK_MAJOR;

    // enum jedec_cmd : unsgined int {
    //     send_ext_csd = 8u,
    //     gen_cmd      = 56u,
    // };
    // Jedec eMMC command list, only adtc supported/needed
    enum jedec_cmd : unsigned int {
        send_ext_csd = 8u,
        gen_cmd      = 56u,
    };
    // Note: Micron specific
    enum cmd65_micron : unsigned int {
        fw_mac          = 0b00000000, // firmware message autentication code (MAC) signature check
        init_rt_bbc     = 0b00001000, // initial run time bad block, and remaining spare blocks count
        min_avg_max     = 0b00010000, // Min/Max/Avg erase count
        min_avg_max_mlc = 0b00010001, // Min/Max/Avg erase count MLC area
        min_avg_max_slc = 0b00010010, // Min/Max/Avg erase count SLC area
        bbc_count_info  = 0b01000000, // Bad block count information
        blk_erase_cnt_t = 0b01000001, // Total number of block erase count tables
        blk_erase_ret_r = 0b01000010, // Block erase count retrieve
        blk_addr_type   = 0b01000011, // Block address type retrieve
        buf_blk_refresh = 0b01010011, // Buffer blocks refresh
    };



    std::stringstream find_in_sys(const char* c_path){
        std::stringstream sys_path{};

        struct stat dev_stat;
        if(stat(c_path, &dev_stat) == 0){
            int major = static_cast<int>( (dev_stat.st_rdev & 0xff00) >> 8);
            int minor = static_cast<int>( (dev_stat.st_rdev & 0xff) );

            if(MMC_BLOCK_MAJOR == major){
                sys_path << "/sys/dev/block/";
                sys_path << major << ':' << minor;
                sys_path << "/device/";
            } else {
                std::cerr << "Not an eMMC device!\n";
            }

        } else {
            sys_path.str(std::string());
        }
        return sys_path;
    }

    std::stringstream find_in_sys(std::string& dev_path){
        return find_in_sys(dev_path.c_str());
    }

} // napespace detail
namespace settings {
    struct config {
        uint8_t dev_name[16];
    };
    using emmc_512block_t =  /*alignas(16)*/ std::array<uint8_t, 512>;
    using emmc_128block_t =  /*alignas(16)*/ std::array<uint8_t, 128>;
} // namespace

namespace registers {
    // from TN-FC-32:
    //enum class register_size : size_t{
    enum register_size : size_t{
        kCID   = 128,  // Card identification
        kCSD   = 128,  // Card-specific data
        kECSD  = 512,  // Extended card-specific data
        kECRD  = 512,  // Erase count response data
        kBBCRD = 512   // Bad block count response data
    };

    using cid_data_t   = std::array<uint8_t, register_size::kCID>;
    using csd_data_t   = std::array<uint8_t, register_size::kCSD>;
    using ecsd_data_t  = std::array<uint8_t, register_size::kECSD>;
    using ecrd_data_t  = std::array<uint8_t, register_size::kECRD>;
    using bbcrd_data_t = std::array<uint8_t, register_size::kBBCRD>;

} // namespace registers


namespace utils {
    // send emmc command
    // enum commands : uint8_t {

    // }
    // Every command has a fixed length of 48bits
    //  addressed data transfer commands
    // using adct_cmd_t = std::array<uint8_t, 6>;
    // only adtc commands will be supported for now
    struct mmc_ioc_cmd cmd8_factory(uint8_t* data){
        using namespace emmc::detail;
        
        struct mmc_ioc_cmd cmd;
        memset(&cmd, 0, sizeof(mmc_ioc_cmd));
        cmd.write_flag = 0;
        cmd.opcode = detail::jedec_cmd::send_ext_csd;
        cmd.arg = 0;
        cmd.flags  = mmc_rsp_spi_r1 | mmc_rsp_r1 | mmc_cmd_adtc;
        cmd.blksz  = detail::mmc_block_bize;
        cmd.blocks = 1;
        mmc_ioc_cmd_set_data(cmd, data);
        return cmd;
    };

    struct mmc_ioc_cmd cmd56_factory(uint8_t* data, 
                                     detail::cmd65_micron cmd56_arg){
        using namespace emmc::detail;
        
        struct mmc_ioc_cmd cmd;
        memset(&cmd, 0, sizeof(mmc_ioc_cmd));

        cmd.write_flag = 0;
        cmd.opcode = detail::jedec_cmd::gen_cmd;
        cmd.arg = cmd56_arg;
        cmd.flags  = mmc_rsp_spi_r1 | mmc_rsp_r1 | mmc_cmd_adtc;
        cmd.blksz  = detail::mmc_block_bize;
        cmd.blocks = 1;
        mmc_ioc_cmd_set_data(cmd, data);
        return cmd;
    };


// enable_if 

    class handle_fd {
        int _fd;
        char _dev_name[25];
        public:
        explicit handle_fd(std::string dev_name): _fd{-1} {
            std::cout << "opening device" << dev_name << '\n';
            _fd = open(dev_name.c_str(), O_RDWR);
            if(-1 == _fd){
                std::cerr << "Unable to open device: " << dev_name
                          << std::string(strerror(errno)) << '\n';
            }else{
                memcpy(_dev_name, dev_name.c_str(), sizeof(_dev_name));
                _dev_name[24] = '\0';
            }
        }

        // do not forget to close the emmc file handle
        ~handle_fd(){
            if(_fd != -1){
                std::cout << "closing device" << _dev_name << '\n';
                close(_fd);
            }
        }
        // Return a copy of the fd
        int get() const { return _fd; }
        // enable status checks 
        // bool operator !(){ return !(-1 != _fd); }
        operator bool(){ return (-1 != _fd); }
    };

    bool do_read_emmc(int fd, mmc_ioc_cmd* cmd_data){
        bool status{false};
        if(ioctl(fd, MMC_IOC_CMD, cmd_data) != -1){
            // at this point the data has been copied to the given array
            std::cout << "success ioctl\n";
            status = true;
        } else {
            std::cerr << "ioctl failed: " << std::string(strerror(errno)) << '\n';
        }
        return status;
    }

    // cid does not need to send an ioctl? No
    // the cid data is gathered during device initialization by the driver
    bool read_cid_register(emmc::registers::cid_data_t& cid_data, const char* emmc_dev_path){
        static_assert(alignof(cid_data.data()) >= 8ul, "Data should be aligned to at least 8bytes");
        bool status{false};
        auto sys_path = emmc::detail::find_in_sys(emmc_dev_path);
        sys_path << "cid";
        std::ifstream cid_reg(sys_path.str(), std::ios::binary);

        if(cid_reg.is_open()){
            cid_reg.read(reinterpret_cast<char*>(cid_data.data()), cid_data.size());
        }

        return status;
    }


    bool read_csd_register(emmc::registers::csd_data_t& csd_data, const char* emmc_dev_path){
        static_assert(alignof(csd_data.data()) >= 8ul, "Data should be aligned to at least 8bytes");
        bool status{false};
        auto sys_path = emmc::detail::find_in_sys(emmc_dev_path);
        sys_path << "csd";
        std::ifstream cid_reg(sys_path.str(), std::ios::binary);

        if(cid_reg.is_open()){
            cid_reg.read(reinterpret_cast<char*>(csd_data.data()), csd_data.size());
        }

        return status;
    }

    bool read_ecsd_register(emmc::registers::ecsd_data_t& ecsd_data, const char* emmc_dev_path){
        static_assert(alignof(ecsd_data.data()) >= 8ul, "Data should be aligned to at least 8bytes");
        handle_fd dev_emmc(emmc_dev_path);
        bool status{false};

        if(dev_emmc.get() != -1){
            auto cmd = cmd8_factory(ecsd_data.data());
            status = do_read_emmc(dev_emmc.get(), &cmd);
        }
        return status;
    }
    // erase count response 
    bool read_ecrd_register(emmc::registers::ecrd_data_t& ecrd_data, const char* emmc_dev_path){
        static_assert(alignof(ecrd_data.data()) >= 8ul, "Data should be aligned to at least 8bytes");
        handle_fd dev_emmc(emmc_dev_path);
        bool status{false};

        if(dev_emmc.get() != -1){
            auto cmd = cmd56_factory(ecrd_data.data(), detail::cmd65_micron::blk_erase_cnt_t);
            status = do_read_emmc(dev_emmc.get(), &cmd);
        }
        return status;
    }
    bool read_bbcrd_register(emmc::registers::bbcrd_data_t& bbcrd_data, const char* emmc_dev_path){
        static_assert(alignof(bbcrd_data.data()) >= 8ul, "Data should be aligned to at least 8bytes");
        handle_fd dev_emmc(emmc_dev_path);
        bool status{false};

        if(dev_emmc.get() != -1){
            auto cmd = cmd56_factory(bbcrd_data.data(), detail::cmd65_micron::bbc_count_info);
            status = do_read_emmc(dev_emmc.get(), &cmd);
        }
        return status;
    }




} // namespace utils


} // namespace emmc