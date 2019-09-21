#ifndef _IP_TYPES_
#define _IP_TYPES_

#include <array>
#include <string>

namespace ip_types
{
    const std::size_t IPV4_ADDR_LEN = 4u;
    using ipv4_addrs_t = std::array<std::uint8_t, IPV4_ADDR_LEN>;
    
    const std::size_t IPV6_ADDR_LEN = 16u;
    using ipv4_addrs_t = std::array<std::uint8_t, IPV6_ADDR_LEN>;

    const std::size_t MAC_LEN = 6u;
    using mac_addrs_t = std::array<std::uint8_t, MAC_LEN>;

    const std::size_t IFNAMSIZ = 16u;
    using interface_name_t = std::string;
} // namespace ip_types


#endif /* _IP_TYPES_ */