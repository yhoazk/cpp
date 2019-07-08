#include <bits/stdc++.h>

using namespace std;

using ip_address_t = array<uint8_t, 4>;
using mac_address_t = array<uint8_t, 6>;

struct iface_properties {
  ip_address_t ip;
  mac_address_t mac;
  bool loopback;
  bool running;
};

using ip_proprerties = map<string, iface_properties>;
//vector<pair<const string, iface_properties>&> filtered_ifaces;
vector<pair<const string, iface_properties>> filtered_ifaces;
ip_proprerties ip_settings;

template<class T>
void print_ifconfig(const T& ip_cfg){
  for(auto& entry : ip_cfg){
    cout << "Name: " << entry.first;
    cout << " IP: " << dec;
    for(auto& oct : entry.second.ip){
      cout << static_cast<int>(oct) << ".";
    }
    cout << "\t Mac: ";
    for(auto& mac_oct : entry.second.mac){
      cout << hex << static_cast<int>(mac_oct) << ':';
    }
    cout << "\t Loopback " << entry.second.loopback;
    cout << "\t running " << entry.second.running << '\n';
  }
}

int main(int argc, char const *argv[])
{
  iface_properties ethn = {{192,156,22,0}, {11,22,33,44,55,66}, false, true};
  ip_settings.emplace("eth0", ethn);
  ethn.loopback = true;
  ip_settings.emplace("lo", ethn);
  ethn.running = false;
  ethn.loopback = false;
  ip_settings.emplace("eth0.73", ethn);

  auto noloop_and_up = [=](pair<string,iface_properties> dict_e){
      return (!dict_e.second.loopback && dict_e.second.running);
  };
  // remove if cannot be used as the map elements contain a const as
  // a key, which does not fit with the remove_if
  //remove_if(begin(ip_settings), end(ip_settings), noloop_and_up);
  for (auto element : ip_settings){
    if(!element.second.loopback && element.second.running){
      filtered_ifaces.push_back(element);
    }
  }

  cout << ip_settings.size();
  print_ifconfig(ip_settings);
  cout << "------\n";
  print_ifconfig(filtered_ifaces);
  return 0;
}
