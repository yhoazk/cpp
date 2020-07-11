#include <iostream>
#include "arp_ex.h"

int main() {
    std::vector<net::arp_entry_t> arp_v{};
    std::vector<net::arp_entry_t> arp_local_link{};
    net::ipv4_t local{192,168,1,0};
    net::ipv4_t apipa{164,254,0,0};
    for (size_t i = 0; i < 10; i++) {
        arp_v.push_back(net::test_helper::generate_arp_entry(local, 0));
    }
    for (size_t i = 0; i < 10; i++) {
        arp_local_link.push_back(net::test_helper::generate_arp_entry(apipa, 0));
    }
    
    net::arp_table_t original;
    net::arp_table_t modified;

    original["eth0"] = arp_v;
    original["eth1"] = arp_local_link;

    modified["eth0"] = arp_v;
    modified["eth1"] = arp_local_link;

    for(const auto& ent : modified["eth0"]) {
        net::test_helper::print_entry(ent);
    }

    net::symetric_diff(original,modified);

    std::cout << "\n====Modify the ARP table\n";

    modified["eth0"][0].first[0] = 0; 
    for(const auto& ent : modified["eth0"]) {
        net::test_helper::print_entry(ent);
    }
    net::symetric_diff(original,modified);

    return 0;
}