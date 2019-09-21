#ifndef _NETWORK_PROPERTY_
#define _NETWORK_PROPERTY_

#include <iostream>
#include <iterator>


#include "ip_types.h"

namespace netcfg {

template<class T>
class it_network_property : public std::iterator {
    it_network_property* it; // use smart ptr
    it_network_property& operator++{ it++, return *this};
    bool operator==(const it_network_property& rhs)const { return }
};

template<class T>
class network_property {
    network_property<T>& operator<<(string&);
    network_property<T>& operator>>(string&);
    string& get(void);
    uint8_t* get(void);
    string& get(void);
    string& get(void);
};

} /* namespace netcfg */
#endif /* _NETWORK_PROPERTY_ */