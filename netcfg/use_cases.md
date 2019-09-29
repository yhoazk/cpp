### List all interfaces

```cpp
auto interfaces = network_config().get_all();
for(auto& iface : interfaces){
    // get interface by name or by index
    std::cout << iface.name << '\n';
}
```

### Get a single interface by name

```cpp
ip_types::eth_interface eth0 = network_config().get_by_name("eth0");
std::cout << eth0.name;
```
### Get a single interface by index

```cpp
ip_types::eth_interface ifidx1 = network_config().get_by_index(1);
ifidx1.name = ip_types::ifname{"eth0"};
```

### Get IP address of an interface

```cpp
ip_types::eth_interface eth0 = network_config().get_by_name("eth0");
std::cout << eth0.ip;
```
### Set ip address of an interface

```cpp
ip_types::eth_interface eth0 = network_config().get_by_name("eth0");
eth0.ip += ip_types::ip{192,168,1,22};
network_config.apply(eth0); // could this be done at the dtor of the calling fnc?
```

### Get mac address of an interface

```cpp
ip_types::eth_interface eth0 = network_config().get_by_name("eth0");
std::cout << eth0.mac.to_str(); // possibly overload the <<(str) op
```

### Get ip addresses of all the interfaces

```cpp
std::vector<ip_types::interface> interfaces = network_config().get_all();
for(const auto& iface : interfaces){
    std::cout << "ip: " << iface.ip << " mac: " << " mac: " << iface.mac << '\n';
}
```
### set interface up

If the state of the interface is the same as the current state.
No action is performed.

```cpp
ip_types::eth_interface eth0 = network_config().get_by_name("eth0");
eth0.admin_state = true;
// or
eth0.admin_state = ip_types::admin_state_up;
network_config().apply(eth0);
```

### set interface down

Here is also the use case for sending confirmation on the interface about the
result of the operation, so a delay is needed before actually setting the 
interface down.

```cpp
using namespace std::chrono_literals;
ip_types::eth_interface eth0 = network_config().get_by_name("eth0");
eth0.admin_state = false;
eth0.admin_state = ip_types::admin_state_down;
auto delay = 200ms;
network_config().apply(eth0, delay);
```

### get connection state of the interface

Note that in this case carrier reflects also the operational state, normally
the carrier could be connected but if the interface is down the carrier is
get a different meaning.

```cpp
ip_types::eth_interface eth0 = network_config().get_by_name("eth0");
std::cout << eth0.carrier;
```

### try to set the connection state of the interface

```cpp
ip_types::eth_interface eth0 = network_config().get_by_name("eth0");
eth0.carrier = true;
//print error to console, and return error. No action is performed
network_config.apply(eth0);
```

### try to set the mac address of an interface

```cpp
ip_types::eth_interface eth0 = network_config().get_by_name("eth0");
eth0.mac = ip_types::mac{0xab, 0xfa, 0x44, 0x33, 0x55, 0x66};
//print error to console, and return error. No action is performed
network_config.apply(eth0);
```
### read the promisc state of an interface

```cpp
ip_types::eth_interface eth0 = network_config().get_by_name("eth0");
if(eth0.promisc == true){
    std::cout << "eth0 promisc mode is activated\n";
}
```
### write the promisc state of an interface

```cpp
ip_types::eth_interface eth0 = network_config().get_by_name("eth0");
eth0.promisc = true;
network_config().apply(eth0);
```

### create a bridge interface

```cpp
ip_types::bridge_interface br0 = network_config().new<ip_types::device_class::bridge>();
// br0 now contains the skeleton of the interface
br0.name = "br0";
network_config().apply(br0);
```

### remove a bridge interface 

```cpp
auto br0 = network_config().get_by_name("br0");
network_config().del(br0).apply();
```

### add an interface to the bridge

```cpp
auto br0 = network_config().get_by_name("br0");
br0.slave += network_config().get_by_name("eth0");
br0.slave += network_config().get_by_name("eth1");
network_config().apply(br0);
```

### remove an interface of the bridge

```cpp
```
### list all the interfaces of the bridge

```cpp
```
### set the name of the interface

```cpp
```
### read the name of the interface

```cpp
```
### write the name of an interface which name was already Set

```cpp
```
### add a vlan interface to an existing interface

```cpp
```
### remove a vlan interface

```cpp
```
### read the state of a virtual interface

```cpp
```
### get macs from the bridge interface

```cpp
```

### add a multicast address

```cpp
```
### remove a multicast address

```cpp
```
### re-add a multicast  address

```cpp
```
### get the multicast address of the interface

```cpp
```
### add a brodcast address

```cpp
```
### remove a broadcast address
```cpp
```
### get the assigned broadcast address of the interface

```cpp
```
### set routes for the interface 

```cpp
```
### read routes assigned to the interface

```cpp
```
