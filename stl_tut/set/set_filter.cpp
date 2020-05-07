#include <iostream>
#include <set>
#include <map>
#include <array>
#include <vector>
#include <functional>
#include <string>
#include <algorithm>


#include <ifaddrs.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/if_packet.h>
#include <net/ethernet.h>

namespace network
{
    using mac_t = std::array<uint8_t, 6>;
    using ipv4_t = std::array<uint8_t, 4>;
    constexpr auto mac_size = std::tuple_size<mac_t>::value;
    constexpr auto ipv4_size = std::tuple_size<ipv4_t>::value;

    enum class device_class_t : size_t {
        lo = 0,
        sit = 1,
        bridge = 2,
        vlan = 3,
        ethernet = 4,
        unk = 200
    };

    struct network_interface  {
        bool plugged;
        bool admin_up;
        mac_t mac;
        ipv4_t ipv4;
        size_t index;
        device_class_t dev_class;
    };

    namespace filter {
        bool is_admin_up(network_interface& ni) { return (1 == ni.admin_up); }
        bool is_plugged(network_interface& ni) { return (1 == ni.plugged); }
        bool is_bridge(network_interface& ni) { return (device_class_t::bridge == ni.dev_class); }
        bool is_lo(network_interface& ni) { return (device_class_t::lo == ni.dev_class); }
        bool is_ethernet(network_interface& ni) { return (device_class_t::ethernet == ni.dev_class); }
    }

    network_interface eth0{
        .plugged = true, .admin_up = true, .mac = {0,1,2,3,4,5}, .ipv4 = {9,8,7,6}, .index = 0, .dev_class = device_class_t::ethernet
    };

    network_interface eth1{
        .plugged = true, .admin_up = true, .mac = {0,1,2,3,4,7}, .ipv4 = {9,8,7,9}, .index = 1, .dev_class = device_class_t::ethernet
    };

    network_interface eth2{
        .plugged = true, .admin_up = false, .mac = {0,1,2,3,4,2}, .ipv4 = {9,8,7,1}, .index = 2, .dev_class = device_class_t::ethernet
    };

    network_interface br0{
        .plugged = true, .admin_up = true, .mac = {0,4,4,5,5,5}, .ipv4 = {1,2,7,0}, .index = 3, .dev_class = device_class_t::bridge
    };

    network_interface lo{
        .plugged = true, .admin_up = true, .mac = {2,3,44,5,45,5}, .ipv4 = {1,2,72,20}, .index = 4, .dev_class = device_class_t::lo
    };



    using network_settings = std::map<const std::string, network_interface&>;

    bool fetch_networksettings(network_settings& ns){
        ns.emplace("eth0", eth0);
        ns.emplace("eth1", eth1);
        ns.emplace("eth2", eth2);
        ns.emplace("br0", br0);
        ns.emplace("lo", lo);
        return true;
    }

    // why network settings cannot be a const reference?
    bool filter_interfaces(network_settings& ns, std::set<std::string>& output, std::vector<std::function<bool(network_interface&)>> filters){
        for(const auto& interface : ns){
            std::cout << "Insert interface: " << interface.first << '\n';
            output.insert(interface.first);
        }
 
        for(auto& filter : filters) {
            for(auto set_it = output.begin(); set_it!=output.end(); ++set_it){
                if(filter(ns[*set_it])){
                    std::cout << "Deleting: " << *set_it << '\n';
                    output.erase(*set_it);
                }
            }
        }
        return true;
    }

} // network name



int main(int argc, char const *argv[])
{
    network::network_settings net_set{};
    network::fetch_networksettings(net_set);
    std::set<std::string> ifaces{};

    network::filter_interfaces(net_set, ifaces, {
        network::filter::is_admin_up,
        network::filter::is_ethernet
    });
    return 0;
}
