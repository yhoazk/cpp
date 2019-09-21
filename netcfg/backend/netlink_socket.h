#ifndef _NETLINK_SOCKET_
#define _NETLINK_SOCKET_

extern "C" {
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <linux/netlink.h>
}

#include <cerrno>
#include <cstdio>
#include <cstring>
#include <iostream>

namespace netlink {

    using socket_t = int;
    enum class socket_class {
        socket_route,
        socket_unused
    };
    
    enum class protocol {
        route = NETLINK_ROUTE,
    };

    class Isocket{
    public:
        virtual ~Isocket();
        virtual bool connect();
        virtual bool allocate();
        virtual bool _bind();
        // virtual bool request();
        // virtual bool receive();
    };

    //template<protocol P, socket_class T = socket_class::socket_route>
    class nl_socket {
    private:
        socket_t sfd{-1};
        bool binded{false};
    public:
        nl_socket(/* args */): sfd{-1}, binded{false} {};
        ~nl_socket();
        bool connect();
        bool allocate();
        bool _bind();
        void show();
        // send the netlink request
        // there is only one type of data for the request?
            // what types of requests should we support?
        // bool request() override;
        // bool receive() override;
    };

} /* namespace netlink */
#endif /* _NETLINK_SOCKET_ */
