

#include <map>
#include <set>
#include <array>
#include <vector>
#include <random>
#include <functional>
#include <iomanip>
#include <algorithm>

namespace net
{


    using ipv4_t = std::array<uint8_t, 4>;
    using mac_t = std::array<uint8_t, 6>;
    using arp_entry_t = std::pair<ipv4_t, mac_t>;
    using arp_table_t = std::map<const std::string, std::vector<arp_entry_t>>;


    namespace test_helper {
        std::default_random_engine gen;
        std::uniform_int_distribution<uint8_t> rnd_oct(1,255);
        auto oct_gen = std::bind(rnd_oct, gen);

        arp_entry_t generate_arp_entry(ipv4_t ip, size_t mask, bool same_mac = false)
        {
            arp_entry_t entry;
            for (auto &oct : ip)
            {
                if (0 == oct)
                {
                    oct = oct_gen();
                }
            }
            mac_t mac;
            for (auto &m : mac)
            {
                m = oct_gen();
            }
            return std::make_pair(ip, mac);
        }
        void print_entry(arp_entry_t entry){
            std::cout << "IP: ";
            for(const auto& ip : entry.first) {
                std::cout << std::to_string(ip) << '.';
            }
            std::cout << " MAC: ";
            for(const auto& mac : entry.second) {
                std::cout << std::hex << static_cast<int>(mac) << ':';
            }
            std::cout << '\n';
        }
    } // namespace test_helper


    arp_table_t symetric_diff(arp_table_t& table_a, arp_table_t& table_b) {
        arp_table_t diff{};
        if(table_a != table_b) {
            // assume both have the same interfaces
            std::set<std::string> ifaces_a;
            std::set<std::string> ifaces_b;
            std::set<std::string> ifaces_common;
            for(auto& elem : table_a) {
                std::cout << "Table a ifaces: " << elem.first << '\n';
                ifaces_a.emplace(elem.first);
            }
            for(auto& elem : table_b) {
                std::cout << "Table b ifaces: " << elem.first << '\n';
                ifaces_b.emplace(elem.first);
            }
            std::set_union(std::begin(ifaces_a), std::end(ifaces_a), std::begin(ifaces_b), std::end(ifaces_b), std::inserter(ifaces_common, ifaces_common.begin()));
            for(auto& iface : ifaces_common) {
                std::cout << "Common interfaces: " << iface << '\n';
            }

            for(const auto& name : ifaces_common) {
                std::vector<arp_entry_t> diff_entries;
                std::set_symmetric_difference(std::begin(table_a[name]), std::end(table_a[name]),
                std::begin(table_b[name]), std::end(table_b[name]), std::back_inserter(diff_entries));

                std::cout << "Diff: " << std::to_string(diff_entries.size()) << '\n';
                for(auto& k : diff_entries) {
                    test_helper::print_entry(k);
                }
            }
        }
        return diff;

    }

} // namespace net
