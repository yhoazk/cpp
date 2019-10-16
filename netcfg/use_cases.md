Read operations should not need to call `apply`, only for `arp` and `statistics`

### List all interfaces

```cpp
auto interfaces = network_config().get_all();
for(auto& iface : interfaces){
    // get interface by name or by index
    std::cout << iface.name << '\n';
}
```
#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``


### Get a single interface by name

```cpp
ip_types::eth_interface eth0 = network_config().get_by_name("eth0");
std::cout << eth0.name;
```

#### req data

* rtnetlink message: `RTM_GETLINK`
* operation: `GET`
* flags: `NLM_F_REQUEST`
* Required attrs:
    * `IFLA_EXT_MASK`:`9`
    * `IFLA_IFNAME`:`str::ifacename`

### Get a single interface by index


```cpp
ip_types::eth_interface ifidx1 = network_config().get_by_index(1);
ifidx1.name = ip_types::ifname{"eth0"};
```
#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``


### Get IP address of an interface

```cpp
ip_types::eth_interface eth0 = network_config().get_by_name("eth0");
std::cout << eth0.ip;
```
#### req data
* rtnetlink message: `RTM_GETLINK`
* operation: `GET`
* flags: `NLM_F_REQUEST`
* Required attrs:
    * `IFLA_EXT_MASK`:`9`
    * `IFLA_IFNAME`:`str::ifacename`

### Set ip address of an interface

```cpp
ip_types::eth_interface eth0 = network_config().get_by_name("eth0");
eth0.ip += ip_types::ip{192,168,1,22};
network_config.apply(eth0); // could this be done at the dtor of the calling fnc?
```
#### req data

* rtnetlink message: `RTM_NEWADDR`
* operation: ``
* flags: `NLM_F_REQUEST|NLM_F_ACK|NLM_F_EXCL|NLM_F_CREATE`
* Required attrs:
    * `IFA_LOCAL`:`inet_addr("192.166.12.11")`
    * `IFA_ADDRESS`:`inet_addr("192.166.12.11")`

### Get mac address of an interface

```cpp
ip_types::eth_interface eth0 = network_config().get_by_name("eth0");
std::cout << eth0.mac.to_str(); // possibly overload the <<(str) op
```
#### req data

* rtnetlink message: `RTM_GETLINK`
* operation: `GET`
* flags: `NLM_F_REQUEST`
* Required attrs:
    * `IFLA_EXT_MASK`:`9`
    * `IFLA_IFNAME`:`str::ifacename`

### Get ip addresses of all the interfaces

```cpp
std::vector<ip_types::interface> interfaces = network_config().get_all();
for(const auto& iface : interfaces){
    for(const auto& ip_element: iface.ip_list){
        std::cout << "ip: " << iface.ip << " mac: " << " mac: " << iface.mac << '\n';
    }
}
```
#### req data

* rtnetlink message: `RTM_GETLINK`
* operation: `GET`
* flags: `NLM_F_REQUEST`
* Required attrs:
    * `IFLA_EXT_MASK`:`9`
    * `IFLA_IFNAME`:`str::ifacename`

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
#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``
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
#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``

### get connection state of the interface

Note that in this case carrier reflects also the operational state, normally
the carrier could be connected but if the interface is down the carrier is
get a different meaning.

```cpp
ip_types::eth_interface eth0 = network_config().get_by_name("eth0");
std::cout << eth0.carrier;
```
#### req data

* rtnetlink message: `RTM_GETLINK`
* operation: `GET`
* flags: `NLM_F_REQUEST`
* Required attrs:
    * `IFLA_EXT_MASK`:`9`
    * `IFLA_IFNAME`:`str::ifacename`

### try to set the connection state of the interface

```cpp
ip_types::eth_interface eth0 = network_config().get_by_name("eth0");
eth0.carrier = true;
//print error to console, and return error. No action is performed
network_config.apply(eth0);
```
#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``
### try to set the mac address of an interface

```cpp
ip_types::eth_interface eth0 = network_config().get_by_name("eth0");
eth0.mac = ip_types::mac{0xab, 0xfa, 0x44, 0x33, 0x55, 0x66};
//print error to console, and return error. No action is performed
network_config.apply(eth0);
```
#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``
### read the promisc state of an interface

