/*
    \brief some header information to be filled
*/
#include "netcfg.hpp"
#include "backend/netlink_socket.h"

int skfd = -1;


#if 0
bool get_ip(std::string iface_name){
    struct ifreq ifr;
    struct sockadd_in sock_in;
    int name_len = IFNAMSIZ;
    // zero the structs
    memset(&ifr, 0, sizeof(struct ifreq));
    memset(&sock_in, 0, sizeof(struct sockadd_in));

    // create the socket to communicate with the interface
    int  socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(socket_fd == -1){
        perror("Creting socket");
    }
    // set the name of the interface we want to get the ip
    name_len = (name_len > iface_name.length())? iface_name.length() : name_len;
    strncpy(ifr.iface_name, iface_name, name_len);

    if(ioctl(socket_fd, SIOCGIFADDR, &iface) < 0){
        perror("ioclt get ip");
    }

    sock_in = (struct sockaddr_in*)&ifr.ifr_addr;
    printf("%s\n", inet_ntoa(sock_in->sin_addr));
    return true;
}
#endif

std::vector<std::string> split(const std::string& s, char delimiter){
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenstream(s);
    while(std::getline(tokenstream, token, delimiter)){
        //if(isspace(token)) continue;
        tokens.push_back(token);
    }
    return tokens;
}


int set_iface_flags(std::string ifname, uint16_t flags){
    struct ifreq ifr;
    int res = 0;

    ifr.ifr_flags = flags;
    strncpy(ifr.ifr_name, ifname.c_str(), IFNAMSIZ);
    res = ioctl(skfd, SIOCSIFFLAGS, &ifr);
    return res;
}

void setup(){
  if( (skfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
      perror("socket");
  }
}

bool ifdown(std::string& iname){
    return true;
}


bool ifup(std::string& iname){
    return true;
}

//grep -E "[a-z0-9]{2,}(?=\r|\n|$)" /proc/net/arp

bool getArp(std::vector<uint8_t>& arp_result){
    using namespace std;
    char lines[128];
    ifstream arp_node ("/proc/net/arp");
    if(!arp_node.is_open()) return false;
    std::string line, iface;
    struct arp_entry{
        array<uint8_t,4> ip;
        array<uint8_t,6> mac;
    };
    unordered_map<string, vector<arp_entry> > arp_table;
    regex rgx_mac   ( R"rgx(([0-9A-Fa-f]{2}[:-]){5}([0-9A-Fa-f]{2}))rgx");
    regex rgx_ip    ( R"rgx(([0-9]{1,3}\.){3}[0-9]{1,3})rgx");

    smatch match_ip;
    smatch match_mac;
    // scrap header
    arp_node.getline(&lines[0], 127);
    while(arp_node.good()){
        fill(begin(lines), end(lines), '\0');
        getline(arp_node, line);
        auto it = line.find_last_of(' ');
        iface.assign(line.substr(it+1));
        arp_entry entry;

        if(regex_search(line, match_mac, rgx_mac)){
            cout << "MAC: " << match_mac[0];
        }
        if(regex_search(line, match_ip, rgx_ip)){
            cout << "  IP: " << match_ip[0];
        }
        cout << "  For Iface: " << iface << '\n';
        auto ip_bytes = split(match_ip[0], '.');
        auto mac_bytes = split(match_mac[0], ':');

        auto iface_map = arp_table.find(iface);

        if(end(arp_table) != iface_map){
            arp_table[iface].push_back(entry);
        } else{
            arp_table.emplace( make_pair(iface, vector<arp_entry>{entry} ) );
        }

        for(size_t i = 0; i < ip_bytes.size(); ++i){
            // insert the converted ascii->int to the
            // entry.ip array
            // see std::stoi see also the optional parameter for base
            // for the case of hex in mac
            entry.ip[i] = stoi(ip_bytes[i]);
        }
        // for(size_t j = 0; j < mac_bytes.size(); ++j){
        //     entry.mac[j] = stoi(mac_bytes[j], 16);
        // }

    }
    arp_node.close();

    return true;
}

int main(){
    {
        using namespace netlink;
        nl_socket nls;
        nls.allocate();
        nls._bind();
        nls.show();
    }
    /*
    std::vector<uint8_t> test;
    getArp(test);

    setup();
    return (0);
    */

}