#include <iostream>
#include <type_traits>
#include <array>

using alias_array = std::array<uint8_t, 128>;

int main(int argc, char const *argv[])
{
    std::cout << "int vs int32_t: " << std::is_same<int, int32_t>::value << '\n';
    std::cout << "alias_array vs array<uint8_t, 128>" << std::is_same<alias_array, std::array<uint8_t, 128>>::value << '\n';
    return 0;
}
