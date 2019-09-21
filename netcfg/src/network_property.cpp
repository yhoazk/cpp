#include "network_property.h"
/*
    
 */

template<class T>
class network_property {
it_network_property* nps;
public:
    network_property<T>& operator<<(string&);
    network_property<T>& operator>>(string&);
    string& get(void);
    uint8_t* get(void);
    string& get(void);
    string& get(void);
};
