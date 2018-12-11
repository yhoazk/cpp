#include "logger.h"

void logger::info(std::string log) noexcept{
    std::cout << log << std::endl;
}
void logger::warn(std::string log) noexcept{
    std::cout << log << std::endl;
}
void logger::error(std::string log) noexcept{
    std::cerr << log << std::endl;
}
void logger::fatal(std::string log) noexcept{
    std::cerr << log << std::endl;
}