```cpp
ip_types::eth_interface eth0 = network_config().get_by_name("eth0");
if(eth0.promisc == true){
    std::cout << "eth0 promisc mode is activated\n";
}
```
#### req data

* rtnetlink message: `RTM_GETLINK`
* operation: `GET`
* flags: `NLM_F_REQUEST`
* Required attrs:
    * `IFLA_EXT_MASK`:`9`
    * `IFLA_IFNAME`:`str::ifacename`

### write the promisc state of an interface

```cpp
ip_types::eth_interface eth0 = network_config().get_by_name("eth0");
eth0.promisc = true;
network_config().apply(eth0);
```
#### req data

* rtnetlink message: `RTM_NEWLINK`
* operation: `NEW`
* flags: `NLM_F_REQUEST|NLM_F_ACK`
* Required attrs:
    * `ifi_index`:`if_nametoindex("enp7s0")`
    * `ifi_flags`:`IFF_PROMISC`
    * `ifi_change`:`0x100`
### create a bridge interface

```cpp
ip_types::bridge_interface br0 = network_config().new<ip_types::device_class::bridge>();
// br0 now contains the skeleton of the interface operation
br0.name = "br0";
network_config().apply(br0);
```
#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``
### remove a bridge interface 

```cpp
auto br0 = network_config().get_by_name("br0");
network_config().del(br0).apply();
```
#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``
### add an interface to the bridge

```cpp
auto br0 = network_config().get_by_name("br0");
br0.slave += network_config().get_by_name("eth0");
br0.slave += network_config().get_by_name("eth1");
network_config().apply(br0);
```
#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``
### remove an interface of the bridge

```cpp
auto br0 = network_config().get_by_name("br0");
br0.slave -= network_config().get_by_name("eth0");
network_config().apply(br0);
```
#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``

### list all the interfaces of the bridge

```cpp
auto br0 = network_config().get_by_name("br0");
for(auto& child : br0.slaves){
    std::cout << child.name
}
```

#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``
### set the name of the interface

```cpp
auto eth0 = network_config().get_by_index(2); // normally lo is 1
eth0.name = ip_types::ifname{"eth0"};
network_config().apply(eth0);
```
#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``
### read the name of the interface

```cpp
auto eth0 = network_config().get_by_index(2); // normally lo is 1
std::cout << eth0.name;
```
#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``
### write the name of an interface which name was already Set

```cpp
auto eth0 = network_config().get_by_index(2); // normally lo is 1
eth0.name = ip_types::ifname{"eth0"};
network_config().apply(eth0); // should we return a value to indicate NOP?
```
#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``
### add a vlan interface to an existing interface

```cpp
ip_types::vlan_interface eth0_73 = network_config().new<ip_types::device_class::vlan>();
eth0_73.name = "eth0.73";
eth0_73.attached_to = network_config().get_by_name("eth0");
network_config().apply(eth0_73);
```
#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``
### remove a vlan interface

```cpp
auto eth0_73 = network_config().get_by_name("eth0_73");
eth0_73.attached_to = nullptr; // this removes the interface
network_config().apply(eth0_73);
```

#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``

### read the state of a virtual interface

```cpp
auto eth0_73 = network_config().get_by_name("eth0_73");

```

#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``
### get macs from the bridge interface

```cpp

```
#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``
### add a multicast address

```cpp
```
#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``
### remove a multicast address

```cpp
```

#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``
### re-add a multicast  address

```cpp
```
#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``

### get the multicast address of the interface

```cpp
```
#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``
### add a brodcast address

```cpp
```
#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``

### remove a broadcast address
```cpp
```

#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``

### get the assigned broadcast address of the interface

```cpp
```
#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``

### set routes for the interface 

```cpp
```
#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``

### read routes assigned to the interface

```cpp
```
#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``

### read interface statistics

```cpp
```
#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``

### read interface arp table
```cpp
```
#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``
### Subsrcribe to interface changes
```cpp
```

#### req data

* rtnetlink message: ``
* operation: ``
* Required attrs:
    * ``:``
---

`get_by_name` & `get_by_index`: Synch operation, should not return until the netlink request has finished.